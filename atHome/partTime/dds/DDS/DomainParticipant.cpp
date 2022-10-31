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

Subscriber* creat_subscriber()
{
    return new Subscriber;
}

Topic* creat_topic()
{
    return new Topic;
}