void findMe(char u[],char n[],char office[],int order,int time)//���˿ڹ��õ��Լ������ݲ鿴����������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1��time��0Ϊ��ȥ��1Ϊδ�� 
{
	system("cls");
	if (order == 1)
	{
		int f = 0,i = 0;
		Formlistp listp,listd;
		listp.head =listp.tail = NULL;
		listd.head =listd.tail = NULL;
		inputnumR(1);
		ioRead_input(&listp,1);
		printf("\n\n\t\t\t\t����ʱ���Ⱥ�����\n\n");
		Formp *q;
		if (time == 1)//�����ҵ���Ϣ 
		{
			for ( q= listp.head; q ; q = q->next)
			{
				if(!strcmp(q->office,office)&&!strcmp(q->doctor,n)&&timeJudge(q->timeYear,q->timeMon,q->timeDay)<=0)
				{
					Addinput(&listd,"k","k",q->timeYear,q->timeMon,q->timeDay,q->doctor,office,q->number,1);
					f++;
				}

			}
		}
		
		else
		{
			for ( q= listp.head; q ; q = q->next)
			{
				if(!strcmp(q->office,office)&&!strcmp(q->doctor,n)&&timeJudge(q->timeYear,q->timeMon,q->timeDay)>=0)
				{
					Addinput(&listd,"k","k",q->timeYear,q->timeMon,q->timeDay,q->doctor,office,q->number,1);
					f++;
				}
			}
		}
		if(f == 0)
		{
			printf("\n\n\t\t\t\t���ʱ��δ������\n\n");
			system("PAUSE");
			return;
		}
		
		Formp *b;
		Formp *k;
		int year,month,day;
		int number;
		Formp *p = listd.head;
		char doctor[30];
		for (i=0; i<f-1; i++) //������� 
		{
			p = listd.head;
			year = p->next->timeYear;
			month = p->next->timeMon;
			day = p->next->timeDay;
        	for (p = listd.head;p;p = p->next) 
			{

			if (timecpy(year,month,day,p->timeYear,p->timeMon,p->timeDay)<=0)
			{
				year = p->timeYear;
				month = p->timeMon;
				day = p->timeDay;
				strcpy(doctor,p->doctor);
				number = p->number;
			}
        	}
		
		for (k = NULL, b = listd.head; b ;k = b,b = b->next)
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
		printf("%s\n%s\nʱ�䣺%d��%d��%d��\nʣ��������%d\n\n",doctor,office,year,month,day,number);
		
		}
		p = listd.head; 
		printf("%s\n%s\nʱ�䣺%d��%d��%d��\nʣ��������%d\n\n",p->doctor,p->office,p->timeYear,p->timeMon,p->timeDay,p->number);//zuihoude*/
		system("PAUSE");
		freeFormlistp(&listp);
		freeFormlistp(&listd);
	}
	else
	{
		int f = 0,i = 0;
		Formlistp listp,listd;
		listp.head =listp.tail = NULL;
		listd.head =listd.tail = NULL;
		inputnumR(0);
		ioRead_input(&listp,0);
		printf("\n\n\t\t\t\t����ʱ���Ⱥ�����\n\n");
		Formp *q;
		if (time == 1)
		{
			for ( q= listp.head; q ; q = q->next)
			{
				if(!strcmp(q->user,u)&&!strcmp(q->name,n)&&timeJudge(q->timeYear,q->timeMon,q->timeDay)<=0)
				{
					Addinput(&listd,q->user,q->name,q->timeYear,q->timeMon,q->timeDay,q->doctor,q->office,q->number,0);
					f++;
				}
			}
		}
		else
		{
			for ( q= listp.head; q ; q = q->next)
			{
				if(!strcmp(q->user,u)&&!strcmp(q->name,n)&&timeJudge(q->timeYear,q->timeMon,q->timeDay)>=0)
				{
					Addinput(&listd,q->user,q->name,q->timeYear,q->timeMon,q->timeDay,q->doctor,q->office,q->number,0);
					f++;
				}
			}
		}
		if(f == 0)
		{
			printf("\n\n\t\t\t\t���ʱ��δ����ԤԼ��\n\n");
			system("PAUSE");
			return;
		}
		Formp *p = listd.head;
		Formp *b;
		Formp *k;
		int year,month,day;
		char name[30];
		char doctor1[30];
		char office1[30];
		for (i=0; i<f-1; i++) 
		{
			p = listd.head;
			year = p->next->timeYear;
			month = p->next->timeMon;
			day = p->next->timeDay;
        	for (p = listd.head;p;p = p->next) 
			{

			if (timecpy(year,month,day,p->timeYear,p->timeMon,p->timeDay)<=0)
			{
				year = p->timeYear;
				month = p->timeMon;
				day = p->timeDay;
				strcpy(office1,p->office);
				strcpy(doctor1,p->doctor);
			}
        	}

			for (k = NULL, b = listd.head; b ;k = b,b = b->next)
			{
				if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,doctor1)&&!strcmp(b->office,office1))
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
		
		printf("ʱ�䣺%d��%d��%d��\nҽ����%s\n���ң�%s\n\n",year,month,day,doctor1,office1);
		}
		p = listd.head;
		printf("ʱ�䣺%d��%d��%d��\nҽ����%s\n���ң�%s\n\n",p->timeYear,p->timeMon,p->timeDay,p->doctor,p->office);
		system("PAUSE");
		freeFormlistp(&listp);
		freeFormlistp(&listd);
	}
	
}
