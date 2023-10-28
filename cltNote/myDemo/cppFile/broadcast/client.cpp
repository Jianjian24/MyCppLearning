#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <IPMIB.h>

#pragma comment(lib, "IPHLPAPI.lib")

int main() {
   SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
   if (sock == INVALID_SOCKET) {
       std::cerr << "Failed to create socket" << std::endl;
       return 1;
   }

   // 绑定到任意地址和指定端口
   sockaddr_in addr;
   addr.sin_family = AF_INET;
   addr.sin_port = htons(12345);
   addr.sin_addr.S_un.S_addr = INADDR_ANY;
   if (bind(sock, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
       std::cerr << "Failed to bind socket" << std::endl;
       return 1;
   }

   // 设置接收缓冲区大小
   int bufferSize = 1024;
   setsockopt(sock, SOL_SOCKET, SO_RCVBUF, (char*)&bufferSize, sizeof(bufferSize));

   // 准备接收广播消息
   sockaddr_in src;
   int srcSize = sizeof(src);
   char buffer[bufferSize];

   for (int i = 0; i < 255; ++i) {
       if (recvfrom(sock, buffer, bufferSize, 0, (sockaddr*)&src, &srcSize) == SOCKET_ERROR) {
           std::cerr << "Failed to receive broadcast message" << std::endl;
           return 1;
       }

       std::cout << "Received from " << inet_ntoa(src.sin_addr) << std::endl;
   }

   closesocket(sock);
   return 0;
}