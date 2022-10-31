#include ".\Publisher.h"


Publisher::Publisher(/* args */)
{
}

Publisher::~Publisher()
{
}

DataWriter* Publisher::create_dataWriter()
{
    return new DataWriter;
}