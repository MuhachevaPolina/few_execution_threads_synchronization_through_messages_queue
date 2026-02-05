#pragma once

#include <string>
#include <atomic>

class Device
{
public:
  Device(std::string name);

  virtual std::string getName() = 0;
  virtual std::string getDataAsString() = 0;
  virtual void read() = 0;
  virtual bool isWorking() = 0;
  virtual void stop() = 0;

protected:
  std::string m_name;
  std::atomic<bool> m_working;
  std::atomic<int> m_readCount;
};