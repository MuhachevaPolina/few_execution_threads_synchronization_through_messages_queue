#include "DeviceB.h"

#include <cstdlib>

DeviceB::DeviceB(): Device("DeviceB"), m_data1(0), m_data2(0), m_data3(0) {} 

std::string DeviceB::getName()
{
  return this->m_name;
}

std::string DeviceB::getDataAsString()
{
 return std::to_string(this->m_data1) + ", " + std::to_string(this->m_data2) + ", " + std::to_string(this->m_data3);
}

bool DeviceB::isWorking()
{
  return this->m_working;
}

void DeviceB::stop()
{
  this->m_working = false;
}

void DeviceB::read()
{
  this->m_data1 = std::rand() % 199;
  this->m_data2 = std::rand() % 199;
  this->m_data3 = std::rand() % 199;
}