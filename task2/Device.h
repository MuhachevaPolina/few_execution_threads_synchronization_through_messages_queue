#pragma once

#include <string>
#include <memory>

class Device 
{
public:
    virtual ~Device() = default;
    virtual std::string getName() const = 0;
    virtual std::string getDataAsString() const = 0;
    virtual bool read() = 0;
    virtual bool isWorking() const = 0;
    virtual void stop() = 0;
};