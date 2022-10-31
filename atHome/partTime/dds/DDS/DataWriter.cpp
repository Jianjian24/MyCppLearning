#include ".\DataWriter.h"
#include <Winsock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")

DataWriter::DataWriter(/* args */)
{
}

DataWriter::~DataWriter()
{
}

bool DataWriter::write(string topic)
{
    const char* buf = topic.c_str();
    return on_data_write(buf);
}

bool on_data_write(const char* buf)
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
	SOCKET sockSen = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrSen;
	addrSen.sin_addr.S_un.S_addr = inet_addr("192.168.1.103");
	addrSen.sin_family = AF_INET;
	addrSen.sin_port = htons(6000);
	
	sendto(sockSen, buf, strlen(buf) + 1, 0, (SOCKADDR*)&addrSen, sizeof(SOCKADDR));
	closesocket(sockSen);
	WSACleanup();

    return true;
}