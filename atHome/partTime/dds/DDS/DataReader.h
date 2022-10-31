#pragma once

#include ".\DataReaderListener.h"
#include <string>
using std::string;

class DataReader : public DataReaderListener
{
private:
    bool on_data_available(const char* buf) override;
    /* data */
public:
    DataReader(/* args */);
    ~DataReader();

    bool read(string topic);
};
