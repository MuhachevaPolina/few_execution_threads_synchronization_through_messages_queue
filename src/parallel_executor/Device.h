#pragma once

#include <string>

class Device
{
public:
  virtual const std::string getDataAsString(); 
  virtual const std::string getName(); 
};