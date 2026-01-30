#pragma once

#include "Device.h"

#include <atomic>

class DeviceA: public Device
{
public:
    DeviceA(int failureAfter);
    DeviceA();

    std::string getName();
    std::string getDataAsString();
    bool read();
    bool isWorking();
    void stop();
private:
    std::string generateString();

    std::string m_name;
    std::string m_data;
    std::atomic<bool> m_working;
    std::atomic<int> m_readCount;
    int m_failureAfter;
};