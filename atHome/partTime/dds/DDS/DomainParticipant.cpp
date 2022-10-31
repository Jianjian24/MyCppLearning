#include ".\DomainParticipant.h"

DomainParticipant::DomainParticipant()
{
}

DomainParticipant::~DomainParticipant()
{
}

Publisher* DomainParticipant::creat_publisher()
{
    return new Publisher;
}