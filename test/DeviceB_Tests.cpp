#include "../src/DeviceB.h"

#include <gtest/gtest.h>
#include <string>

TEST(DeviceB, GetName)
{
  DeviceB device;
  EXPECT_EQ(device.getName(), "DeviceB");
}

TEST(DeviceB, RandomNumber)
{
  DeviceB device;
  device.read();
  std::string result = device.getDataAsString();
  EXPECT_TRUE(result.length() >= 9 && result.length() <= 15);
}

TEST(DeviceB, IsWorking)
{
  DeviceB device;
  EXPECT_TRUE(device.isWorking());
}