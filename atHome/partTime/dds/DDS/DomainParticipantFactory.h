#include ".\DomainParticipant.h"

class DomainParticipant;

class DomainParticipantFactory
{
private:
    // static DomainParticipantFactory* domainParticipantFactoryInstance;
    /* data */

public:
    DomainParticipantFactory(/* args */);
    ~DomainParticipantFactory();
	// static DomainParticipantFactory* getInstance() 
    //     {
	// 	if(domainParticipantFactoryInstance == NULL) 
	// 		domainParticipantFactoryInstance = new DomainParticipantFactory();
	// 	return instance;
	// }
    static DomainParticipant* create_participant();
};

// DomainParticipantFactory* DomainParticipantFactory::domainParticipantFactoryInstance = nullptr;