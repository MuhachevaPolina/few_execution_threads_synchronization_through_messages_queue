#pragma once

#include "DeviceEvent.h"

class WorkDoneEvent: virtual public DeviceEvent
{
public:
  WorkDoneEvent(std::shared_ptr<Device> device): m_device(device) {}
  virtual const std::string toSting() const;

private:
  std::shared_ptr<Device> m_device;
};