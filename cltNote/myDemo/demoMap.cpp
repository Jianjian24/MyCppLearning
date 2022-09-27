#include "iostream"
#include "map"
using namespace std;

map<int, void*> myMap;

typedef struct t1
{
    double a;
    int b;
}T1;

typedef struct t2
{
    int a;
    double b;
}T2;

void fun1()
{
    cout << "This is fun1()\n";
    T1 * t = new T1;
    t->a = 1;
    t->b = 1009;
    pair<int, void*> p(1, (void*)t);

    myMap.insert(p);
}

void fun2()
{
    cout << "This is fun2()\n";
    T2 * t = new T2;
    t->a = 89;
    pair<int, void*> p(2, (void*)t);

    myMap.insert(p);
}


int main()
{
    fun1();
    fun2();

    int count = 0;  
    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) 
    {	
        if (count == 0)
        {
            cout << iter->first << "  " << ((T2*)(iter->second))->a << endl;
            ++count;
            continue;
        }
        if (count == 1)
        {
            cout << iter->first << "  " << ((T1*)(iter->second))->b << endl;
            ++count;
        }			
        
    }

    return 0;
}