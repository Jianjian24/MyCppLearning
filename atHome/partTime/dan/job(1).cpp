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

struct node {      //������ҵ�����ԣ����ڽṹ����
    int start;     //��ʼʱ��
    int end;       //����ʱ��
    int num;       //��ҵ���
    int w;         //������
    int wait = 0;  //�ȴ�ʱ��
} e[50], h[1000010];

bool cmp(node a, node b) { return a.start < b.start; }

int randInt(int l, int r) {
	srand(time(0)); 
    return rand() % (r - l + 1) + l;
}  //����[l,R]��int������
LL randLL(LL l, LL r) {
    srand(time(0));
	return rand() % (r - l + 1) + l;
}  //����[l,R]�� long long int������

void loading() {  //��ӡ���ݴ��������
    printf("\n���ݴ�����,���Ժ󡭡�\n");
    for (int i = 1; i <= 5; i++) {
        printf("[");
        for (int j = 1; j <= i; j++) printf("����");
        for (int j = 0; j < 5 - i; j++) printf("����");
        printf("]\t%d%%", i * 20);
        Sleep(1000);
        printf("\r");
    }
    printf("\n\n");
    return;
}


void loading2() {  //��ӡ���ݴ��������
    printf("\n����������,���Ժ󡭡�\n");
    for (int i = 1; i <= 2; i++) {
        printf("[");
        for (int j = 1; j <= i; j++) printf("����������");
        for (int j = 0; j < 2 - i; j++) printf("����������");
        printf("]\t%d%%", i * 50);
        Sleep(1000);
        printf("\r");
    }
    printf("\n\n");
    return;
}


int cnt = 0;  //С��������ҵ����

void create(int x, int k) {  //����С����
    h[++cnt].w = x;
    h[cnt].num = k;
    int t = cnt; //��Žڵ㣬�ܽ���� 
    while (t > 1 && h[t / 2].w > h[t].w)//�ж��Ƿ�ȸ��ڵ�ҪС
	 {
        swap(h[t], h[t / 2]);
        t /= 2;
    }
    h[t].w = x;
    return;
}

// void update() {  //����С����(���ʰ�)
//     for (int i = cnt; i >= 2; i--)
//         if (h[i / 2].w > h[i].w) swap(h[i / 2], h[i]);
//     return;
// }

void down(int u) {  //����С����(�°�)
    int t = u;//t��ʾ�������е���Сֵ 
    if (2 * u <= cnt && h[2 * u].w < h[t].w) t = 2 * u;//����� 
    if (2 * u + 1 <= cnt && h[2 * u + 1].w < h[t].w) t = 2 * u + 1;//�ҳ��ýڵ��뺢�ӽڵ�֮�е���С�ڵ� 
    if (t != u)//�����ڵ㣬�����ǰ�ĸ��ײ�����С�ģ��ͽ��������ݹ鴦�� 
	 {
        swap(h[t], h[u]);
        down(t);
    }
    return;
}

bool judge(string s) {  //�ж��ַ����Ƿ���ȫ�����ֹ���,���ַ����Ƿ�Ϸ�
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9')
            continue;
        else
            return false;
    return true;
}

void check(int k)  //���Ⱥ��ĺ���
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
                    "%d-���Ϊ%d����ҵ��%dʱ�������\t��%dʱ��ʼ����\t��%d"
                    "ʱ�뿪\t����ʱ��Ϊ%d\t����ҵ�ȴ�ʱ��Ϊ"
                    "%d\tִ�и���ҵʱ����ҵ��������Ϊ"
                    "%d    ��������̬�仯���%d -> %d\n",
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
    if (x == 0)  //��ɫ
        return;
    else if (x == 1)  //��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                FOREGROUND_INTENSITY | FOREGROUND_RED);
    else if (x == 2)  //��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    else if (x == 3)  //��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    else if (x == 4)  //��ɫ
        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
    else if (x == 5)  //��ɫ
        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    else if (x == 6)  //��ɫ
        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    else if (x == 7)  //�������
        color(randInt(0, 6));
    return;
}

