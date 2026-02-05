#include "DeviceReader.h"

#include "DataEvent.h"
#include "StartedEvent.h"
#include "WorkDoneEvent.h"

#include <thread>
#include <iostream>

DeviceReader::DeviceReader(std::shared_ptr<Device> dev, std::shared_ptr<EventQueue> queue)
: m_dev(dev), m_queue(queue) {}

void DeviceReader::read(int deviceBrokenAfter)
{
  std::thread thr(&DeviceReader::readingLoop, this, deviceBrokenAfter);
}

void DeviceReader::readingLoop(int deviceBrokenAfter)
{
  std::shared_ptr<Event> startEv(new StartedEvent(this->m_dev));
  startEv->toString();
  this->m_queue->push(startEv);

  for (int i = 0; i < deviceBrokenAfter; i++)
  {
    std::shared_ptr<Event> dataEv(new DataEvent(this->m_dev));
    this->m_dev->read();
    dataEv->toString();
    this->m_queue->push(dataEv);
  }
}

