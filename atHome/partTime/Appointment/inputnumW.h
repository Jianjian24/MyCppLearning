void inputnumW(int order)//���˿ڹ��õ���������д���ļ��ĺ���������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
{
	FILE *fp;
	if(order == 0)
	{
		fp = fopen("ԤԼ����.txt", "w");
	}
	else
	{
		fp = fopen("���ﰲ������.txt", "w");
	}
	
    if(fp ==NULL)
	{
		
		return;
	}
	if(order == 1)
	{
		fprintf(fp,"%d\n",inputd);
	}
	else
	{
		fprintf(fp,"%d\n",inputp);
	}

    fclose(fp);
}

