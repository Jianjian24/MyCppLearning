#include "BroadcastServer.h"

int main() {
   // 创建一个UDP套接字
   int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

   // 设置套接字的广播选项
   int broadcast = 1;
   socklen_t broadcast_len = sizeof(broadcast);
   setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcast, broadcast_len);

   // 创建一个广播地址
   struct sockaddr_in broadcast_addr;
   memset(&broadcast_addr, 0, sizeof(broadcast_addr));
   broadcast_addr.sin_family = AF_INET;
   broadcast_addr.sin_port = htons(12345); // 选择一个端口号
   broadcast_addr.sin_addr.s_addr = INADDR_BROADCAST; // 广播地址

   // 发送广播消息
   std::string message = "Hello, broadcast!";
   sendto(sock, message.c_str(), message.size(), 0, (sockaddr*)&broadcast_addr, sizeof(broadcast_addr));

   // 等待客户端响应
   sockaddr_in client_addr;
   socklen_t client_addr_len = sizeof(client_addr);
   char buffer[1024];
   int bytes_received = recvfrom(sock, buffer, sizeof(buffer), 0, (sockaddr*)&client_addr, &client_addr_len);

   if (bytes_received > 0) {
       std::cout << "Received response from client: " << inet_ntoa(client_addr.sin_addr) << std::endl;
   } else {
       std::cout << "No clients responded." << std::endl;
   }

   // 关闭套接字
   close(sock);
   return 0;
}