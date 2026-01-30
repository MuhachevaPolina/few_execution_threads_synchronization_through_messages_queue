#include "StartedEvent.h"

StartedEvent::StartedEvent(std::shared_ptr<Device> device): DeviceEvent(device) {}

std::string StartedEvent::toString() 
{
  return "Started: Device " + this->m_device->getName() + " начал работу";
}