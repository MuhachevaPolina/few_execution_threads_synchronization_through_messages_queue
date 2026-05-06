#include "DeviceEvent.h"

DeviceEvent::DeviceEvent(std::shared_ptr<Device> device): m_device(device) 
{
  this->m_data = std::make_shared<DataStorage>();
}

std::shared_ptr<Device> DeviceEvent::getDevice() const 
{
  return this->m_device;
}