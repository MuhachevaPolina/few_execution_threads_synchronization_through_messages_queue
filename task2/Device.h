#pragma once

#include <string>

class Device
{
public:
  //virtual Device() = default;
  virtual std::string getName() = 0;
  virtual std::string getDataAsString() = 0;
  virtual ~Device() = default;
};