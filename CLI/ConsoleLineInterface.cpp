#include "ConsoleLineInterface.h"

#include <iostream>

std::pair<int, int> ConsoleLineInterface::start()
{
  std::cout << "choose mode:\n";
  std::cout << "input '0' for deviceA and deviceB both work correctly\n";
  std::cout << "input '1' for deviceA is broken after N iterations and deviceB works correctly\n";
  std::cout << "input '2' for deviceA works correctly and deviceA is broken after M iterations\n";
  std::cout << "input '3' for deviceA is broken after N iterations and deviceB is broken after M iterations\n" << std::endl;
  
  int mode = -1;
  bool isWorking = false;
  int deviceABrokenAfter = -1, deviceBBrokenAfter = -1;

  while(!isWorking)
  {
  std::cin >> mode;
  switch(mode)
  {
  case 0:
    std::cout << "deviceA and deviceB both work correctly" << std::endl;
    isWorking = true;
    break;
  case 1:
    std::cout << "Input number of reading iterations for deviceA as a natural number" << std::endl;
    std::cin >> deviceABrokenAfter;
    isWorking = true;
    break;
  case 2:
    std::cout << "Input number of reading iterations for deviceB as a natural number" << std::endl;
    std::cin >> deviceBBrokenAfter;
    isWorking = true;
    break;
  case 3:
    std::cout << "Input number of reading iterations for deviceA and deviceB in format \n";
    std::cout << "'N M' where N and M are natural numbers (with space between them)" << std::endl;
    std::cin >> deviceABrokenAfter >> deviceBBrokenAfter;
    isWorking = true;
    break;
  default:
    std::cout << "wrong value! try again" << std::endl;
  }
  } 

  return std::pair<int, int>(deviceABrokenAfter, deviceBBrokenAfter);
}