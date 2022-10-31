#include ".\Subscriber.h"

Subscriber::Subscriber(/* args */)
{
}

Subscriber::~Subscriber()
{
}

DataReader* Subscriber::create_dataReader()
{
    return new DataReader;
}