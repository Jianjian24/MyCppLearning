// MultiThead.cpp : Defines the entry point for the console application.

#include <windows.h>
#include <iostream>

using namespace std;

#define INFINITY 99999

// 这边不知道为什么，下面main函数的函数调用
// 其 实现 必须在其调用之前 C 的语法
DWORD WINAPI Fun1Proc(LPVOID lpParameter);
// 线程1的入口函数
DWORD WINAPI Fun2Proc(LPVOID lpParameter);
//int index = 0;
int ticket = 100;
int countThread = 0;
HANDLE hmutex;

int main()
{
	HANDLE hThread1;
	HANDLE hThread2;

	// 创建互斥对象
	// 创建该互斥对象的线程若第二个参数为TRUE，则自动获得该对象的所有权
	// 此时参数为false，主线程不获得该对象
	hmutex = CreateMutex(nullptr, FALSE, TEXT("tickets"));
	// 使用WaitForSingleObject来请求后，先判断现在的线程与互斥对象所在的线程是不是一个
	// 若是，即使互斥对象处于未通知状态，仍然能获得该对象
	// 并且互斥对象内部维护的一个关于某个线程调用次数的计数器加一，在这个例子中该计数器为2
	// 所以下面得release两次其他线程才有机会获得该互斥对象
	//WaitForSingleObject(hmutex, INFINITY);
	if (hmutex)
	{
		if (ERROR_ALREADY_EXISTS == GetLastError())
		{
			cout << "only one instance can run! \n";
			getchar();
			return -1;
		}
	}


	// 创建线程
	hThread1 = CreateThread(nullptr, 0, Fun1Proc, nullptr, 0, nullptr);
	hThread2 = CreateThread(nullptr, 0, Fun2Proc, nullptr, 0, nullptr);
	CloseHandle(hThread1);// 关闭线程句柄
	CloseHandle(hThread2);
	//ReleaseMutex(hmutex);
	//ReleaseMutex(hmutex);
	//while (index++ < 1000)
	//cout << "main thread is running\n";
	//getchar();
	Sleep(1000);
	// getchar();
	cout << "countThread is :" << countThread;
	system("pause");
	return 0;
}

DWORD WINAPI Fun1Proc(LPVOID lpParameter)
{
	//while (index++ < 1000)
	//cout << "thread is running\n";
	char buf[100] = { 0 };// buffer : Storage location for output
	while (TRUE)
	{
		// 需要主动请求对象的使用权才有可能获得。。
		WaitForSingleObject(hmutex, INFINITY);// INFINITY undefind
		if (ticket > 0)
		{
			sprintf_s(buf, "thread1 sell ticket : %d \n", ticket);
			cout << buf;
			ticket--;
			countThread++;
		}
		else break;
		// 当线程对共享资源访问结束后，应释放该对象的所有权，也就是让该对象处于已通知状态
		ReleaseMutex(hmutex);
	}
	return 0;
}

DWORD WINAPI Fun2Proc(LPVOID lpParameter)
{
	char buf[100] = { 0 };
	while (TRUE)
	{
		WaitForSingleObject(hmutex, INFINITY); // 在vc中，应该使用的是INFINITE，导致最后在vc中的输出结果不理想
		if (ticket > 0)
		{
			sprintf_s(buf, "thread2 sell ticket :  %d \n", ticket);
			cout << buf;
			ticket--;
			countThread++;
		}
		else break;
		ReleaseMutex(hmutex);
	}
	return 0;
}