#include "DataEvent.h"

DataEvent::DataEvent(std::shared_ptr<Device> device) 
    : DeviceEvent(device) {}

std::string DataEvent::toString() const 
{
    return "Data from " + m_device->getName() + ": " + m_device->getDataAsString();
}