#pragma once

#include "Event.h"
#include "Device.h"

#include <memory>

class DeviceEvent: virtual public Event
{
public:
  DeviceEvent(std::shared_ptr<Device> device): m_device(device) {}
private:
  std::shared_ptr<Device> m_device;
};