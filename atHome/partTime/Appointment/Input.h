extern void lnput(char u[],char n[],char office[],int order)//���˿ڹ��õ�ԤԼ�������뺯��������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1�������û��������� 
{
	Formlistp listp;
    listp.head =listp.tail = NULL;
    int year,month,day,number;
    int flag = 0;
    char doctor[30];
    inputnumR(order);//�����ﵥ����������ȫ�ֱ��� 
    ioRead_input(&listp,order);//�����ļ��ﵥ���ݵ�����listp
    printf("\n\n\t\t\t\t��ʽʾ����2022��1��1�գ��ֱ���2022 1 1 ����\n\t\t\t\t");
    printf("\n\t\t\t\t�±߽����ꡢ�¡��ս�������\n\t\t\t");
    printf("\n\n\t\t\t\t���������\n\n\t\t\t\t");
    scanf("%d",&year);
    printf("\n\n\t\t\t\t�������·ݣ�\n\n\t\t\t\t");
    scanf("%d",&month);
    printf("\n\n\t\t\t\t���������ڣ�\n\n\t\t\t\t");
	scanf("%d",&day);
    if (order == 0)
    {
    printf("\n\n\t\t\t\t������ҽ��������\n\n\t\t\t\t");
    scanf("%s",doctor);
    }
    else
    {
        printf("\n\n\t\t\t\t�����뵱�����������\n\n\t\t\t\t");
        scanf("%d",&number);
        strcpy(doctor,n);
    }
    
    if (timeJudge(year,month,day) >= 0)//ʱ���ж� 
    {
        printf("\n\n\t\t\t\t�����ԣ��������ʱ��\n\n\t\t\t\t");
        system("PAUSE");
	    system("cls");
        return;
    }
    if(order == 0)
    {
    Formp *q;
    for ( q= listp.head; q ; q = q->next)
    {
        if(!strcmp(q->user,u)&&!strcmp(q->name,n)&&!strcmp(q->doctor,doctor)&&q->timeYear==year&&q->timeMon==month&&q->timeDay == day)
        {
            printf("\t\t\t\t����������ö�ʱ�䣡��\n\n\t\t\t\t");
            system("PAUSE");
            return ;
        }
        
    }
    } 
    if(order == 1)
    {
    Formp *q;
    for ( q= listp.head; q ; q = q->next)//дһ���ж��Ƿ��ظ�ԤԼ 
    {
        if(!strcmp(q->doctor,doctor)&&q->timeYear==year&&q->timeMon==month&&q->timeDay==day)
        {
            printf("\t\t\t\t����ע����ö�ʱ�䣡��\n\n\t\t\t\t");
            system("PAUSE");
            return ;
        }
    }
	}
	if(order == 0)
	{
		flag = appointmentCheck(year,month,day,doctor,office);// ����Ƿ�����س������ݣ������Ƿ���ԤԼ���� 
		if(flag == 0)
		{
			printf("\t\t\t\tû����صĳ������ݣ����������ˣ���������ȷ�ϣ���\n\n\t\t\t\t");
            system("PAUSE");
			return;	
		}
	}
    Addinput(&listp,u,n,year,month,day,doctor,office,number,order);//���������������������listp�� 
    ioWrite_input(&listp,order);//��������д���ļ� 
	inputnumW(order);//��������д���ļ� 
	freeFormlistp(&listp);//�ͷ����뵽�Ŀռ� 
	printf("\t\t\t\t����ɹ�����\n\n\t\t\t\t");
    system("PAUSE");
}

