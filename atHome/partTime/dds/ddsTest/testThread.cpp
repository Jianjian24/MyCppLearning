#include <thread>
// #include "pch.h"
#include <iostream>
#include<thread>
#include<mutex>
using namespace std;

int g_data = 0;
mutex mtx;

void print1()
{
    cout << "print1_1 thread here" << endl;
    while (1)
    {
        // cout << "print1_1 thread exit" << endl;
        if (g_data == 6)
        {
            cout << "print1_1 thread exit" << endl;
            return;
        }
    //     /* code */
    mtx.lock();

    cout << "print1_2 thread here" << endl;
    cout << "print1_3 thread here" << endl;
    mtx.unlock();
    }
    
}
using namespace std;
int main()
{
    thread mythread1(print1);
    // mythread1.join();
    mythread1.detach();
    int op = 0;
    do
    {
    // mythread1.detach();
    cin >> g_data;
    // mtx.lock();
    cout << "main thread here:" << g_data << endl;//这里应该用锁将IO锁住，这句话完成之后再解锁
    // mtx.unlock();
        /* code */
    } while (g_data != 2);
    
    return 0;
}