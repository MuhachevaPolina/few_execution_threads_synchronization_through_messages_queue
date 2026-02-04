#include "DeviceReader.h"

#include <thread>
#include <iostream>

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

