#include <iostream>
#include <algorithm>
#include <string>
#include <random>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
using namespace std;

typedef long long LL;
//mt19937_64 gen(time(0));

struct node {      //定义作业的属性，放在结构体里
    int start;     //开始时间
    int end;       //结束时间
    int num;       //作业编号
    int w;         //优先数
    int wait = 0;  //等待时间
} e[50], h[1000010];

bool cmp(node a, node b) { return a.start < b.start; }

int randInt(int l, int r) {
	srand(time(0)); 
    return rand() % (r - l + 1) + l;
}  //生成[l,R]的int型数字
LL randLL(LL l, LL r) {
    srand(time(0));
	return rand() % (r - l + 1) + l;
}  //生成[l,R]的 long long int型数字

void loading() {  //打印数据处理进度条
    printf("\n数据处理中,请稍后……\n");
    for (int i = 1; i <= 5; i++) {
        printf("[");
        for (int j = 1; j <= i; j++) printf("■■");
        for (int j = 0; j < 5 - i; j++) printf("□□");
        printf("]\t%d%%", i * 20);
        Sleep(1000);
        printf("\r");
    }
    printf("\n\n");
    return;
}


void loading2() {  //打印数据处理进度条
    printf("\n数据生成中,请稍后……\n");
    for (int i = 1; i <= 2; i++) {
        printf("[");
        for (int j = 1; j <= i; j++) printf("■■■■■");
        for (int j = 0; j < 2 - i; j++) printf("□□□□□");
        printf("]\t%d%%", i * 50);
        Sleep(1000);
        printf("\r");
    }
    printf("\n\n");
    return;
}


int cnt = 0;  //小顶堆中作业个数

void create(int x, int k) {  //建立小顶堆
    h[++cnt].w = x;
    h[cnt].num = k;
    int t = cnt; //存放节点，总结点数 
    while (t > 1 && h[t / 2].w > h[t].w)//判断是否比父节点要小
	 {
        swap(h[t], h[t / 2]);
        t /= 2;
    }
    h[t].w = x;
    return;
}

// void update() {  //更新小顶堆(劣质版)
//     for (int i = cnt; i >= 2; i--)
//         if (h[i / 2].w > h[i].w) swap(h[i / 2], h[i]);
//     return;
// }

void down(int u) {  //更新小顶堆(新版)
    int t = u;//t表示三个点中的最小值 
    if (2 * u <= cnt && h[2 * u].w < h[t].w) t = 2 * u;//左儿子 
    if (2 * u + 1 <= cnt && h[2 * u + 1].w < h[t].w) t = 2 * u + 1;//找出该节点与孩子节点之中的最小节点 
    if (t != u)//交换节点，如果当前的父亲不是最小的，就交换，并递归处理 
	 {
        swap(h[t], h[u]);
        down(t);
    }
    return;
}

bool judge(string s) {  //判断字符串是否完全由数字构成,即字符串是否合法
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9')
            continue;
        else
            return false;
    return true;
}

void check(int k)  //调度核心函数
{
    int ans = 1;
    sort(e, e + k, cmp);
    int flag = 0;
    int time = 0;
    for (int i = 1; i <= 2000; i++) {
        if (i == time) flag = 0;
        for (int j = 0; j < k; j++)
            if (e[j].start == i) create(e[j].end, j);
        if (cnt > 0) {
            if (flag == 0) {
                int tot = h[1].num;
                int weight = h[1].w;
                swap(h[1], h[cnt]);
                cnt--;
                down(1);
                printf(
                    "%d-编号为%d的作业于%d时进入队列\t于%d时开始调度\t于%d"
                    "时离开\t调度时长为%d\t该作业等待时间为"
                    "%d\t执行该作业时该作业的优先数为"
                    "%d    优先数动态变化情况%d -> %d\n",
                    ans++, e[tot].num, e[tot].start, i,
                    i + e[tot].end - e[tot].start, e[tot].end - e[tot].start,
                    e[tot].wait, weight, e[tot].end, weight);
                flag = 1;
                time = i + e[tot].end - e[tot].start;
            }
            for (int i = 1; i <= cnt; i++) {
                e[h[i].num].wait++;
                h[i].w -= e[h[i].num].wait;
            }
        }
    }
    return;
}

