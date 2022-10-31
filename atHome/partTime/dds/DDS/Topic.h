#include <string>
using namespace std;

class Topic
{
private:
    /* data */
    //todo: 动态数组
    string m_topic;
public:
    Topic(string strTopic = "Undefine");
    ~Topic();
    string GetTopic();
    bool SetTopic(string& str);
};