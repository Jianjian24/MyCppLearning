void ioWrite(List *pList,int order)//���˿ڹ��õĵ�¼����д�뺯��������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
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
	
    if (fp == NULL)  
    {  
        printf("������!\n");  
        return;  
    }  
    else
    {    
    Patient *p;
        for (p = pList->head; p ; p = p->next)  
        {  
			fprintf(fp,"%s\n",p->user);
			fprintf(fp,"%s\n",p->name);
			fprintf(fp,"%s\n",p->password);
			if(order == 1)
			{
				fprintf(fp,"%s\n",p->office);
				m++;    //ͬʱ������������ 
			}   
			else
			{
				n++;	//ͬʱ������������ 
			}
			
        }
    }   
    fclose(fp);
    
	
}
