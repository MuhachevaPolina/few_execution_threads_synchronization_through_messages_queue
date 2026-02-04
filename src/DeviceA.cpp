#include "DeviceA.h"

#include <cstdlib>

DeviceA::DeviceA(int failureAfter): Device(failureAfter, "DeviceA") {}

DeviceA::DeviceA(): Device(-1, "DeviceA") {} {}

std::string DeviceA::getName()
{
  return this->m_name;
}

std::string DeviceA::getDataAsString()
{
  return this->m_data;
}

bool DeviceA::isWorking()
{
  return this->m_working;
}

void DeviceA::stop()
{
  this->m_working = false;
}

bool DeviceA::read()
{
  this->m_data = this->generateString();
}

std::string DeviceA::generateString()
{
  int length = std::rand() % 501;

  std::string str(length, 'a');
  return str;
}