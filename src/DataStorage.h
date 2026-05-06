#pragma once

#include <string>

class DataStorage
{
public:
    DataStorage(): m_data("") {};
    void setData(std::string data);
    std::string getData();
private:
    std::string m_data;
};