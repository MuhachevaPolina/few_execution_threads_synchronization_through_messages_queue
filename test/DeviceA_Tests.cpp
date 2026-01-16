#include "../src/DeviceA.h"

#include <gtest/gtest.h>
#include <string>

TEST(DeviceA, GetName)
{
  DeviceA* device();
  EXPECT_EQ(device->getName(), "DeviceA");
}

TEST(DeviceA, RandomString)
{
  DeviceA* device();
  EXPECT_EQ(device->generateRandomString().length(), 500);
}