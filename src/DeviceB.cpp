#include "DeviceB.h"
#include <iostream>

DeviceB::DeviceB(int failureAfter) : m_failureAfter(failureAfter) {}

std::string DeviceB::getName() const 
{
  return this->m_name;
}

std::string DeviceB::getDataAsString() const 
{
  return "[" + std::to_string(this->m_data1) + ", " + std::to_string(this->m_data2) + ", " + 
    std::to_string(this->m_data3) + "]";
}

bool DeviceB::read() 
{
  if (!this->m_working.load()) return false;
    
  int currentCount = ++this->m_readCount;
    
  if (this->m_failureAfter > 0 && currentCount >= this->m_failureAfter) 
  {
    this->m_working.store(false);
    std::cout << "DeviceB перестал работать после " << currentCount << " чтений\n";
    return false;
  }
    
  std::this_thread::sleep_for(std::chrono::seconds(5));
    
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 198);
    
  this->m_data1 = distrib(gen);
  this->m_data2 = distrib(gen);
  this->m_data3 = distrib(gen);
    
  return true;
}

bool DeviceB::isWorking() const 
{
  return this->m_working.load();
}

void DeviceB::stop() 
{
  this->m_working.store(false);
}