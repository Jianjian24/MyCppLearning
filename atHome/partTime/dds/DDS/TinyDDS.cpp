#include ".\Topic.h"
#include ".\Subscriber.h"
#include ".\Publisher.h"
#include ".\DomainParticipantFactory.h"
// #include ".\DomainEntity.h"
#include <iostream>
using namespace std;


void DoPublish(DomainParticipant* domainPartcipant);
void DoSubscribe(DomainParticipant* domainPartcipant);

int main()
{
    int option = 0;
    cout << "Welcome to TinyDDS!\n";
    do
    {
        cout << "\nTinyDDS Menu:" << endl;
        cout << "\t1. Publish Topic\n\t2. Subscribe Topic\n\t3. exit" << endl;
        cout << "Enter your option: ";
        cin >> option;
        DomainParticipant* domainPartcipant = DomainParticipantFactory::getInstance()->create_participant();
        char c;
        while ((c = getchar()) != '\n'); // clear buffer
        switch (option)
        {
            case 1:
                DoPublish(domainPartcipant);
                break;
            case 2:
                DoSubscribe(domainPartcipant);
                break;
            case 3:
                exit(0);
                break;
            default:
                break;
        }

    }while(option != 3);
    
    return 0;
}

void DoPublish(DomainParticipant* domainPartcipant)
{

}

void DoSubscribe(DomainParticipant* domainPartcipant)
{

}

