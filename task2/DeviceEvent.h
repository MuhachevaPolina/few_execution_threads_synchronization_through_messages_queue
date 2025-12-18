#pragma once

#include "Event.h"
#include "Device.h"

#include <memory>

class DeviceEvent: public Event 
{
public:
  DeviceEvent(std::shared_ptr<Device> device): m_device(device) {}
  std::shared_ptr<Device> getDevice() const;

  virtual ~DeviceEvent() = default;
protected:
  std::shared_ptr<Device> m_device;
};