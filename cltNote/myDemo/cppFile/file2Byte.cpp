#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
   // 文件路径
   std::string file_path = "E:\\EffectiveDebug\\leyarNew7\\CaliL.log";

   // 打开文件
   std::ifstream file(file_path, std::ios::binary);
   if (!file.is_open()) {
       std::cerr << "无法打开文件: " << file_path << std::endl;
       return 1;
   }

   // 读取文件内容
   std::vector<char> file_content;
   file.seekg(0, std::ios::end);
   file_content.resize(file.tellg());
   file.seekg(0, std::ios::beg);
   file.read(file_content.data(), file_content.size());

   // 关闭文件
   file.close();

   // 输出文件内容（用于调试）
   std::cout << "文件内容（原始）：" << std::endl;
   for (char c : file_content) {
       std::cout << static_cast<int>(c) << " ";
   }
   std::cout << std::endl;

   // 将文件内容转换为字节序
   std::vector<unsigned char> bytes_content;
   for (char c : file_content) {
       bytes_content.push_back(static_cast<unsigned char>(c));
   }

//    // 输出转换后的文件内容（用于调试）
//    std::cout << "文件内容（字节序）：" << std::endl;
//    for (unsigned char b : bytes_content) {
//        std::cout << static_cast<int>(b) << " ";
//    }
//    std::cout << std::endl;

  // 文件路径
  std::string file_pathO = "E:\\EffectiveDebug\\leyarNew7\\CaliLOut.log";

  // 打开文件
  std::ofstream fileO(file_pathO, std::ios::binary);
  if (!fileO.is_open()) {
      std::cerr << "无法打开文件: " << file_path << std::endl;
      return 1;
  }

  // 接收文件内容
//   std::vector<unsigned char> bytes_content;
  // ...（在这里处理接收到的字节序数据）

  // 将字节序转换回文件内容
  for (char b : bytes_content) {
      fileO.write(&b, 1);
  }

    // 关闭文件
  fileO.close();

  std::cout << "文件已成功接收并保存。" << std::endl;

   // 在网络中传输文件内容
   // 这里是一个假设的IP地址和端口号
   std::string target_ip = "127.0.0.1";
   int target_port = 12345;

//    // 创建套接字
//    std::socket socket(AF_INET, SOCK_STREAM, 0);
//    if (socket.ERROR) {
//        std::cerr << "无法创建套接字: " << socket.error() << std::endl;
//        return 1;
//    }

//    // 连接到目标计算机
//    sockaddr_in target_addr;
//    target_addr.sin_family = AF_INET;
//    target_addr.sin_port = htons(target_port);
//    inet_pton(AF_INET, target_ip.c_str(), &target_addr.sin_addr);

//    if (connect(socket, (sockaddr*)&target_addr, sizeof(target_addr)) == SOCKET_ERROR) {
//        std::cerr << "无法连接到目标计算机: " << socket.error() << std::endl;
//        return 1;
//    }

//    // 发送文件内容
//    if (send(socket, bytes_content.data(), bytes_content.size(), 0) == SOCKET_ERROR) {
//        std::cerr << "无法发送文件内容: " << socket.error() << std::endl;
//        return 1;
//    }

//    std::cout << "文件已成功发送到目标计算机。" << std::endl;

//    // 关闭套接字
//    close(socket);

   return 0;
}