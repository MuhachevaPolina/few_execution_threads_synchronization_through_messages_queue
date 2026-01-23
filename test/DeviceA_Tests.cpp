#include "../src/DeviceA.h"

#include <gtest/gtest.h>
#include <string>

TEST(DeviceA, GetName)
{
  DeviceA device;
  EXPECT_EQ(device.getName(), "DeviceA");
}

TEST(DeviceA, RandomString)
{
  DeviceA device;
  EXPECT_LE(device.generateRandomString().length(), 500);
  EXPECT_GT(device.generateRandomString().length(), 0);
}

TEST(DeviceA, IsWorking)
{
  DeviceA device;
  EXPECT_TRUE(device.isWorking());
}