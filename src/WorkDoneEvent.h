#pragma once 

#include "DeviceEvent.h"

class WorkDoneEvent: public DeviceEvent
{
public:
  WorkDoneEvent(std::shared_ptr<Device> device);
  std::string toString() const;
};