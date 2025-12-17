#pragma once

#include "Device.h"
#include "EventQueue.h"

#include <memory>
#include <thread>
#include <atomic>

class DeviceReader
{
public:
  void start();
  void stop();
private:
  std::shared_ptr<Device> m_device; 
  std::shared_ptr<EventQueue> m_queue;
  std::atomic<bool> isRunning{false};
  std::thread readingThread;
};