int appointmentCheck(int year,int month,int day,char doctor[],char office[])// ����Ƿ�����س������ݣ������Ƿ���ԤԼ���� 
{
	Formlistp listd;
    listd.head =listd.tail = NULL;
	int flag = 0;
    inputnumR(1);
    ioRead_input(&listd,1);
	Formp *q;
    for ( q= listd.head; q ; q = q->next)
    {
        if(!strcmp(q->doctor,doctor)&&q->timeYear==year&&q->timeMon==month&&q->timeDay==day)
        {
            flag = 1;
            break;
        }
	}
	if(flag == 1)
	{
		q->number--;
		if(q->number < 0)
		{
			flag = 0;
			return flag;
		}
		ioWrite_input(&listd,1);
		inputnumW(1);
	}
	freeFormlistp(&listd);
	return flag;
}
