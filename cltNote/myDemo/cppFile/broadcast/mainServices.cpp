#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <cstring>
#include <Winsock2.h>

#define MAX_SUBSERVICES 10

struct Subservice {
  std::string name;
  sockaddr_in address;
};

std::vector<Subservice> subservices;

void init_server() {
  WSADATA wsaData;
  WSAStartup(MAKEWORD(2, 2), &wsaData);

  int server_fd = WSASocket(AF_INET, SOCK_DGRAM, 0, NULL, NULL, WSA_FLAG_OVERLAPPED);
  if (server_fd == INVALID_SOCKET) {
      std::cerr << "Failed to create socket" << std::endl;
      exit(EXIT_FAILURE);
  }

  sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(12345);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
      std::cerr << "Failed to bind socket" << std::endl;
      WSACleanup();
      exit(EXIT_FAILURE);
  }

  std::cout << "Server is listening on port 12345" << std::endl;
}

void handle_message(char* message, int length) {
  std::string received_message(message, length);
  std::istringstream iss(received_message);
  std::string command;
  iss >> command;

  if (command == "REGISTER") {
      std::string subservice_name;
      iss >> subservice_name;

      Subservice subservice;
      subservice.name = subservice_name;
      subservice.address = iss.get().s_addr;

      subservices.push_back(subservice);
      std::cout << "Registered subservice " << subservice_name << std::endl;
  } else if (command == "UNREGISTER") {
      std::string subservice_name;
      iss >> subservice_name;

      for (auto& subservice : subservices) {
          if (subservice.name == subservice_name) {
              subservices.erase(std::remove_if(subservices.begin(), subservices.end(), [&](Subservice s) { return s.name == subservice_name; }));
              std::cout << "Unregistered subservice " << subservice_name << std::endl;
              break;
          }
      }
  } else if (command == "Broadcast") {
      // Handle broadcast message
  } else {
      std::cout << "Unknown command: " << received_message << std::endl;
  }
}

int main() {
  init_server();

  while (true) {
      char buffer[1024];
      int receive_fd = recvfrom(server_fd, buffer, sizeof(buffer), 0, (sockaddr*)&client_addr, &client_addr_len);

      if (receive_fd == SOCKET_ERROR) {
          std::cerr << "Failed to receive data" << std::endl;
          continue;
      }

      handle_message(buffer, receive_fd);
  }

  WSACleanup();
  return 0;
}