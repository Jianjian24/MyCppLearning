#include ".\Topic.h"
#include ".\Subscriber.h"
#include ".\Publisher.h"
#include ".\DomainParticipantFactory.h"
#include ".\DomainEntity.h"
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
        // DomainParticipant* domainPartcipant = DomainParticipantFactory::getInstance()->create_participant();
        char c;
        while ((c = getchar()) != '\n'); // clear buffer
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
    DomainEntity entity;
    DomainParticipant*  participant = entity.create_participant();

    Publisher* publisher = participant->creat_publisher();

    DataWriter* dataWriter = publisher->create_dataWriter();

    string topic;
    cout << "Please enter topic:" ;
    cin >> topic;
    dataWriter->write(topic);

    char c;
    while ((c = getchar()) != '\n'); // clear buffer
}

void DoSubscribe()
{
    DomainEntity entity;
    DomainParticipant*  participant = entity.create_participant();

    Subscriber* subscriber = participant->creat_subscriber();

    DataReader* reader = subscriber->create_dataReader();

    string topic;
    cout << "Please enter topic:" ;
    cin >> topic;
    reader->read(topic);

    char c;
    while ((c = getchar()) != '\n'); // clear buffer   
}