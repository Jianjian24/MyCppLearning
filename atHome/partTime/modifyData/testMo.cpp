#include <stdio.h>
int main() 
{ 
	printf("Hello world!!\n"); 
	int a,b; 
	freopen("D:\\in.txt","r",stdin); //输入重定向，输入数据将从D盘根目录下的in.txt文件中读取 
	freopen("D:\\out.txt","w",stdout); //输出重定向，输出数据将保存在D盘根目录下的out.txt文件中 
	while(scanf("%d %d",&a,&b)!=EOF) 
	    printf("%d\n",a+b); 
	fclose(stdin);//关闭重定向输入 
	fclose(stdout);//关闭重定向输出 
	return 0; 
} 