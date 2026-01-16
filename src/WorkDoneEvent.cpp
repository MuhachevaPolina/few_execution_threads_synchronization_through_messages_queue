#include "WorkDoneEvent.h"

WorkDoneEvent::WorkDoneEvent(std::shared_ptr<Device> device): DeviceEvent(device) {}

std::string WorkDoneEvent::toString() const 
{
  return "WorkDone: Device " + m_device->getName() + " завершил работу";
}