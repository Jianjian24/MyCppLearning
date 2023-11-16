#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <IPMIB.h>

#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(lib, "Ws2_32.lib")
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

   // 设置广播选项
   DWORD dwBufSize = sizeof(SOCKET);
   DWORD dwIndex = 0;
   while (dwIndex < 10) {
       if (WSAIoctl(sock, STG_E_BADBASEADDRESS, NULL, 0, (char*)&sock, &dwBufSize, &dwIndex) == 0) {
           break;
       }
       Sleep(1000);
       dwIndex++;
   }

   // 发送广播消息
   std::string message = "Hello, I am the server.";
   for (int i = 0; i < 255; ++i) {
       sockaddr_in dest;
       dest.sin_family = AF_INET;
       dest.sin_port = htons(12345);
       dest.sin_addr.S_un.S_addr = inet_addr("192.168.1.100"); // 替换为客户端的IP地址

       if (sendto(sock, message.c_str(), message.size(), 0, (sockaddr*)&dest, sizeof(dest)) == SOCKET_ERROR) {
           std::cerr << "Failed to send broadcast message" << std::endl;
           return 1;
       }

       Sleep(1000); // 等待1秒钟后再发送下一条消息
   }

   closesocket(sock);
   return 0;
}