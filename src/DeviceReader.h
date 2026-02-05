#pragma once

#include "Device.h"
#include "EventQueue.h"

#include <memory>

class DeviceReader
{
public:
  DeviceReader(std::shared_ptr<Device> dev, std::shared_ptr<EventQueue> queue, int deviceBrokenAfter);
  void read();
private:
  void readingLoop();

  std::shared_ptr<Device> m_dev;
  std::shared_ptr<EventQueue> m_queue;
  int m_deviceBrokenAfter;
};