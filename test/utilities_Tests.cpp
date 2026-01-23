#include "utilities_Tests.h"

#include <string>
#include <vector>

  std::vector<int> utilities::strToIntVector(std::string str)
  {
    std::vector<int> res;
    std::vector<int> empty;
    int digCounter = 0;
    std::string numInStr = "";

    for (int i = 0; i < str.length(); i++)
    {
      if (str[i] >= '0' && str[i] <= '9')
      {
        digCounter++;
        numInStr += str[i];
      }
      else if (str[i] != ']' && str[i] != '[' && str[i] != ' ' && str[i] != ',' && str[i] != '\0')
      {
        return empty;
      }
      else if (digCounter != 0)
      {
        res.push_back(std::stoi(numInStr));
        digCounter = 0;
        numInStr.clear();
      }
    }

    return res;
  }
