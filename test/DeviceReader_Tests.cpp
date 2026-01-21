#include "../src/EventQueue.h"
#include "../src/StartedEvent.h"
#include "../src/DeviceA.h"

#include <gtest/gtest.h>
#include <string>

TEST(DeviceReader, OneReadingForDeviceA)
{
  int deviceAFailAfter = 1;
  auto deviceA = std::make_shared<DeviceA>(deviceAFailAfter);
  auto eventQueue = std::make_shared<EventQueue>();        
  DeviceReader readerA(deviceA, eventQueue);
  readerA.start();
  deviceA->getDataAsString();
}