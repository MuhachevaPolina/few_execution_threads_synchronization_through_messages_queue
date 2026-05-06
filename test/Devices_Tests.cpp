#include "../src/DeviceA.h"
#include "../src/DeviceB.h"

#include "utilities_Tests.h"

#include <gtest/gtest.h>
#include <string>

TEST(Devices, DeviceAGetName)
{
  DeviceA device;
  EXPECT_EQ(device.getName(), "DeviceA");
}

TEST(Devices, DeviceARead)
{
  DeviceA dev;
  dev.read();
  std::string res = dev.getDataAsString();
  EXPECT_FALSE(res.empty());
  EXPECT_LE(res.length(), 500);
  EXPECT_GE(res.length(), 1);
  EXPECT_EQ(res[0], 'a');
}

TEST(Devices, DeviceAIsWorking)
{
  DeviceA device;
  EXPECT_TRUE(device.isWorking());
}

TEST(Devices, DeviceBGetName)
{
  DeviceB device;
  EXPECT_EQ(device.getName(), "DeviceB");
}

TEST(Devices, DeviceBRead)
{
  DeviceB dev;
  dev.read();
  std::string resStr = dev.getDataAsString();
  EXPECT_FALSE(resStr.empty());
  std::vector<int> resInts = utilities::strToIntVector(resStr);
  EXPECT_EQ(resInts.size(), 3);
  EXPECT_TRUE(resInts[0] <= 198 &&  resInts[0] >= 0);
  EXPECT_TRUE(resInts[1] <= 198 &&  resInts[1] >= 0);
  EXPECT_TRUE(resInts[2] <= 198 &&  resInts[2] >= 0);
}

TEST(Devices, DeviceBIsWorking)
{
  DeviceB dev;
  EXPECT_TRUE(dev.isWorking());
}