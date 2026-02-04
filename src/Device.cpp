#include "Device.h"

Device::Device(int failureAfter, std::string name)
: m_failureAfter(failureAfter), m_name(name)
{
  this->m_working = true;
  this->m_readCount = 0;
}
