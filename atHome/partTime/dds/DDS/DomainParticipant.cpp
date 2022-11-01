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

Subscriber* DomainParticipant::creat_subscriber()
{
    return new Subscriber;
}

Topic* DomainParticipant::creat_topic()
{
    return new Topic;
}