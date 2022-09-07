# 一行代码就能解决的算法题
## Nim游戏
游戏规则是这样的：你和你的朋友面前有一堆石子，你们轮流拿，一次至少拿一颗，最多拿三颗，谁拿走最后一颗石子谁获胜。

假设你们都很聪明，由你第一个开始拿，请你写一个算法，输入一个正整数 n，返回你是否能赢（true 或 false）。

比如现在有 4 颗石子，算法应该返回 false。因为无论你拿 1 颗 2 颗还是 3 颗，对方都能一次性拿完，拿走最后一颗石子，所以你一定会输。

首先，这道题肯定可以使用动态规划，因为显然原问题存在子问题，且子问题存在重复。但是因为你们都很聪明，涉及到你和对手的博弈，动态规划会比较复杂。

我们解决这种问题的思路一般都是反着思考：

如果我能赢，那么最后轮到我取石子的时候必须要剩下 1~3 颗石子，这样我才能一把拿完。

如何营造这样的一个局面呢？显然，如果对手拿的时候只剩 4 颗石子，那么无论他怎么拿，总会剩下 1~3 颗石子，我就能赢。

如何逼迫对手面对 4 颗石子呢？要想办法，让我选择的时候还有 5~7 颗石子，这样的话我就有把握让对方不得不面对 4 颗石子。

如何营造 57 颗石子的局面呢？让对手面对 8 颗石子，无论他怎么拿，都会给我剩下 57 颗，我就能赢。

这样一直循环下去，我们发现只要踩到 4 的倍数，就落入了圈套，永远逃不出 4 的倍数，而且一定会输。所以这道题的解法非常简单：
```C++
bool Solution(int stone)
{
    bool result = stone % 4;
    if( result == 0 ) return false;
    else return true;

}
```

## 二分法查找子序列
1. 首先将母序列用哈希字典存储起来，每个字母出现的顺序进入对应字母的序列位置

```C++
boolean isSubsequence(String s, String t) {
    int m = s.length(), n = t.length();
    // 对 t 进行预处理
    ArrayList<Integer>[] index = new ArrayList[256];
    for (int i = 0; i < n; i++) {
        char c = t.charAt(i);
        if (index[c] == null) 
            index[c] = new ArrayList<>();
        index[c].add(i);
    }
    
    // 串 t 上的指针
    int j = 0;
    // 借助 index 查找 s[i]
    for (int i = 0; i < m; i++) {
        char c = s.charAt(i);
        // 整个 t 压根儿没有字符 c
        if (index[c] == null) return false;
        int pos = left_bound(index[c], j);
        // 二分搜索区间中没有找到字符 c
        if (pos == index[c].size()) return false;
        // 向前移动指针 j
        j = index[c].get(pos) + 1;
    }
    return true;
}
```