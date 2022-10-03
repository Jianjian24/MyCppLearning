#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <windows.h>
#include <iostream>

//获取系统时间戳毫秒级
std::string GetTimeStamp(__int64& stampTime)
{
	struct tm *mytm;
	time_t t = time(NULL);
	long long time1 = (long long)t;
	std::cout << std::to_string(time1) << '\n';
	mytm =gmtime(&t);

	std::cout << mytm->tm_year + 1900 << " "  << mytm->tm_mon + 1 << '-' << mytm->tm_mday << ' ' << (mytm->tm_hour + 8) % 24 << ':' << mytm->tm_min << "\n";

	time_t curtime = time(NULL);
	long long time = (long long)curtime;
	stampTime = curtime;
	return std::to_string(time);
}

//时间戳转化为时间 毫秒级
std::string Stamp2Time(long long timestamp)
{
	int ms = timestamp % 1000;//取毫秒
	time_t tick = (time_t)(timestamp/1000);//转换时间
	struct tm tm;
	char s[40];
	tm = *localtime(&tick);
	strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", &tm);
	std::string str(s);
	str = str+ " " + std::to_string(ms);
	return str;
}

int main()
{
	__int64 stampTime = 0LL;
	unsigned int stampTime32 = 0;
	struct tm *mytm;
	time_t t = time(NULL);
	stampTime32 = (unsigned int)t;
	std::cout << "32:" << std::to_string(stampTime32) << '\n';
	std::cout << "\n" << GetTimeStamp(stampTime) << "\n";
	std::cout << "\n" << Stamp2Time(stampTime) << "\n";
	// SYSTEMTIME		stLocal, stUTC, stUTC2;
	// FILETIME		ftLocal, ftUTC, ft;
	// ULARGE_INTEGER	uli;

	// GetLocalTime(&stLocal);
	// GetSystemTime(&stUTC);
	// printf("Local System Time(YYYY-MM-DD HH:MM:SS): %d-%d-%d %d:%d:%d\n", stLocal.wYear, stLocal.wMonth,
	// 	stLocal.wDay, stLocal.wHour, stLocal.wMinute, stLocal.wSecond);
	// printf("UTC System Time  (YYYY-MM-DD HH:MM:SS): %d-%d-%d %d:%d:%d\n", stUTC.wYear, stUTC.wMonth,
	// 	stUTC.wDay, stUTC.wHour, stUTC.wMinute, stUTC.wSecond);

	// SystemTimeToFileTime(&stLocal, &ftLocal);
	// uli.LowPart = ftLocal.dwLowDateTime;
	// uli.HighPart = ftLocal.dwHighDateTime;
	// printf("Local File Time: %llu\n", uli.QuadPart);

	// LocalFileTimeToFileTime(&ftLocal, &ftUTC);
	// uli.LowPart = ftUTC.dwLowDateTime;
	// uli.HighPart = ftUTC.dwHighDateTime;
	// printf("UTC File Time: %llu\n", uli.QuadPart);

	// FileTimeToSystemTime(&ftUTC, &stUTC2);
	// printf("UTC System Time2 (YYYY-MM-DD HH:MM:SS): %d-%d-%d %d:%d:%d\n", stUTC2.wYear, stUTC2.wMonth,
	// 	stUTC2.wDay, stUTC2.wHour, stUTC2.wMinute, stUTC2.wSecond);


	return EXIT_SUCCESS;
}

// https://www.cnblogs.com/huangsitao/p/10283623.html
// https://blog.csdn.net/bokee/article/details/5330791
// https://blog.csdn.net/qq_36568418/article/details/105514586