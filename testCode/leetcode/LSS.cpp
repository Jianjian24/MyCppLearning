// 最长连续序列
#include "../../../jian.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 利用set去重和存储存在的值
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }
        // printf();
        int longestStreak = 0;
            
        for (const int& num : num_set) {
            // 选择合适的开始点是这个算法的关键
            if (!num_set.count(num - 1)) { // 如果这个是起点才执行下面的代码
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;           
    }
};

int main()
{
    
    cout << "Hello" << endl;
    int a = 10;
    a = 11;
    char c = getchar();

    return 0;
}