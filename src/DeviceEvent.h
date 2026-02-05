#pragma once

#include "Event.h"
#include "Device.h"

#include <memory>

class DeviceEvent: public Event
{
public:
  DeviceEvent(std::shared_ptr<Device> device);
  std::shared_ptr<Device> DeviceEvent::getDevice() const;
protected:
  std::shared_ptr<Device> m_device;
  std::shared_ptr<DataStorage> m_data;
};