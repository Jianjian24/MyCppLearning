void usernumW(int order)//���˿ڹ��õĵ�¼��������д�뺯��������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
{
	FILE *fp;
	if(order == 1)
	{
		fp = fopen("ҽ������.txt", "w");
	}
	else
	{
		fp = fopen("�û�����.txt", "w");
	}
	
    if(fp ==NULL)
	{
		
		return;
	}
	if(order == 1)
	{
		fprintf(fp,"%d",m);//д���������� 
	}
	else
	{
		fprintf(fp,"%d",n);//д���������� 
	}

    fclose(fp);
}
