#include <Windows.h>
#include <iostream>
using namespace std;
 
HANDLE gEvent;
DWORD WINAPI Fuc1(LPVOID lpParam);
DWORD WINAPI Fuc2(LPVOID lpParam);
 
int tick = 0;
 
DWORD __stdcall Fuc1(LPVOID lpParam)
{
    WaitForSingleObject(gEvent, INFINITE);//请求事件对象
    ResetEvent(gEvent);//重置事件为无信号状态
    tick += 50;
    cout << "func1 ====> " << tick << endl;
    for (size_t i = 0; i < 10; i++)
    {
        cout <<"f1:" << i << endl;
    }
    // SetEvent(gEvent);//设置为有信号状态
    return 0;
}
 
DWORD __stdcall Fuc2(LPVOID lpParam)
{
    WaitForSingleObject(gEvent, 10000);//请求事件对象
    ResetEvent(gEvent);//重置事件为无信号状态
    tick += 50;
    cout << "func2 ====> " << tick << endl;
    for (size_t i = 0; i < 10; i++)
    {
        cout <<"f2:" << i << endl;
    }
    SetEvent(gEvent);//设置为有信号状态
    return 0;
}
 
int main()
{
    gEvent = CreateEvent(NULL, FALSE, false, NULL);
    if (gEvent)
    {
        SetEvent(gEvent);
    }
    
    HANDLE t1, t2;
    t1 = CreateThread(NULL, 0, Fuc1, NULL, 0, NULL);
    t2 = CreateThread(NULL, 0, Fuc2, NULL, 0, NULL);
    while (true)
    {
 
    }
    CloseHandle(t1);
    CloseHandle(t2);
    return 0;
}