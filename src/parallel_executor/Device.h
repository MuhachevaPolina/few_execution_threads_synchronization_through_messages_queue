#pragma once

#include <string>

class Device
{
public:
  virtual const std::string getDataAsString() = 0; 
  virtual const std::string getName() = 0; 
};