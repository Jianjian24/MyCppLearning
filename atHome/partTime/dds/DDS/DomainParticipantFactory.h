#pragma once

#include ".\DomainParticipant.h"

class DomainParticipantFactory
{
//单例模式 + 工厂模式
private:
    static DomainParticipantFactory* domainParticipantFactoryInstance;
    DomainParticipantFactory();
    ~DomainParticipantFactory();

public:
	static DomainParticipantFactory* getInstance() 
        {
		if(domainParticipantFactoryInstance == NULL) 
			domainParticipantFactoryInstance = new DomainParticipantFactory;
		return domainParticipantFactoryInstance;
	}
    DomainParticipant* create_participant();
};