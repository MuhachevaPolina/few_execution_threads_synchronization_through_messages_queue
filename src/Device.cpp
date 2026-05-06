#include "Device.h"

Device::Device(std::string name): m_name(name)
{
  this->m_working = true;
  this->m_readCount = 0;
}
