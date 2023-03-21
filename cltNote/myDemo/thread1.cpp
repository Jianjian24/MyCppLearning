#include <iostream>
#include <string>
#include <thread>
#include <mutex>
std::mutex mt;
using namespace std;

void print(const char* s)
{
    mt.lock();
    while (*s != '\0')
    {
        cout << *s;
        s++;
        // this_thread::sleep_for(chrono::milliseconds(100));
    }
    mt.unlock();

}

void fun1()
{
    const char* s1 = "hello";
    print(s1);
}

void fun2()
{
    const char* s2 = "world";
    print(s2);
}

int main()
{
    thread t1(fun1);
    thread t2(fun2);

    t2.join();
    t1.join();
    return 0;
}
