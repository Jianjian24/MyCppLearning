#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>


int main()
{
	SYSTEMTIME		stLocal, stUTC, stUTC2;
	FILETIME		ftLocal, ftUTC, ft;
	ULARGE_INTEGER	uli;

	GetLocalTime(&stLocal);
	GetSystemTime(&stUTC);
	printf("Local System Time(YYYY-MM-DD HH:MM:SS): %d-%d-%d %d:%d:%d\n", stLocal.wYear, stLocal.wMonth,
		stLocal.wDay, stLocal.wHour, stLocal.wMinute, stLocal.wSecond);
	printf("UTC System Time  (YYYY-MM-DD HH:MM:SS): %d-%d-%d %d:%d:%d\n", stUTC.wYear, stUTC.wMonth,
		stUTC.wDay, stUTC.wHour, stUTC.wMinute, stUTC.wSecond);

	SystemTimeToFileTime(&stLocal, &ftLocal);
	uli.LowPart = ftLocal.dwLowDateTime;
	uli.HighPart = ftLocal.dwHighDateTime;
	printf("Local File Time: %llu\n", uli.QuadPart);

	LocalFileTimeToFileTime(&ftLocal, &ftUTC);
	uli.LowPart = ftUTC.dwLowDateTime;
	uli.HighPart = ftUTC.dwHighDateTime;
	printf("UTC File Time: %llu\n", uli.QuadPart);

	FileTimeToSystemTime(&ftUTC, &stUTC2);
	printf("UTC System Time2 (YYYY-MM-DD HH:MM:SS): %d-%d-%d %d:%d:%d\n", stUTC2.wYear, stUTC2.wMonth,
		stUTC2.wDay, stUTC2.wHour, stUTC2.wMinute, stUTC2.wSecond);

	return EXIT_SUCCESS;
}

// https://www.cnblogs.com/huangsitao/p/10283623.html
// https://blog.csdn.net/bokee/article/details/5330791