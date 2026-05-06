#include "DataEvent.h"

DataEvent::DataEvent(std::shared_ptr<Device> device) 
    : DeviceEvent(device) {}

std::string DataEvent::toString() const
{
    this->m_data->setData(this->m_device->getDataAsString());
    return this->m_data->getData();
}