#include "../src/EventQueue.h"
#include "../src/StartedEvent.h"
#include "../src/WorkDoneEvent.h"
#include "../src/DataEvent.h"
#include "../src/DeviceA.h"
#include "../src/DeviceB.h"
#include "../src/DeviceReader.h"

#include "utilities_Tests.h"

#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <cctype>

TEST(DeviceReader, OneReadingForDeviceA)
{
  int deviceABrokenAfter = 1;

  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();

  std::shared_ptr<Device> devA(new DeviceA);

  std::shared_ptr<DeviceReader> readerA(new DeviceReader(devA, queue, deviceABrokenAfter));

  readerA->read();

  std::chrono::seconds dur = std::chrono::seconds(6);
  int evAmount = deviceABrokenAfter + 2;
  int evCounter = 0;

  std::shared_ptr<const Event> ev = queue->pop(dur);
  EXPECT_EQ(ev->toString(), "Started: Device " + devA->getName() + " started its work");
  ev = queue->pop(dur);
  EXPECT_EQ(ev->toString()[0], 'a');
  ev = queue->pop(dur);
  EXPECT_EQ(ev->toString(), "WorkDone: Device " + devA->getName() + " ended its work");
}

TEST(DeviceReader, OneReadingForDeviceB)
{
  int deviceBBrokenAfter = 1;

  std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();

  std::shared_ptr<Device> devB(new DeviceB);

  std::shared_ptr<DeviceReader> readerB(new DeviceReader(devB, queue, deviceBBrokenAfter));

  readerB->read();

  std::chrono::seconds dur = std::chrono::seconds(6);
  int evAmount = deviceBBrokenAfter + 2;
  int evCounter = 0;

  std::shared_ptr<const Event> ev = queue->pop(dur);
  EXPECT_EQ(ev->toString(), "Started: Device " + devB->getName() + " started its work");
  ev = queue->pop(dur);
  std::vector<int> resInts = utilities::strToIntVector(ev->toString());
  EXPECT_EQ(resInts.size(), 3);
  EXPECT_TRUE(resInts[0] <= 198 &&  resInts[0] >= 0);
  EXPECT_TRUE(resInts[1] <= 198 &&  resInts[1] >= 0);
  EXPECT_TRUE(resInts[2] <= 198 &&  resInts[2] >= 0);
  ev = queue->pop(dur);
  EXPECT_EQ(ev->toString(), "WorkDone: Device " + devB->getName() + " ended its work");
}

TEST(DeviceReader, BothDevicesFewReadings)
{
  int deviceABrokenAfter = 4, deviceBBrokenAfter = 2;

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
      std::string resStr = ev->toString();
      EXPECT_TRUE(resStr.find("WorkDone:") != -1 || resStr.find("Started:") != -1
                  || resStr[0] == 'a' || resStr[0] == '[');
      if (resStr.find("WorkDone:") != -1)
      {
        EXPECT_FALSE(resStr.find("Device") == -1);
        EXPECT_FALSE(resStr.find("ended its work") == -1);
      }
      else if (resStr.find("Started:") != -1)
      {
        EXPECT_FALSE(resStr.find("Device") == -1);
        EXPECT_FALSE(resStr.find("started its work") == -1);
      }
      else
      {
        if (resStr[0] == 'a')
        {
          EXPECT_TRUE(resStr.length() >= 1 && resStr.length() <=500);
        }
        else if (resStr[0] == '[')
        {
          EXPECT_TRUE(std::isdigit(resStr[1]));
        }
      }
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
}