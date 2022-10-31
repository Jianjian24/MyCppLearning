#include ".\DataReaderListener.h"

class DataReader : public DataReaderListener
{
private:
    /* data */
public:
    DataReader(/* args */);
    ~DataReader();

    bool on_data_available();
    bool read();
};
