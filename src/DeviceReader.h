#pragma once

#include "Device.h"
#include "EventQueue.h"

#include <memory>

class DeviceReader
{
public:
  DeviceReader(std::shared_ptr<Device> dev, std::shared_ptr<EventQueue> queue);
  void read(int deviceBrokenAfter);
private:
  void readingLoop(int deviceBrokenAfter);

  std::shared_ptr<Device> m_dev;
  std::shared_ptr<EventQueue> m_queue;
};