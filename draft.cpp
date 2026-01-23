#include "test/utilities_Tests.h"
#include <iostream>

int main()
{
  std::string str = "[11, 2011, 5, 90001]";
  std::vector<int> res = utilities::strToIntVector(str);
  for (auto elem: res)
  {
    std::cout << elem << std::endl;
  }
  return 0;
}