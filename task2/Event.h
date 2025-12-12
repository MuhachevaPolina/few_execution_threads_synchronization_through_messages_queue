#pragma once

#include <string>

class Event 
{
public:
  //virtual Event() = default;
  virtual std::string toString() const = 0;
  virtual ~Event() = default;
};