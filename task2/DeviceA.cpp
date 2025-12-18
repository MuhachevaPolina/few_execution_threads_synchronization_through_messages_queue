#include "DeviceA.h"
#include <iostream>

DeviceA::DeviceA(int failureAfter) : m_failureAfter(failureAfter) {}

std::string DeviceA::getName() const 
{
    return this->m_name;
}

std::string DeviceA::getDataAsString() const 
{
    return this->m_data;
}

std::string DeviceA::generateRandomString() 
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, sizeof(alphanum) - 2);
    std::uniform_int_distribution<> lenDistrib(0, 500);
    
    int length = lenDistrib(gen);
    std::string result;
    
    for (int i = 0; i < length; ++i) {
        result += alphanum[distrib(gen)];
    }
    
    return result;
}

bool DeviceA::read() {
    if (!this->m_working.load()) return false;
    
    int currentCount = ++this->m_readCount;
    
    if (this->m_failureAfter > 0 && currentCount >= this->m_failureAfter) {
        this->m_working.store(false);
        std::cout << "DeviceA перестал работать после " << currentCount << " чтений\n";
        return false;
    }
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
    this->m_data = generateRandomString();
    
    return true;
}

bool DeviceA::isWorking() const {
    return this->m_working.load();
}

void DeviceA::stop() {
    this->m_working.store(false);
}