int main() {
    /*
	printf(
        "\n***************************************************\n");  //���������Ϣ
    printf("*         -�������ȶ��е���ҵ�����㷨ʵ��-        *\n");
    printf("*                   ����:������                  *\n");
    printf("***************************************************\n\n");

    printf("\n----------������ɫ----------\n");
    printf("0.��ɫ\n");
    printf("1.��ɫ\n");
    printf("2.��ɫ\n");
    printf("3.��ɫ\n");
    printf("4.��ɫ\n");
    printf("5.��ɫ\n");
    printf("6.��ɫ\n");
    printf("7.�������\n");
    printf("-----------------------------\n");
    printf("\n������������������ɫ�ı��:");
    string tmp;
    while (getline(cin, tmp)) {
        if (tmp == "0" || tmp == "1" || tmp == "2" || tmp == "3" ||
            tmp == "4" || tmp == "5" || tmp == "6" || tmp == "7") {
            color(stoi(tmp));
            break;
        } else
            printf("�Ƿ�����,����������:");
    }
*/
    printf("\n   ----------�˵�----------\n");
    printf("   1.�ֶ�������ҵ��Ϣ\n");
    printf("   2.�����Զ�������ҵ��Ϣ\n");
    printf("   3.�˳�\n");
    printf("   ------------------------\n");
    printf("\n����������ѡ�Ĳ������:");
    string s, str;
    while (getline(cin, s)) {
        if (s == "1" || s == "2" || s == "3")
            break;
        else
            printf("�Ƿ�����,����������:");
    }
    if (s == "1") {
        printf("��������ҵ����(0-15������):");
        while (getline(cin, str)) {
            if (judge(str) && stoi(str) >= 0 &&
                stoi(str) <= 15) {  //�ж������Ƿ�Ϸ�
                int num = stoi(str);
                if (num == 0) {
                    printf("��ǰû����ҵ��Ҫ������\n");
                    break;
                }
                printf("�밴˳�����%d����ҵ�Ŀ�ʼʱ��ͽ���ʱ��\n", num);
                for (int i = 0; i < num; i++) {
                    printf(
                        "�������%d����ҵ�Ŀ�ʼʱ��ͽ���ʱ�䣬�м��ÿո���("
                        "1<=ʱ��<=100):",
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
                            printf("�Ƿ�����,����������:");
                    }
                }
                //loading();
                check(num);
                break;
            }
            printf("�Ƿ�����,����������:");
        }
    } else if (s == "2") {
        printf("�������Զ�������ҵ����(0-15������):");
        while (getline(cin, str)) {
            if (judge(str) && stoi(str) >= 0 && stoi(str) <= 15) {
                //loading2();
                int num = stoi(str);
                int k = 0;
                while (k != num) {
                    int a = randInt(1, 100);  //���������
                    int b = randInt(1, 100);
                    if (a < b) {  //ȥ�����ɵķǷ������
                        e[k].start = a;
                        e[k].end = b;
                        e[k].num = k + 1;
                        k++;
                    }
                }
                if (k == 0) {
                    printf("��ǰû����ҵ��Ҫ������\n");
                    break;
                }
                printf("\n�Զ����ɵ���������:\n");
                for (int i = 0; i < k; i++)
                    printf("��%d����ҵ�Ŀ�ʼʱ����:%d,����ʱ����:%d\n", i + 1,
                           e[i].start, e[i].end);
                //loading();
                check(k);
                break;
            } else
                printf("�Ƿ�����,����������:");
        }
    }
    printf("\nллʹ��!����������J\n");  //�������
    /*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_INTENSITY | FOREGROUND_RED |
                                FOREGROUND_GREEN |
                                FOREGROUND_BLUE);  //��������������Ϊ��ɫ
    */
    return 0;
}

