#include "StartedEvent.h"

StartedEvent::StartedEvent(std::shared_ptr<Device> device): DeviceEvent(device) {}

std::string StartedEvent::toString() 
{
  this->m_data = "Started: Device " + this->m_device->getName() + " начал работу";
  return this->m_data;
}