#pragma once

#include <string>
#include <utility>

class ConsoleLineInterface
{
public:
  ConsoleLineInterface() {};
  std::pair<int, int> start();
};
