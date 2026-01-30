#include "DeviceA.h"

#include <cstdlib>

DeviceA::DeviceA(int failureAfter): m_failureAfter(failureAfter), 
m_name("DeviceA"), m_working(true), m_readCount(0) {}

DeviceA::DeviceA(): m_failureAfter(0), 
m_name("DeviceA"), m_working(true), m_readCount(0) {}

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