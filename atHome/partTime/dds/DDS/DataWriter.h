#include ".\DataWriterListener.h"

class DataWriter : public DataWriterListener
{
private:
    /* data */
public:
    DataWriter(/* args */);
    ~DataWriter();

    bool write();
};
