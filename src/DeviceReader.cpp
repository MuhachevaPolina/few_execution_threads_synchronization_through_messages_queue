#include "DeviceReader.h"
#include "StartedEvent.h"
#include "DataEvent.h"
#include "WorkDoneEvent.h"

DeviceReader::DeviceReader(std::shared_ptr<Device> device, std::shared_ptr<EventQueue> eventQueue)
  : m_device(device), m_eventQueue(eventQueue) {}

DeviceReader::~DeviceReader() 
{
  stop();
  join();
}

void DeviceReader::start() 
{
  if (this->m_running.load()) return;
    
  this->m_running.store(true);
  this->m_readerThread = std::thread(&DeviceReader::readingLoop, this);
}

void DeviceReader::stop() 
{
  this->m_running.store(false);
  if (this->m_device) 
  {
    this->m_device->stop();
  }
}

void DeviceReader::join() 
{
  if (this->m_readerThread.joinable()) 
  {
    this->m_readerThread.join();
  }
}

void DeviceReader::readingLoop() 
{
  try {
    this->m_eventQueue->push(std::make_shared<StartedEvent>(this->m_device));
        
    while (this->m_running.load() && this->m_device->isWorking()) 
    {
      bool success = this->m_device->read();
      
      if (success && this->m_running.load()) 
      {
        this->m_eventQueue->push(std::make_shared<DataEvent>(this->m_device));
      } else 
      {
        break;
      }
    }
        
    if (this->m_running.load()) 
    {
      this->m_eventQueue->push(std::make_shared<WorkDoneEvent>(this->m_device));
    }
        
    } catch (const std::exception& e) 
    {
      std::cerr << "Ошибка в потоке чтения " << this->m_device->getName() << ": " << e.what() << std::endl;
    }
}