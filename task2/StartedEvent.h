#pragma once

#include "DeviceEvent.h"

class StartedEvent: public DeviceEvent
{
public:
  StartedEvent(std::shared_ptr<Device> device): DeviceEvent(device) {}
  std::string toString() const;
private:
  //std::shared_ptr<Device> m_device;
};