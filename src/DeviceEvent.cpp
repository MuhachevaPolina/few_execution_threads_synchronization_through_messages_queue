#include "DeviceEvent.h"

DeviceEvent::DeviceEvent(std::shared_ptr<Device> device): m_device(device) {}

std::shared_ptr<Device> DeviceEvent::getDevice() const 
{
  return this->m_device;
}