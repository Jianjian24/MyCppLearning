#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <mutex>

class CDebugLog {
public:
 CDebugLog() = default;

 ~CDebugLog() {
    //  std::ofstream logFile("CaliDebugInfo.txt", std::ios::out | std::ios::app);
    //  logFile << "End of the log at: " << std::ctime(&std::chrono::system_clock::now().time_since_epoch()) << std::endl;
    //  logFile.close();
 }

 void AddLog(const std::string& logInfo) {
      std::unique_lock<std::mutex> lock(m_mutex);
     std::ofstream logFile("c:/Code11/CaliDebugInfo.txt", std::ios::out | std::ios::app);
             if(!logFile.is_open())
        {
            std::cout<<"file open fail"<<std::endl;
            return;
        }
     std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
     std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
     auto nowTimeStr = std::localtime(&nowTime);
     std::ostringstream oss;

    std::string myFormat = "%Y-%m-%d:%H:%M:%S";  //自定义格式
      //strftime 第一个参数是 char * 
    strftime(myStr,sizeof(myStr),myFormat.c_str(),nowTimeStr);  //myFormat.c_str() 兼容c字符串，c中没有string类型
    std::cout<<"myStr is:" <<myStr <<std::endl;

     oss << myStr;
     oss << ", " << logInfo;
     logFile << oss.str() << std::endl;
     logFile.close();
 }

private:
 CDebugLog(const CDebugLog&) = delete;
 CDebugLog& operator=(const CDebugLog&) = delete;
   std::mutex m_mutex;
   char myStr[255]="\0";
};

int main() {
 CDebugLog logInfo;

 std::string log1 = "This is a test log.";
 logInfo.AddLog(log1);

 std::string log2 = "This is another test log.";
 logInfo.AddLog(log2);

 return 0;
}