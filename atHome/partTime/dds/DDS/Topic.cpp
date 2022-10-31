#include ".\Topic.h"

Topic::Topic()
{
}

Topic::~Topic()
{
}

void Topic::GetTopic(vector<string>  &vecTopic)
{
    vecTopic.clear();
    vecTopic.assign(m_vecTopic.begin(), m_vecTopic.end());
}

bool Topic::AddTopic(string& str)
{
    m_vecTopic.push_back(str);
    return true;
}