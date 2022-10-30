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
		printf("%s\n", recvBuf);
	}
	closesocket(sockRec);
	WSACleanup();

	return 0;
}
