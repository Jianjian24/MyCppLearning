#include"stud.h"
void save()
{
	FILE * fp;
	int i;
	if((fp=fopen("lxr.dat","wb"))==NULL)
	{printf("无法打开此文件\n");
	return;
	}
	for(i=0;i<t;i++)
		if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
			printf("文件输入错误\n");
	fclose(fp);
}