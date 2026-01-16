#pragma once
#include "EventQueue.h"
#include "Device.h"

#include <memory>
#include <thread>
#include <atomic>
#include <iostream>

class DeviceReader 
{
public:
  DeviceReader(std::shared_ptr<Device> device, std::shared_ptr<EventQueue> eventQueue);
  ~DeviceReader();
    
  void start();
  void stop();
  void join();
    
  DeviceReader(const DeviceReader&) = delete;
  DeviceReader& operator=(const DeviceReader&) = delete;
  DeviceReader(DeviceReader&&) = default;
  DeviceReader& operator=(DeviceReader&&) = default;

private:
  std::shared_ptr<Device> m_device;
  std::shared_ptr<EventQueue> m_eventQueue;
  std::thread m_readerThread;
  std::atomic<bool> m_running{false};
    
  void readingLoop();
};