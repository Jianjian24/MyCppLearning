void inputnumR(int order)//���˿ڹ��õ�����������¼����������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
{
	FILE *fp;
	if(order == 0)
	{
		fp = fopen("ԤԼ����.txt", "r");
	}
	else
	{
		fp = fopen("���ﰲ������.txt", "r");
	}
	
	
	if(fp == NULL)
	{
			inputd=0;//��Ϊ��¼��ȫ�ֱ��� 
			inputp=0; 
	}
    else
    {
		
		if(order == 1)
		{
			fscanf(fp,"%d",&inputd);
		}
		else
		{
			fscanf(fp,"%d",&inputp);
		}
		
	    fclose(fp);
	}
}
