#pragma once

#include "Device.h"

class DeviceB: virtual public Device
{
public:
  DeviceB() {}
  const std::string getDataAsString();
  const std::string getName(); 
private:
  const std::string m_name;
  std::string m_data;
  const EventQueue m_queue;
};