#include "src/DeviceReader.h"
#include "src/DeviceA.h"
#include "src/DeviceB.h"

#include <iostream>
#include <memory>

int main()
{
  int deviceABrokenAfter = -1, deviceBBrokenAfter = -1;
  std::cin >> deviceABrokenAfter >> deviceBBrokenAfter;

  std::shared_ptr<EventQueue> queue;

  std::shared_ptr<Device> devA(new DeviceA);
  std::shared_ptr<Device> devB(new DeviceB);

  std::shared_ptr<DeviceReader> readerA(new DeviceReader(devA, queue, deviceABrokenAfter));
  std::shared_ptr<DeviceReader> readerB(new DeviceReader(devB, queue, deviceBBrokenAfter));

  readerA->read();
  readerB->read();

  std::chrono::seconds dur = std::chrono::seconds(5);
  std::shared_ptr<const Event> ev = queue->pop(dur);

  while (ev != nullptr)
  {
    ev = queue->pop(dur);
    std::cout << ev->toString() << std::endl;
  }

  return 0;
}