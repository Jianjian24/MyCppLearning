void usernumR(int order)//���˿ڹ��õĵ�¼����������¼����������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
{
	FILE *fp;
	if(order == 1)
	{
		fp = fopen("ҽ������.txt", "r");
	}
	else
	{
		fp = fopen("�û�����.txt", "r");
	}
	
	
	if(fp == NULL)
	{
		if(order == 1)
		{
			m=0;//ҽ������ȫ�ֱ��� 
		}
		else
		{
			n=0;//�û�����ȫ�ֱ���
		}
	}
    else
    {
		
		if(order == 1)
		{
			fscanf(fp,"%d",&m);
		}
		else
		{
			fscanf(fp,"%d",&n);
		}
		
	    fclose(fp);
	}
}
