#include <iostream>

using namespace std;


// A interface
// B->A 
// C->B
// in C  A*
// see what happened


class A
{
public:
    virtual void saySomething() = 0;
};

class B : public A
{
public:
    virtual void saySomething()
    {
        cout << "in B Hello \n";
    }
};

class C : public B
{
public:
    C()
    {
        m_Ba = new B;
    }

    ~C()
    {
        delete m_Ba;
    }
public:
    A *m_Ba;
    void saySomething(){ cout << "In c hello \n";}

    void doSomething()
    {
        m_Ba->saySomething();
    }

};

int main()
{   
    
    C mainC;
    C* cc = new C;
    cc->saySomething();
    cc->doSomething();

    // mainC.doSomething();
    // getchar();
    return 0;
}
