#include <string>
using namespace std;

class Topic
{
private:
    /* data */
    string m_topic;
public:
    Topic(string strTopic = "Undefine");
    ~Topic();
    string GetTopic();
};