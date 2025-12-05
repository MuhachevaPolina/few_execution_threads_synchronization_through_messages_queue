#pragma once

#include "Event.h"

class WorkDoneEvent: virtual public DeviceEvent
{
public:
  std::string toSting();
private:
  
};