void color(int x) {
    if (x == 0)  //白色
        return;
    else if (x == 1)  //红色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                FOREGROUND_INTENSITY | FOREGROUND_RED);
    else if (x == 2)  //绿色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    else if (x == 3)  //蓝色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    else if (x == 4)  //粉色
        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
    else if (x == 5)  //青色
        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    else if (x == 6)  //黄色
        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    else if (x == 7)  //随机生成
        color(randInt(0, 6));
    return;
}

int main() {
    /*
	printf(
        "\n***************************************************\n");  //输出文字信息
    printf("*         -基于优先队列的作业调度算法实现-        *\n");
    printf("*                   作者:孙黎明                  *\n");
    printf("***************************************************\n\n");

    printf("\n----------字体颜色----------\n");
    printf("0.白色\n");
    printf("1.红色\n");
    printf("2.绿色\n");
    printf("3.蓝色\n");
    printf("4.粉色\n");
    printf("5.青色\n");
    printf("6.黄色\n");
    printf("7.随机生成\n");
    printf("-----------------------------\n");
    printf("\n请输入您想用字体颜色的编号:");
    string tmp;
    while (getline(cin, tmp)) {
        if (tmp == "0" || tmp == "1" || tmp == "2" || tmp == "3" ||
            tmp == "4" || tmp == "5" || tmp == "6" || tmp == "7") {
            color(stoi(tmp));
            break;
        } else
            printf("非法输入,请重新输入:");
    }
*/
    printf("\n   ----------菜单----------\n");
    printf("   1.手动输入作业信息\n");
    printf("   2.电脑自动生成作业信息\n");
    printf("   3.退出\n");
    printf("   ------------------------\n");
    printf("\n请输入您所选的操作编号:");
    string s, str;
    while (getline(cin, s)) {
        if (s == "1" || s == "2" || s == "3")
            break;
        else
            printf("非法输入,请重新输入:");
    }
    if (s == "1") {
        printf("请输入作业个数(0-15的数字):");
        while (getline(cin, str)) {
            if (judge(str) && stoi(str) >= 0 &&
                stoi(str) <= 15) {  //判断输入是否合法
                int num = stoi(str);
                if (num == 0) {
                    printf("当前没有作业需要被调度\n");
                    break;
                }
                printf("请按顺序给出%d个作业的开始时间和结束时间\n", num);
                for (int i = 0; i < num; i++) {
                    printf(
                        "请输入第%d个作业的开始时间和结束时间，中间用空格间隔("
                        "1<=时间<=100):",
                        i + 1);
                    string str1, str2;
                    while (cin >> str1) {
                        cin >> str2;
                        if (judge(str1) && judge(str2) && stoi(str1) >= 1 &&
                            stoi(str1) <= 100 && stoi(str2) >= 1 &&
                            stoi(str2) <= 100 && stoi(str2) > stoi(str1)) {
                            e[i].start = stoi(str1);
                            e[i].end = stoi(str2);
                            e[i].num = i + 1;
                            break;
                        } else
                            printf("非法输入,请重新输入:");
                    }
                }
                //loading();
                check(num);
                break;
            }
            printf("非法输入,请重新输入:");
        }
    } else if (s == "2") {
        printf("请输入自动生成作业个数(0-15的数字):");
        while (getline(cin, str)) {
            if (judge(str) && stoi(str) >= 0 && stoi(str) <= 15) {
                //loading2();
                int num = stoi(str);
                int k = 0;
                while (k != num) {
                    int a = randInt(1, 100);  //生成随机数
                    int b = randInt(1, 100);
                    if (a < b) {  //去掉生成的非法随机数
                        e[k].start = a;
                        e[k].end = b;
                        e[k].num = k + 1;
                        k++;
                    }
                }
                if (k == 0) {
                    printf("当前没有作业需要被调度\n");
                    break;
                }
                printf("\n自动生成的数据如下:\n");
                for (int i = 0; i < k; i++)
                    printf("第%d个作业的开始时间是:%d,结束时间是:%d\n", i + 1,
                           e[i].start, e[i].end);
                //loading();
                check(k);
                break;
            } else
                printf("非法输入,请重新输入:");
        }
    }
    printf("\n谢谢使用!（￣︶￣）↗\n");  //程序结束
    /*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_INTENSITY | FOREGROUND_RED |
                                FOREGROUND_GREEN |
                                FOREGROUND_BLUE);  //将字体重新设置为白色
    */
    return 0;
}

