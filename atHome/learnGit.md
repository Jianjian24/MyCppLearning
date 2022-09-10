# Learn Git Branching
## git checkout [nodeName]
1. 将HEAD移动到指定的节点，输入分支名字的时，移动到分支所在的最新节点
2. 支持输入移位相关的操作 
   1. git checkout main^ 代表将HEAD节点移动到main节点的前一个位置处
   2. git checkout main~3 代表将HEAD节点移动到main节点的前3个位置处
## git switch [branchName]
1. 切换HEAD到某个特定节点处
2. checkout 操作也可以实现，但是更推荐使用switch