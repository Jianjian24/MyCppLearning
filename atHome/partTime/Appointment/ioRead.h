void ioRead(List *pList,int order)//���˿ڹ��õ�ע�ắ��������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
{ 
	
	int i;
	FILE *fp;
	//��ȡȫ�ֱ��� 
	if(order == 1)
	{
		fp = fopen("ҽ������.txt", "r");
		i = m;
	}
	else
	{
		fp = fopen("�û�����.txt", "r");
		i = n;
	}
	
    if (fp == NULL)  
    {  
          
        return; 
    }  
        while(i) //����ȫ�ֱ�����֪��Ҫ������ٴοռ� 
        {  
        	Patient *p = (Patient*)malloc(sizeof(Patient));	
			fscanf(fp,"%s",p->user); 
			fscanf(fp,"%s",p->name);
			fscanf(fp,"%s",p->password);
			if(order == 1)
			{
				fscanf(fp,"%s",p->office);
			}
			p->next = NULL;
			Patient *First = pList->head;
		    if (First)//head��Ϊ�գ�д��tail->next 
		    {
		        pList->tail->next = p;
		        pList->tail = pList->tail->next;
		    }
		    //head Ϊ�գ�д��head 
		    else
		    {
		        pList->head = pList->tail = p;
		    }
		    
    		i--;
        }
        if(order == 1)
		{
			m = i;
		}
		else
		{
			n = i;
		}
		
	fclose(fp);

}
