#pragma once

#include "Device.h"

class DeviceA: public Device
{
public:
  DeviceA(int failureAfter);
  DeviceA();

  std::string getName();
  std::string getDataAsString();
  bool read();
  bool isWorking();
  void stop();
private:
  std::string generateString();
};