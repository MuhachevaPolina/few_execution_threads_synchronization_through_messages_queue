#include "src/DeviceReader.h"
#include "src/DeviceA.h"
#include "src/DeviceB.h"
#include "CLI/ConsoleLineInterface.h"

#include <iostream>
#include <memory>

int main()
{
  int deviceABrokenAfter = -1, deviceBBrokenAfter = -1;

  ConsoleLineInterface CLI;
  std::pair<int, int> devicesBrokenAfter = CLI.start();
  deviceABrokenAfter = devicesBrokenAfter.first;
  deviceBBrokenAfter = devicesBrokenAfter.second;

  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();

  std::shared_ptr<Device> devA(new DeviceA);
  std::shared_ptr<Device> devB(new DeviceB);

  if (deviceABrokenAfter == -1) 
  {
    deviceABrokenAfter = 100;
  }
  if (deviceBBrokenAfter == -1) 
  {
    deviceBBrokenAfter = 100;
  }

  std::shared_ptr<DeviceReader> readerA(new DeviceReader(devA, queue, deviceABrokenAfter));
  std::shared_ptr<DeviceReader> readerB(new DeviceReader(devB, queue, deviceBBrokenAfter));

  readerA->read();
  readerB->read();
  
  std::chrono::seconds dur = std::chrono::seconds(6);
  std::shared_ptr<const Event> ev;
  int evAmount = deviceABrokenAfter + deviceBBrokenAfter + 4;
  int evCounter = 0;

  while (evCounter < evAmount)
  {
    ev = queue->pop(dur);
    if (ev != nullptr)
    {
      std::cout << ev->toString() << std::endl;
      ++evCounter;
    }
    else
    {
      if (!devA->isWorking() && !devB->isWorking())
      {
        break;
      }
    }
  }

  return 0;
}