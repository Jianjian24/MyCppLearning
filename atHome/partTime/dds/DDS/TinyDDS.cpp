#include ".\Topic.h"
#include ".\Subscriber.h"
#include ".\Publisher.h"
#include ".\DomainParticipantFactory.h"
#include <iostream>
using namespace std;


void DoPublish();
void DoSubscribe();

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
        DomainParticipant* domainPartcipant = DomainParticipantFactory::create_participant();
        switch (option)
        {
            case 1:
                DoPublish();
                break;
            case 2:
                DoSubscribe();
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

void DoPublish()
{

}

void DoSubscribe()
{

}

