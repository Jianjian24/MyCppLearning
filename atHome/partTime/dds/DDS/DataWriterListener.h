#pragma once

class DataWriterListener
{
private:
    /* data */
public:
    // DataWriterListener(/* args */);
    // ~DataWriterListener();

    virtual bool on_data_write(const char* buf) = 0;
};
