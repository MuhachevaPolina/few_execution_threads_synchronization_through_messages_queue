#pragma once

#include "Device.h"
#include "EventQueue.h"

#include <memory>

class DeviceReader
{
public:
  void read(int deviceBrokenAfter);
private:
  void readingLoop(int deviceBrokenAfter);

  std::shared_ptr<Device> m_dev;
  std::shared_ptr<EventQueue> m_queue;
};