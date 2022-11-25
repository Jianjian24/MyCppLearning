#include <iostream>
#include <stdio.h>
using namespace std;

class AC
{
public:  
    AC()
    {
        // say();
    }
    void doSomething()
    {
        say();
    }
    virtual void say() = 0;
    int getData() {return m_data;}
    virtual void testPure() = 0;
protected:
    int m_data = 0;
};

class son : public AC
{
public :
    son()
    {

    }
    void say()
    {
        cout << "son\n";
        m_data = 100;
    }
    virtual void testPure()
    {
        cout << "testPure\n";
    }
};

class TestAddr
{
    public:
    TestAddr(){}
    void say()
    {
        printf("TestAdr is %x\n", this);
    }
};

int main()
{
    AC *a = new son;
    // son b;
    cout << a->getData() << '\n';
    a->doSomething();
    cout << a->getData() << '\n';
    delete a;

    TestAddr addr;
    addr.say();
    printf("init TestAdr is %x\n", &addr);
    
}

