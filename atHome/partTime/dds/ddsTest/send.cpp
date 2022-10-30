#include <Winsock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return 1;
	}

	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return 1;
	}
	SOCKET sockSen = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrSen;
	addrSen.sin_addr.S_un.S_addr = inet_addr("192.168.1.103");
	addrSen.sin_family = AF_INET;
	addrSen.sin_port = htons(6000);
	
	sendto(sockSen, "123", strlen("123") + 1, 0, (SOCKADDR*)&addrSen, sizeof(SOCKADDR));
	closesocket(sockSen);
	WSACleanup();

	return 0;
}
