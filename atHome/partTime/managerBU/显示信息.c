#include"stud.h"
void display()                        /*��ʾ��ҵ����Ϣ*/
{
	int j;
	FILE*fp;
	system("cls"); 
	printf("\n\n");
	printf("\t\t\t\t\t\t\t            ��ҵ����Ϣ��ʾ.\n\n"); 
	printf("\t\t*******************************************************************************************************************\n\n");
	printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n","ѧ��","����","�Ա�","�༶","QQ��","��ϵ�绰","�Ƿ��ҵ","��ҵ����");
	printf("\n");
	if((fp=fopen("lxr.dat","rb"))==NULL)
	{
		printf("\t\t\t\t\t\t\t            �޷��򿪴��ļ�\n");
		exit(0);
	}
	for(j=0;j<t;j++)		
	{ 	
    fread(&stu[j],sizeof(struct student),1,fp);
    printf("\t\t%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n\n",stu[j].num,stu[j].name,stu[j].sex,stu[j].cla,stu[j].QQ,stu[j].tele,stu[j].job,stu[j].city);	
	} 
	printf("\t\t*******************************************************************************************************************\n\n");
	printf("\n �����������.\n");
	fclose(fp);
	_getch();	 
	enter();
}