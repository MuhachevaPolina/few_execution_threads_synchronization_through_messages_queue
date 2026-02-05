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
private:
  std::string m_name;
  int m_data1, m_data2, m_data3;
  std::atomic<bool> m_working;
  std::atomic<int> m_readCount;
  int m_failureAfter;
};