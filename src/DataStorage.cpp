#include "DataStorage.h"

void DataStorage::setData(std::string data)
{
    if(this->m_data == "")
    {
        this->m_data = data;
    }
}

std::string DataStorage::getData()
{
    return this->m_data;
}