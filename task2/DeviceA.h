#pragma once

#include "Device.h"

#include <string>

class DeviceA: public Device
{
public:
  std::string getName();
  std::string getDataAsString();
};