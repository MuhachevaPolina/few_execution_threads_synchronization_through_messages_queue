#pragma once

#include <string>
#include <atomic>

class Device
{
public:
  Device(int failureAfter, std::string name);

  virtual std::string getName() = 0;
  virtual std::string getDataAsString() = 0;
  virtual void read() = 0;
  virtual bool isWorking() = 0;
  virtual void stop() = 0;

protected:
  int m_failureAfter;
  std::string m_name;
  std::atomic<bool> m_working;
  std::atomic<int> m_readCount;
};