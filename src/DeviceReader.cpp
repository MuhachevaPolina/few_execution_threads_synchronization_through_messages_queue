#include "DeviceReader.h"

#include <thread>
#include <iostream>

DeviceReader::DeviceReader(std::shared_ptr<Device> dev, std::shared_ptr<EventQueue> queue)
: m_dev(dev), m_queue(queue) {}

void DeviceReader::read(int deviceBrokenAfter)
{
  std::thread thr{this->readingLoop};
}

void DeviceReader::readingLoop(int deviceBrokenAfter)
{
  for (int i = 0; i < deviceBrokenAfter; i++)
  {
    this->m_dev->read();
    std::string data = this->m_dev->getDataAsString();
    this->m_queue->push(data);
  }
}

