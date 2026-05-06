#include "../src/EventQueue.h"
#include "../src/StartedEvent.h"
#include "../src/WorkDoneEvent.h"
#include "../src/DeviceA.h"
#include "../src/DeviceB.h"

#include <gtest/gtest.h>
#include <string>
#include <memory>
#include <chrono>

TEST(EventQueueAndEvents, StartedEventValue)
{
  std::shared_ptr<Device> dev = std::make_shared<DeviceA>();
  std::shared_ptr<const Event> ev(new StartedEvent(dev));
  EXPECT_EQ(ev->toString(), "Started: Device " + dev->getName() + " started its work");
}

TEST(EventQueueAndEvents, WorkDoneEventValue)
{
  std::shared_ptr<Device> dev = std::make_shared<DeviceB>();
  std::shared_ptr<const Event> ev(new WorkDoneEvent(dev));
  EXPECT_EQ(ev->toString(), "WorkDone: Device " + dev->getName() + " ended its work");
}

TEST(EventQueueAndEvents, PushAndPop)
{
  EventQueue queue;
  std::shared_ptr<Device> dev = std::make_shared<DeviceA>();
  std::shared_ptr<const Event> ev(new StartedEvent(dev));
  queue.push(ev);
  std::chrono::seconds dur = std::chrono::seconds(6);
  std::shared_ptr<const Event> gottenEv = queue.pop(dur);
  EXPECT_EQ(gottenEv->toString(), "Started: Device " + dev->getName() + " started its work");
}

