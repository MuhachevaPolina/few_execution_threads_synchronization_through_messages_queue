#pragma once

#include "Event.h"

class DataEvent: virtual public DeviceEvent
{
public:
  std::string toSting();
private:
  
};