#pragma once

#include "Device.h"
#include "EventQueue.h"

class DeviceA: virtual public Device 
{
public:
  DeviceA(std::string name, EventQueue& queue): m_name(name), m_queue(queue);
  void readA();
  const std::string getDataAsString();
  const std::string getName(); 
private:
  const std::string m_name;
  const int* m_data;
  const EventQueue m_queue;
};