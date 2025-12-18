#pragma once
#include "Device.h"
#include <atomic>
#include <random>
#include <chrono>
#include <thread>

class DeviceB : public Device {
  public:
    DeviceB(int failureAfter = -1);
    std::string getName() const override;
    std::string getDataAsString() const override;
    bool read() override;
    bool isWorking() const override;
    void stop() override;

private:
    std::string m_name = "DeviceB";
    int m_data1, m_data2, m_data3;
    std::atomic<bool> m_working{true};
    std::atomic<int> m_readCount{0};
    int m_failureAfter;
};