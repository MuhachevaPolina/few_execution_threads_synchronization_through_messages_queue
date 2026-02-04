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

  std::shared_ptr<Device> devA{new DeviceA};
  std::shared_ptr<Device> devB{new DeviceB};

  std::shared_ptr<DeviceReader> readerA{DeviceA, queue};
  std::shared_ptr<DeviceReader> readerB{DeviceB, queue};

  return 0;
}