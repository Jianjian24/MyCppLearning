void otherLook(char u[],char n[],char doctor1[],char office[],int order,int time)//���˿ڹ��õĲ鿴�Է�����Ϣ����������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1���������ݴ��� 
{	system("cls");
	if (order == 0)
	{
		int f = 0,i = 0,j = 0;
		Formlistp listp,listd;
		listp.head =listp.tail = NULL;
		listd.head =listd.tail = NULL;
		inputnumR(1);
		ioRead_input(&listp,1);
		printf("\n\n\t\t\t\t�±��ǿ�ԤԼ����Ϣ\n\n\t\t\t\t����ʱ���Ⱥ�����\n\n");
		Formp *q;
		for ( q= listp.head; q ; q = q->next)//�ҳ���صĵ�����listd 
    	{
			if(!strcmp(q->office,office)&&timeJudge(q->timeYear,q->timeMon,q->timeDay)<=0)
			{
				Addinput(&listd,"k","k",q->timeYear,q->timeMon,q->timeDay,q->doctor,office,q->number,1);//�������� 
				f++;//��ȡ���ݸ��� 
			}
		}
		if(f == 0)
		{
			printf("\n\n\t\t\t\tδ��û��%s�ľ�����Ϣ\n\n",office);
			system("PAUSE");
			return;
		}
		Formp *b;
		Formp *k;
		int year,month,day;
		int number;
		Formp *p = listd.head;
		char doctor[30];
		for (i=0; i<f-1; i++) 
		{
			p = listd.head;
			year = p->next->timeYear;
			month = p->next->timeMon;
			day = p->next->timeDay;
        	for (p = listd.head;p;p = p->next) 
			{

			if (timecpy(year,month,day,p->timeYear,p->timeMon,p->timeDay)<=0)//�ﵥʱ�����򣬻�ȡСֵ 
			{
				year = p->timeYear;
				month = p->timeMon;
				day = p->timeDay;
				strcpy(doctor,p->doctor);
				number = p->number;
			}
        	}

		for (k = NULL, b = listd.head; b ;k = b,b = b->next)// �ͷ�Сֵ���� 
	    {
	        if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,doctor))
	        {
	            if (k)
	            {
	                k->next = b->next;
	            }
	            else
	            {
	                listd.head = b->next;
	            }
	            free(b);
	            break;
	        }
	
	    }
		printf("\t\t\t\tҽ����%s\n\t\t\t\t���ң�%s\n\t\t\t\tʱ�䣺%d��%d��%d��\n\t\t\t\tʣ��������%d\n\n",doctor,office,year,month,day,number);
		
		}
		p = listd.head; 
		printf("\t\t\t\tҽ����%s\n\t\t\t\t���ң�%s\n\t\t\t\tʱ�䣺%d��%d��%d��\n\t\t\t\tʣ��������%d\n\n\n\n",p->doctor,p->office,p->timeYear,p->timeMon,p->timeDay,p->number);//zuihoude*/
		system("PAUSE");
		freeFormlistp(&listp);
		freeFormlistp(&listd);
		lnput(u,n,office,0);
	}
	else
	{
		int f = 0,i = 0,j = 0;
		Formlistp listp,listd;
		listp.head =listp.tail = NULL;
		listd.head =listd.tail = NULL;
		inputnumR(0);
		ioRead_input(&listp,0);
		printf("\n\n\t\t\t\t����ʱ���Ⱥ�����\n\n");
		Formp *q;
		if(time == 1)
		{
			for ( q= listp.head; q ; q = q->next)//�ҳ���صĵ�����listd 
	    	{
				if(!strcmp(q->doctor,doctor1)&&!strcmp(q->office,office)&&timeJudge(q->timeYear,q->timeMon,q->timeDay)<=0)
				{
					Addinput(&listd,q->user,q->name,q->timeYear,q->timeMon,q->timeDay,q->doctor,office,q->number,0);//�������� 
					f++;//��ȡ���ݸ��� 
				}
			}
		}
		else
		{
			for ( q= listp.head; q ; q = q->next)//�ҳ���صĵ�����listd 
	    	{
				if(!strcmp(q->doctor,doctor1)&&!strcmp(q->office,office)&&timeJudge(q->timeYear,q->timeMon,q->timeDay)>=0)
				{
					Addinput(&listd,q->user,q->name,q->timeYear,q->timeMon,q->timeDay,q->doctor,office,q->number,0);//�������� 
					f++;//��ȡ���ݸ��� 
				}
			}	
		}
		if(f == 0&&time == 1)
		{
			printf("\n\n\t\t\t\t��δ����ԤԼ��ľ���\n\n");
			system("PAUSE");
			return;
		}
		if(f == 0&&time == 0)
		{
			printf("\n\n\t\t\t\t��ȥ��δ�о�����Ϣ\n\n");
			system("PAUSE");
			return;
		}
		Formp *p = listd.head;
		Formp *b;
		Formp *k;
		int year,month,day;
		char name[30];
		for (i=0; i<f-1; i++) 
		{
			p = listd.head;
			year = p->next->timeYear;
			month = p->next->timeMon;
			day = p->next->timeDay;
        	for (p = listd.head;p;p = p->next) 
			{

			if (timecpy(year,month,day,p->timeYear,p->timeMon,p->timeDay)<=0)//�ﵥʱ�����򣬻�ȡСֵ
			{
				year = p->timeYear;
				month = p->timeMon;
				day = p->timeDay;
				strcpy(office,p->office);
				strcpy(doctor1,p->doctor);
				strcpy(name,p->name);
			}
        	}

		for (k = NULL, b = listd.head; b ;k = b,b = b->next)// �ͷ�Сֵ���� 
		{
			if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,doctor1)&&!strcmp(b->office,office)&&!strcmp(b->name,name))
			{
				if (k)
				{
					k->next = b->next;
				}
				else
				{
					listd.head = b->next;
				}
				free(b);
				break;
			}

		}
		printf("\t\t\t\tʱ�䣺%d��%d��%d��\n\t\t\t\t���ˣ�%s\n\n",year,month,day,name);
		
		}
		p = listd.head;
		printf("\t\t\t\tʱ�䣺%d��%d��%d��\n\t\t\t\t���ˣ�%s\n\n\n\n",p->timeYear,p->timeMon,p->timeDay,p->name);
		system("PAUSE");
		freeFormlistp(&listp);//�ͷ�����ռ� 
		freeFormlistp(&listd);//�ͷ�����ռ� 
	}
	
		
	
}
