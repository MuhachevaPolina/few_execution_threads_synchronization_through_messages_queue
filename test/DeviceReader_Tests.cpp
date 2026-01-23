#include "../src/EventQueue.h"
#include "../src/StartedEvent.h"
#include "../src/DeviceA.h"
#include "../src/DeviceB.h"
#include "../src/DeviceReader.h"

#include "utilities_Tests.h"

#include <gtest/gtest.h>
#include <string>
#include <iostream>

TEST(DeviceReader, OneReadingForDeviceA)
{
  int deviceAFailAfter = 1;
  auto deviceA = std::make_shared<DeviceA>(deviceAFailAfter);
  auto eventQueue = std::make_shared<EventQueue>();        
  DeviceReader readerA(deviceA, eventQueue);
  readerA.start();
  auto event = eventQueue->pop(std::chrono::seconds(1));
  std::string result = event->toString();
  std::cout << "result for A: " << result << std::endl;
  readerA.stop();

  EXPECT_LE(result.length(), 500);
  EXPECT_GT(result.length(), 0);
}

TEST(DeviceReader, OneReadingForDeviceB)
{
  int deviceBFailAfter = 1;
  auto deviceB = std::make_shared<DeviceB>(deviceBFailAfter);
  auto eventQueue = std::make_shared<EventQueue>();        
  DeviceReader readerB(deviceB, eventQueue);
  readerB.start();
  auto event = eventQueue->pop(std::chrono::seconds(10));

  std::string resInStr = event->toString();
  std::cout << "result for B: " << resInStr << std::endl;
  std::vector res = utilities::strToIntVector(resInStr);
  readerB.stop();

  EXPECT_FALSE(resInStr.empty());
}