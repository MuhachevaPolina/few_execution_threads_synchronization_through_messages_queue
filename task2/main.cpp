#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <string>

#include "EventQueue.h"
#include "DeviceA.h"
#include "DeviceB.h"
#include "DeviceReader.h"
#include "WorkDoneEvent.h"
#include "DataEvent.h"
#include "StartedEvent.h"

void printUsage() {
    std::cout << "Использование:\n";
    std::cout << "  ./prog [опции]\n";
    std::cout << "Опции:\n";
    std::cout << "  -a N    DeviceA ломается после N чтений (по умолчанию: никогда)\n";
    std::cout << "  -b N    DeviceB ломается после N чтений (по умолчанию: никогда)\n";
    std::cout << "  -h      Показать эту справку\n";
}

int main(int argc, char* argv[]) {
    int deviceAFailAfter = -1;
    int deviceBFailAfter = -1;
    
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-a" && i + 1 < argc) {
            deviceAFailAfter = std::stoi(argv[++i]);
        } else if (arg == "-b" && i + 1 < argc) {
            deviceBFailAfter = std::stoi(argv[++i]);
        } else if (arg == "-h") {
            printUsage();
            return 0;
        }
    }
    
    std::cout << "Запуск мониторинга устройств...\n";
    std::cout << "DeviceA сломается после " 
              << (deviceAFailAfter > 0 ? std::to_string(deviceAFailAfter) : "never") 
              << " чтений\n";
    std::cout << "DeviceB сломается после " 
              << (deviceBFailAfter > 0 ? std::to_string(deviceBFailAfter) : "never") 
              << " чтений\n";
    std::cout << std::endl;
    
    try {
        auto deviceA = std::make_shared<DeviceA>(deviceAFailAfter);
        auto deviceB = std::make_shared<DeviceB>(deviceBFailAfter);
        auto eventQueue = std::make_shared<EventQueue>();
        
        DeviceReader readerA(deviceA, eventQueue);
        DeviceReader readerB(deviceB, eventQueue);
        
        readerA.start();
        readerB.start();
        
        std::cout << "=== Начало обработки событий ===\n\n";
        
        bool deviceADone = false;
        bool deviceBDone = false;
        auto lastEventTime = std::chrono::steady_clock::now();
        
        while (!(deviceADone && deviceBDone)) {
            auto event = eventQueue->pop(std::chrono::seconds(5));
            
            if (event) {
                std::cout << event->toString() << std::endl;
                lastEventTime = std::chrono::steady_clock::now();
                
                auto workDoneEvent = std::dynamic_pointer_cast<WorkDoneEvent>(event);
                if (workDoneEvent) {
                    auto device = workDoneEvent->getDevice();
                    if (device->getName() == "DeviceA") {
                        deviceADone = true;
                        std::cout << ">>> DeviceA завершил работу\n";
                    } else if (device->getName() == "DeviceB") {
                        deviceBDone = true;
                        std::cout << ">>> DeviceB завершил работу\n";
                    }
                }
            } else {
                auto now = std::chrono::steady_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(
                    now - lastEventTime);
                
                if (elapsed.count() >= 5) {
                    std::cout << "\nВНИМАНИЕ: Нет событий в течение 5 секунд!\n";
                    
                    if (!deviceA->isWorking() && !deviceB->isWorking()) {
                        std::cout << "Оба устройства не работают. Завершение...\n";
                        break;
                    } else if (!deviceA->isWorking()) {
                        std::cout << "DeviceA не работает, продолжаем с DeviceB\n";
                        deviceADone = true;
                    } else if (!deviceB->isWorking()) {
                        std::cout << "DeviceB не работает, продолжаем с DeviceA\n";
                        deviceBDone = true;
                    }
                    
                    lastEventTime = now;
                }
            }
            
            if (deviceADone && !deviceBDone && !deviceB->isWorking()) {
                deviceBDone = true;
            }
            if (deviceBDone && !deviceADone && !deviceA->isWorking()) {
                deviceADone = true;
            }
        }
        
        readerA.stop();
        readerB.stop();
        eventQueue->stop();
        
        readerA.join();
        readerB.join();
        
        std::cout << "\n=== Приложение завершено ===\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}