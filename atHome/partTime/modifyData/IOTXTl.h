#include "stdio.h"
#include <iostream>

using namespace std;

#define N 30000 //数组大小，根据不同需要可以直接改
// #define N 1000 //数组大小，根据不同需要可以直接改
double excel_x[N]; //散点X坐标
double excel_y[N]; //散点Y坐标
double Wm[N]={-1}; //引用头文件时数组初始化为-1（你的数据应该没有负数，这样最后输出的时候不会有多余的数据）
int a;					//你对数组数据进行操作后调用函数可以直接输�?
double Wf[N]={-1};
double tsatm[N],tsatf[N];
//以上四个数组都是全局的，在程序其他地方可以直接用

int ReadFromTXT(const char* file_name)
{
	int i=0;
	
	freopen(file_name, "r", stdin);
	while(scanf("%lf\t%lf\n",&excel_x[i],&excel_y[i])!=EOF)
	{
		//printf("%lf\t%lf\n",excel_x[i],excel_y[i]);
		i++;
	}
	fclose(stdin);
	return 1;
};

 int WriteIntoTXT(const char* file_name,char ture_name[])
{
	 freopen(file_name, "a", stdout);
	/*cout<<"file_name"<<'\t'<<"Wm"<<'\t'<<"Wf"<<endl;��ӡͷ�ļ�*/
	 if(Wm[a]!=-1)
	 {
		 cout<<ture_name<<'\t';
		 printf("%lf\t%lf\t%lf\t%lf\n",Wm[a],tsatm[a],Wf[a],tsatf[a]);
	 }
	 fclose(stdout);
	 printf("计算完毕");
	 return 1;
 }
