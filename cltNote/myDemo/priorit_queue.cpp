#include<iostream>
#include<queue>
#include<functional>
using namespace std;
 
class cmp
{
public:
	bool operator()(int a, int b)
	{
		return a < b;
	}
};
 
bool cmp2(int a, int b)
{
	return a < b;
}
 
template <typename A>
void display()
{
	A q;
	q.push(1);
	q.push(3);
	q.push(4);
	q.push(2);
	while (!q.empty())
	{
		cout << q.top();
		q.pop();
	}
	cout << endl;
}
 
int main()
{
	display < priority_queue<int, vector<int>> >();  //默认大顶堆	
	display < priority_queue <int, vector<int>, greater<int>> >();//小顶堆
	display < priority_queue <int, vector<int>, less<int>> >();//大顶堆
	display < priority_queue<int, vector<int>, cmp>>();//大顶堆
	//display < priority_queue<int, vector<int>, cmp2>>();  错误
	return 0;
}