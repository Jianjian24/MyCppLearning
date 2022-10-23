#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class SolutionMergeStr1768 {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int len = len1 > len2 ? len1 : len2;
        string resultStr;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < len; i++)
        {
            if (i < len1)
                resultStr += word1[count1++];
            if (i < len2)
                resultStr += word2[count2++];
        }

        return resultStr;
    }
};

class SolutionTwoSumLink2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //遍历链表，拿到对位相加，过程中保留进位
        ListNode* head = new ListNode;
        ListNode* node = head;
        int flag = 0, tmp = 0;
        while (1)
        {
            if (l1)
            {
                tmp += l1->val;
                l1 = l1->next;
            }            
            if (l2)
            {
                tmp += l2->val;
                l2 = l2->next;
            }
            tmp += flag;
            if (tmp > 9)
            {
                flag = 1;
                tmp %= 10;
            }
            else
                flag = 0;
            
            node->val = tmp;
            tmp = 0;
            if (l1 || l2){
                node->next = new ListNode;
                node = node->next;
            }
            else
                break;
        }
        if (flag){
            node->next = new ListNode;
            node = node->next;
            node->val = 1;
        }
        return head;
    }
};  

class Solutionzuichangzichuan {
public:
    int lengthOfLongestSubstring(string s) {
        //滑动窗口解题，主要利用unorder_set来实现对非重复字符的提取
        int len = s.length();
        if (len == 0)
            return 0;
        unordered_set<char> memo;
        int count = 0, ans = 0;
        int rIndex = 0;
        for (int i = 0; i < len; i++)
        {
            // rIndex = i;
            while (rIndex < len && !memo.count(s.at(rIndex)))//一次滑动窗口找最长的子串
            {
                memo.emplace(s.at(rIndex++));
                count++; 
            }
            ans = ans > count ? ans : count;
            // auto itEnd = memo.begin();
            // for (int i = 0; i < count; i++)
            // {
            //     itEnd++;
            // }
            
            memo.erase(s.at(i));
            count -= 1;
        }
        
        return ans;
    }
};

class SolutionlongestPalindrome {
public:
    //1.异常处理
    //2.寻找回文字符串的中心点，中心点分为奇数和偶数中心
    int isPalindrome(string &s, int startIndex, int endIndex){
        int count = 0;
        if (startIndex == endIndex){
            startIndex--;
            endIndex++;
            count = 1;
        }
        int strLen = s.length();
        while (startIndex >= 0 && endIndex != strLen)
        {
            if (s.at(startIndex) == s.at(endIndex))
            {
                count += 2;
                startIndex--;
                endIndex++;
            }
            else
                break;
        }
        return count;
    }

    string longestPalindrome(string s) {
        int strLen = s.length(), curLen1 = 0, curLen2 = 0 , tmp = 0;
        if (strLen == 1)
            return s;
        pair<int, int> ans(0 ,0);
        for (int i = 0; i < strLen - 1; i++)
        {
            curLen1 = isPalindrome(s, i, i);
            curLen2 = isPalindrome(s, i, i + 1);
            tmp = curLen1 > curLen2 ? curLen1 : curLen2;
            if (ans.first < tmp)
            {
                ans.first = tmp;
                ans.second = i;
            }           
        }
        int startPos = ans.second - (ans.first - 1) / 2; 
        return s.substr(startPos, ans.first);
    }
};

int main()
{
    SolutionMergeStr1768 s1;

    cout << s1.mergeAlternately("abc", "ef2322434") << '\n';

    Solutionzuichangzichuan s2;
    cout << s2.lengthOfLongestSubstring("dvdsasadasf") << '\n';

    SolutionlongestPalindrome s3;
    cout << s3.longestPalindrome("a") << '\n';

    // system("pause");
    return 0;
   }