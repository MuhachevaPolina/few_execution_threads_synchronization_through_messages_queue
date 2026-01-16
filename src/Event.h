#pragma once

#include <string>

class Event 
{
public:
  virtual std::string toString() const = 0;
  virtual ~Event() = default;
};