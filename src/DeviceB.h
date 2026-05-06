#pragma once

#include "Device.h"

#include <atomic>

class DeviceB: public Device
{
public:
  DeviceB();
    
  std::string getName();
  std::string getDataAsString();
  void read();
  bool isWorking();
  void stop();
  int getReadCount();
private:
  int m_data1, m_data2, m_data3;
};