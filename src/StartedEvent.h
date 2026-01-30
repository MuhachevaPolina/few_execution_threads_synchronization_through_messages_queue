#pragma once 

#include "DeviceEvent.h"

class StartedEvent: public DeviceEvent
{
public:
    StartedEvent(std::shared_ptr<Device> device);
    std::string toString();
};