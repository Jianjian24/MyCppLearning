#include"stud.h"
int LXR6(char x[20],int *v)
{
	int i;
    for (i=0;i<t+1; i++)
    {
		if (!strcmp(stu[i].job,x))
        {
			*v=i;
			return 1;
        }
    }
    return -1;
}
void preside()                         /*��ҵ����Ϣ��ͳ��*/
{	
	int v,b1;
	char b[20];
	int i=0;
	double k,now=0,j=0;
	while(strlen(stu[i].num))
	 {
		 i++;
		 now++;
	 }
	system("cls");
	printf("\n\t\t\t\t\t\t\t\t   ��ҵ����Ϣͳ��.\n");
	b1=LXR6(b,&v);
    for(i=0;i<now;i++)
	{
		if(b1==1)
		j++;
	}

	k=j/now*100.0;
	printf("\t\t\t\t\t\t\t\t   �ܾ�ҵ��Ϊ��%.0lf%%",k);
	printf("\n"); 
	printf("\t\t\t\t\t\t\t\t   ͳ�����,�밴���������.\n"); 
	_getch(); 
	enter(); 

 } 