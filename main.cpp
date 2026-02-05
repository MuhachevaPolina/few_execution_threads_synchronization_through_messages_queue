#include "src/DeviceReader.h"
#include "src/DeviceA.h"
#include "src/DeviceB.h"

#include <iostream>
#include <memory>

int main()
{
  int deviceABrokenAfter = -1, deviceBBrokenAfter = -1;
  std::cin >> deviceABrokenAfter >> deviceBBrokenAfter;

  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();

  std::shared_ptr<Device> devA(new DeviceA);
  std::shared_ptr<Device> devB(new DeviceB);

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