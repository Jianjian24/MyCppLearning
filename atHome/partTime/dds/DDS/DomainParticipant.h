#include ".\Entity.h"

class DomainParticipant : public Entity
{
private:

public:
    DomainParticipant();
    ~DomainParticipant();

    bool creat_publisher();     //创建一个Publisher对象
    bool creat_subscriber();    //创建一个subscribe对象
    bool creat_topic();         //创建一个topic对象

};
