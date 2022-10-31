#include ".\DataWriter.h"

class Publisher
{
private:
    /* data */
public:
    Publisher(/* args */);
    ~Publisher();

    DataWriter* create_dataWriter();
};