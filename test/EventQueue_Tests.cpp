#include "../src/EventQueue.h"
#include "../src/StartedEvent.h"
#include "../src/DeviceA.h"

#include <gtest/gtest.h>
#include <string>

TEST(EventQueue, isEmptyTrue)
{
  EventQueue queue;
  EXPECT_TRUE(queue.empty());
}

TEST(EventQueue, isEmptyFalse)
{
  EventQueue queue;
  auto dev = std::make_shared<DeviceA>();
  auto ev = StartedEvent(dev);
  queue.push(std::make_shared<StartedEvent>(ev));
  EXPECT_FALSE(queue.empty());
}