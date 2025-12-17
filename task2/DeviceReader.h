#pragma once

#include "Device.h"
#include "EventQueue.h"

#include <memory>
#include <thread>
#include <atomic>

class DeviceReader
{
public:
  DeviceReader(std::shared_ptr<Device> device,std::shared_ptr<EventQueue> m_queue,
  std::thread readingThread): m_device(device), m_queue(queue), m_readingThread(readingThread){}
  
  void start();
  void stop();
private:
  std::shared_ptr<Device> m_device; 
  std::shared_ptr<EventQueue> m_queue;
  std::atomic<bool> isRunning{false};
  std::thread m_readingThread;

  void readingProcess();
};