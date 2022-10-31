#include ".\DomainParticipantFactory.h"

DomainParticipantFactory::DomainParticipantFactory()
{
}

DomainParticipantFactory::~DomainParticipantFactory()
{
}

DomainParticipant* DomainParticipantFactory::create_participant()
{
    // DomainParticipant *participant = ;
    return new DomainParticipant;
}