#include "WorkDoneEvent.h"

WorkDoneEvent::WorkDoneEvent(std::shared_ptr<Device> device): DeviceEvent(device) {}

std::string WorkDoneEvent::toString() const
{
  this->m_data->setData("WorkDone: Device " + m_device->getName() + " ended its work");
  return this->m_data->getData();
}