#pragma once

#include <string>
#include <vector>
using namespace std;

class Topic
{
private:
    vector<string>  m_vecTopic;
    // string m_topic;
public:
    Topic();
    ~Topic();
    void GetTopic(vector<string>  &vecTopic);
    bool AddTopic(string& str);
};