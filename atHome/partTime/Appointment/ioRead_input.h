void ioRead_input(Formlistp *pList,int order)//���˿ڹ��õĵ����ļ��ﵥ���ݵ�����ĺ���������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
{ 
	
	int i;
	FILE *fp;
	if(order == 0)
	{
		fp = fopen("ԤԼ����.txt", "r");
		i = inputp;//������ȫ�ֱ��� 
	} 
	else
	{
		fp = fopen("���ﰲ������.txt", "r");
		i = inputd;
	}
	
    if (fp == NULL)  
    {  
        return; 
    }  
        while(i) //����ȫ�ֱ����ж�������ٴοռ� 
        {  
        	Formp *p = (Formp*)malloc(sizeof(Formp));	

			if(order == 0)
			{
                fscanf(fp,"%s",p->user); 
		        fscanf(fp,"%s",p->name);
			    fscanf(fp,"%d",&p->timeYear);
				fscanf(fp,"%d",&p->timeMon);
                fscanf(fp,"%d",&p->timeDay);
                fscanf(fp,"%s",p->office);
                fscanf(fp,"%s",p->doctor);
			}
            else
            {
			    fscanf(fp,"%s",p->doctor);
                fscanf(fp,"%d",&p->timeYear);
				fscanf(fp,"%d",&p->timeMon);
                fscanf(fp,"%d",&p->timeDay);
                fscanf(fp,"%s",p->office);
                fscanf(fp,"%d",&p->number);
            }
            
			p->next = NULL;
			Formp *First = pList->head;
		    if (First)
		    {
		        pList->tail->next = p;//�ӵ�β�� 
		        pList->tail = pList->tail->next;
		    }
		    //ͷΪ�� 
		    else
		    {
		        pList->head = pList->tail = p;
		    }
		    
    		i--;
        }
        if(order == 1)
		{
			inputd = i;
		}
		else
		{
			inputp = i;
		}
		
	fclose(fp);

}

