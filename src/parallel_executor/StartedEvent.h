#pragma once

#include "Event.h"

class StartedEvent: virtual public DeviceEvent
{
public:
  std::string toSting();
private:
  
};