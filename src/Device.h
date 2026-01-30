#pragma once

#include <string>

class Device
{
public:
    virtual std::string getName() = 0;
    virtual std::string getDataAsString() = 0;
    virtual bool read() = 0;
    virtual bool isWorking() = 0;
    virtual void stop() = 0;
};