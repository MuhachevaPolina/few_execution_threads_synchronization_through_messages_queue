#include "DeviceReader.h"

#include "DataEvent.h"
#include "StartedEvent.h"
#include "WorkDoneEvent.h"

#include <thread>
#include <iostream>

DeviceReader::DeviceReader(std::shared_ptr<Device> dev, std::shared_ptr<EventQueue> queue, int deviceBrokenAfter)
: m_dev(dev), m_queue(queue), m_deviceBrokenAfter(deviceBrokenAfter) {}

void DeviceReader::read()
{
  std::thread thr([this]() {
    this->readingLoop();
  });
  thr.detach();
}

void DeviceReader::readingLoop()
{
  std::shared_ptr<const Event> startEv(new StartedEvent(this->m_dev));
  startEv->toString();
  this->m_queue->push(startEv);

  while(this->m_dev->getReadCount() < this->m_deviceBrokenAfter)
  {
    if(this->m_dev->getName() == "DeviceA")
    {
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    else if(this->m_dev->getName() == "DeviceB")
    {
      std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    std::shared_ptr<const Event> dataEv(new DataEvent(this->m_dev));
    this->m_dev->read();
    dataEv->toString();
    this->m_queue->push(dataEv);
  }

  this->m_dev->stop();
  std::shared_ptr<const Event> doneEv(new WorkDoneEvent(this->m_dev));
  doneEv->toString();
  this->m_queue->push(doneEv);
}
