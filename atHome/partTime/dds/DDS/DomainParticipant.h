#ifndef __DOMAINPARTICIPANT_H__
#define __DOMAINPARTICIPANT_H__

#include ".\Entity.h"
#include ".\Publisher.h"
#include ".\Subscriber.h"
#include ".\Topic.h"

class Publisher;
class DomainParticipant : public Entity
{
private:

public:
    DomainParticipant();
    ~DomainParticipant();

    Publisher* creat_publisher();      //创建一个Publisher对象
    Subscriber* creat_subscriber();    //创建一个subscribe对象
    Topic* creat_topic();              //创建一个topic对象

};

#endif