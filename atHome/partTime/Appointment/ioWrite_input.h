void ioWrite_input(Formlistp *pList,int order)//���˿ڹ��õ���������д���ļ��ĺ���������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
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
	
    if (fp == NULL)  
    {  
        printf("������!\n");  
        return;  
    }  
    else
    {    
    Formp *p;
        for (p = pList->head; p ; p = p->next)  
        {  
			if(order == 0)
			{
                fprintf(fp,"%s\n",p->user); 
		        fprintf(fp,"%s\n",p->name);
			    fprintf(fp,"%d\n",p->timeYear);
				fprintf(fp,"%d\n",p->timeMon);
                fprintf(fp,"%d\n",p->timeDay);
                fprintf(fp,"%s\n",p->office);
                fprintf(fp,"%s\n",p->doctor);
                inputp++;//ȫ�ֱ������� 
			}
            else
            {
			    fprintf(fp,"%s\n",p->doctor);
                fprintf(fp,"%d\n",p->timeYear);
				fprintf(fp,"%d\n",p->timeMon);
                fprintf(fp,"%d\n",p->timeDay);
                fprintf(fp,"%s\n",p->office);
                fprintf(fp,"%d\n",p->number);
                inputd++;
            }
			
        }
    }   
    fclose(fp);
    
	
}
