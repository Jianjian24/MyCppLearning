#include "../../../jian.h"

class Base{
    public:
    int a;
    int b;
    virtual void sayD()
    {
        info(d);
    }
    private:
    int d = 100;
};

class Derived : public Base{
    public:
    void sayD()
    {
        // info(d);
    }
    int c;
    private:
    // using Base::d;
    int d = 99;
};

int main(){
    Base* dd = new Derived;
    // dd->a = 1;
    // dd->b = 2;
    // dd->c = 3;
    // dd->d = 4;

    // Base bb;
    // bb.a = 89;
    // bb.b = 189;

    // *(Base*)dd = bb;

    dd->sayD();

    return 0;
}