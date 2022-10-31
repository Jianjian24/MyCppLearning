#include ".\DataReader.h"
#include <Winsock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")

DataReader::DataReader(/* args */)
{
}

DataReader::~DataReader()
{
}

bool DataReader::read(string topic)
{
    const char* buf = topic.c_str();
    return on_data_available(buf);
}

bool DataReader::on_data_available(const char* buf)
{
    WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return false;
	}

	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return false;
	}

	SOCKET sockRec = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrRec;
	addrRec.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrRec.sin_family = AF_INET;
	addrRec.sin_port = htons(6000);

	bind(sockRec, (SOCKADDR*)&addrRec, sizeof(SOCKADDR));
	// int iTimeout = 5000;//5s没收到消息退出当前函数
	// setsockopt(sockRec, SOL_SOCKET, SO_RCVTIMEO, (const char *)&iTimeout, sizeof(iTimeout));
	SOCKADDR_IN addrSen;
	int len = sizeof(SOCKADDR);
	char recvBuf[100];
	while (1)
	{
		recvfrom(sockRec, recvBuf, 100, 0, (SOCKADDR*)&addrSen, &len);
        if(strcmp(recvBuf, buf) == 0) // 接收到相应Topic
		    printf("%s\n", recvBuf);
	}
	closesocket(sockRec);
	WSACleanup();

    return true;
}