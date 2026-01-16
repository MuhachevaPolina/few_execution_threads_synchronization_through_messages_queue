#pragma once

#include "Device.h"

#include <atomic>
#include <random>
#include <chrono>
#include <thread>

class DeviceA : public Device 
{
  public:
      DeviceA(int failureAfter = -1);
      std::string getName() const override;
      std::string getDataAsString() const override;
      bool read() override;
      bool isWorking() const override;
      void stop() override;
      std::string generateRandomString();

  private:
      std::string m_name = "DeviceA";
      std::string m_data;
      std::atomic<bool> m_working{true};
      std::atomic<int> m_readCount{0};
      int m_failureAfter;
  };