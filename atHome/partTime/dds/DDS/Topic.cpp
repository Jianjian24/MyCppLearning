#include ".\Topic.h"

Topic::Topic(string strTopic) : m_topic(strTopic)
{
}

Topic::~Topic()
{
}

string Topic::GetTopic()
{
    return m_topic;
}

bool Topic::SetTopic(string& str)
{
    m_topic = str;
}