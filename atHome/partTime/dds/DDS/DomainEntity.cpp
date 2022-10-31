#include ".\DomainEntity.h"
#include ".\DomainParticipantFactory.h"

class DomainParticipantFactory;
DomainEntity::DomainEntity()
{
}

DomainEntity::~DomainEntity()
{
}

DomainParticipant*  DomainEntity::create_participant()
{
    DomainParticipant* domainPartcipant = DomainParticipantFactory::getInstance()->create_participant();
    return domainPartcipant;
}