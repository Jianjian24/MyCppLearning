void cancel(char u[],char n[],char office[],int order)//���˿ڹ��õ�ȡ�������ԤԼ����������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
{
	system("cls");
	if (order == 1)
	{
		int f = 0;
		Formlistp listp,listd;
		listp.head =listp.tail = NULL;
		listd.head =listd.tail = NULL;
		int year,month,day;
		inputnumR(1);
		ioRead_input(&listp,1);
		Formp *k,*b;
		printf("\n\n\t\t\t\tע�⣺����ȡ������ҳ��\n\n");
		printf("\n\t\t\t\t�±߽����ꡢ�¡��ս�������\n");
		printf("\n\n\t\t\t\t���������\n\n\t\t\t\t");
		scanf("%d",&year);
		printf("\n\n\t\t\t\t�������·ݣ�\n\n\t\t\t\t");
		scanf("%d",&month);
		printf("\n\n\t\t\t\t���������ڣ�\n\n\t\t\t\t");
		scanf("%d",&day);
		if (timeJudge(year,month,day) >= 0)//ʱ���ж� 
	    {
	        printf("\n\n\t\t\t\t�����ԣ��������ʱ��\n\n\t\t\t\t");
	        system("PAUSE");
		    system("cls");
	        return;
	    }
		for (k = NULL, b = listp.head; b ;k = b,b = b->next)
			{
				if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,n)&&!strcmp(b->office,office))
				{
					f = 1;
					if (k)
					{
						k->next = b->next;
					}
					else
					{
						listp.head = b->next;
					}
					free(b);
					break;
				}

			}
		if (f == 0)
		{
			printf("\t\t\t\t��ʱ�β����ڣ���\n\n\t\t\t\t");
			system("PAUSE");
			return;
		}
		
		ioWrite_input(&listp,1);
		inputnumW(1);
		freeFormlistp(&listp);
		inputnumR(0);
		ioRead_input(&listd,0);
		for (k = NULL, b = listd.head; b ;k = b,b = b->next)
			{
				if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,n)&&!strcmp(b->office,office))
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
		ioWrite_input(&listd,0);
		inputnumW(0);
		freeFormlistp(&listd);
		printf("\t\t\t\tȡ���ɹ�����\n\n\t\t\t\t");
		system("PAUSE");
	}
	
	else
	{
		int f = 0;
		Formlistp listp,listd;
		listp.head =listp.tail = NULL;
		listd.head =listd.tail = NULL;
		int year,month,day;
		char doctor[30],office1[30];
		inputnumR(0);
		ioRead_input(&listp,0);
		Formp *k,*b;
		printf("\n\n\t\t\t\tע�⣺����ȡ������ҳ��\n\n");
		printf("\n\t\t\t\t�±߽����ꡢ�¡��ս�������\n");
		printf("\n\n\t\t\t\t���������\n\n\t\t\t\t");
		scanf("%d",&year);
		printf("\n\n\t\t\t\t�������·ݣ�\n\n\t\t\t\t");
		scanf("%d",&month);
		printf("\n\n\t\t\t\t���������ڣ�\n\n\t\t\t\t");
		scanf("%d",&day);
		printf("\n\n\t\t\t\t������ҽ��������\n\n\t\t\t\t");
		scanf("%s",&doctor);
		printf("\n\n\t\t\t\t��������ң�\n\n\t\t\t\t");
		scanf("%s",&office1);
		if (timeJudge(year,month,day) >= 0)//ʱ���ж� 
	    {
	        printf("\n\n\t\t\t\t�����ԣ��������ʱ��\n\n\t\t\t\t");
	        system("PAUSE");
		    system("cls");
	        return;
	    }
		for (k = NULL, b = listp.head; b ;k = b,b = b->next)
			{
				if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,doctor)&&!strcmp(b->office,office1)&&!strcmp(b->name,n)&&!strcmp(b->user,u))
				{
					f = 1;
					if (k)
					{
						k->next = b->next;
					}
					else
					{
						listp.head = b->next;
					}
					free(b);
					break;
				}

			}
		if (f == 0)
		{
			printf("\t\t\t\tδ��⵽��ԤԼ����鿴�Ƿ�������ȷ����\n\n\t\t\t");
			system("PAUSE");
			return;
		}
		
		ioWrite_input(&listp,0);
		inputnumW(0);
		freeFormlistp(&listp);
		inputnumR(1);
		ioRead_input(&listd,1);
		for ( b = listd.head; b ;b = b->next)
			{
				if (b->timeYear==year&&b->timeMon==month&&b->timeDay==day&&!strcmp(b->doctor,doctor)&&!strcmp(b->office,office1))
				{
					b->number++;
					break;
				}

			}
		ioWrite_input(&listd,1);
		inputnumW(1);
		freeFormlistp(&listd);
		printf("\t\t\t\tȡ���ɹ�����\n\n\t\t\t");
		system("PAUSE");
	}
	
}
