#include ".\Entity.h"
#include ".\DomainParticipant.h"

class DomainParticipant;

class DomainEntity : public Entity
{
private:
    
public:
    DomainEntity();
    ~DomainEntity();

    DomainParticipant*  create_participant();
};
