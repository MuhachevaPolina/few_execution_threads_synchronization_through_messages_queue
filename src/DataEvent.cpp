#include "DataEvent.h"

DataEvent::DataEvent(std::shared_ptr<Device> device) 
    : DeviceEvent(device) {}

std::string DataEvent::toString()
{
    this->m_data = this->m_device->getDataAsString();
    return this->m_data;
}