#include "WorkDoneEvent.h"

WorkDoneEvent::WorkDoneEvent(std::shared_ptr<Device> device): DeviceEvent(device) {}

std::string WorkDoneEvent::toString()
{
  return "WorkDone: Device " + m_device->getName() + " завершил работу";
}