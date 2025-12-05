#pragma once

#include "DeviceEvent.h"

class WorkDoneEvent: virtual public DeviceEvent
{
public:
  WorkDoneEvent();
  virtual const std::string toSting() const;
};