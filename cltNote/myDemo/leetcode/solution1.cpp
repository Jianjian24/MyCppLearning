#include "../../../jian.h"

//字母异位词
class Solution1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapChar;
        string strContent;
        for(auto it : strs){
            strContent = it;
            std::sort(it.begin(), it.end());
            mapChar[it].push_back(strContent);
        }

        vector<vector<string>> res;
        res.resize(mapChar.size());

        int idx = 0;
        for(auto it : mapChar){
            res[idx++].assign(it.second.begin(), it.second.end());
        }

        return res;
    }
};

//无重复字符的最长子串
class Solution2 {
public:
    bool JudgeRepeat(string& s, int begin, int end){
        unordered_map<char, bool> mapJudge;
        for(int i = begin; i < end; ++i){
            if (mapJudge.find(s[i]) != mapJudge.end()){
                //找到了存在的字符
                return true;
            }
            else{
                mapJudge[s[i]] = true;
            }
            return false;
        }
    }

    int lengthOfLongestSubstring(string s) {
        //由最长窗口开始，判断窗口内是否有重复字符
        //没有重复字符则直接返回当前窗口长度
        //有则缩短窗口长度，重新遍历该字符串
        int maxLen = s.length();
        int curLen = maxLen;

        if (curLen < 2)
        {
            return curLen;
        }
        
        while (curLen > 0)
        {
            for (size_t i = 0; i <= maxLen - curLen; i++)
            {
                if (!JudgeRepeat(s, i, i + curLen))
                {
                    return curLen;
                }
            }
            --curLen;
        }
    }
};


//找到字符串中所有字母异位词
class Solution3 {
public:
    vector<int> findAnagrams(string s, string p) {
        //滑动窗口+散列表
        //滑动窗口长度为p的大小，变量字符串s，找到符合子串p模式的子串

        vector<int> res;

        int windowsLen = p.length();
        int sLen = s.length();

        unordered_set<char> windowsChar;
        for(auto it : p){
            // windowsChar
        }
        for (size_t i = 0; i <= sLen - windowsLen; ++i)
        {
            
        }
        
    }
};

//560. 和为 K 的子数组
class SolutionK {
public:
    int subarraySum(vector<int>& nums, int k) {
        //利用队列遍历当前整数数组
        //每次添加或者删除元素就判断一下当前总和
        //若大于k则删除队列里的第一个元素，若小于k则添加一个元素
        //若等于k则结果+1并删除队列第一个元素且添加未添加的元素

        std::queue<int> qNum;
        int sum = nums[0];
        qNum.push(nums[0]);
        int len = nums.size(), res = 0;

        if (len == 1){
            if(sum == k)
                return 1;
            else
                return 0;
        }

        for(int i = 1; i < len; ++i){
            sum += nums[i];
            qNum.push(nums[i]);
            if(sum < k){
                if(qNum.front() < 0){
                    sum -= qNum.front();
                    qNum.pop();
                }
            }
            else if(sum > k){
                while(sum > k && qNum.empty() == false){
                    sum -= qNum.front();
                    qNum.pop();                   
                }
                // continue;
            }
            if (sum == k){
                ++res;
                sum -= qNum.front();
                qNum.pop();
                // ++i;
                continue;
            }
        }
        return res;
    }
};

int main(){
    SolutionK solution;
    vector<int> nums = {-1,-1,1};

    cout << solution.subarraySum(nums, 0) << endl;

    return 0;
}