#include "DeviceA.h"

const std::string DeviceA::getName()
{
  return this->m_name;
} 

const std::string DeviceA::getDataAsString()
{
  const std::string dataAsString;
  for (int i = 0; i < 3; ++i)
    dataAsString.append(std::to_string(this->m_data[i]));

  return dataAsString;
}
