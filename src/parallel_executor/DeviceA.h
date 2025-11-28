#pragma once

#include "Device.h"

class DeviceA: virtual public Device 
{
public:
  std::string getDataAsString();
  const std::string getName(); 
private:
  const std::string m_name;
  int* m_data;
};