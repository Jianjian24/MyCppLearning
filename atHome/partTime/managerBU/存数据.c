#include"stud.h"
void save()
{
	FILE * fp;
	int i;
	if((fp=fopen("lxr.dat","wb"))==NULL)
	{printf("�޷��򿪴��ļ�\n");
	return;
	}
	for(i=0;i<t;i++)
		if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
			printf("�ļ��������\n");
	fclose(fp);
}