#include "DeviceA.h"

std::string DeviceA::getName()
{
  return this->m_name;
} 

std::string DeviceA::getDataAsString()
{
  std::string dataAsString;
  for (int i = 0; i < 3; ++I) 
    dataAsString.append(std::to_string(this->m_data));
  
  return dataAsString;
}
