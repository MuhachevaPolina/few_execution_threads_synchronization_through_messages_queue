#include "DataEvent.h"

DataEvent::DataEvent(std::shared_ptr<Device> device) 
    : DeviceEvent(device) {}

std::string DataEvent::toString()
{
    return "Data from " + this->m_device->getName() + ": " + this->m_device->getDataAsString();
}