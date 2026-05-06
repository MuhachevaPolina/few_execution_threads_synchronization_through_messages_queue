#include "StartedEvent.h"

StartedEvent::StartedEvent(std::shared_ptr<Device> device): DeviceEvent(device) {}

std::string StartedEvent::toString() const
{
  this->m_data->setData("Started: Device " + this->m_device->getName() + " started its work");
  return this->m_data->getData();
}