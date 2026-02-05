#include "WorkDoneEvent.h"

WorkDoneEvent::WorkDoneEvent(std::shared_ptr<Device> device): DeviceEvent(device) {}

std::string WorkDoneEvent::toString()
{
  this->m_data = "WorkDone: Device " + m_device->getName() + " завершил работу";
  return this->m_data;
}