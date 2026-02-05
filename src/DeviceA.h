#pragma once

#include "Device.h"

class DeviceA: public Device
{
public:
  DeviceA();

  std::string getName();
  std::string getDataAsString();
  void read();
  bool isWorking();
  void stop();
private:
  std::string generateString();

  std::string m_data;
};