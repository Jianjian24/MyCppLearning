void Addinput(Formlistp *pList,char u[],char n[],int year,int month,int day,char doctor[],char office[],int number,int order)
{
    //add to linked-list
    Formp *p = (Formp*)malloc(sizeof(Formp));//���˿ڹ��õĽ��������������������ĺ���������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
    if(order == 1)
    {
        strcpy(p->doctor,doctor);
    	strcpy(p->office,office);
        p->timeYear = year;
        p->timeMon = month;
        p->timeDay = day;
        p->number = number;
	}
    else
    {
        strcpy(p->user,u);
        strcpy(p->name,n);
        strcpy(p->doctor,doctor);
    	strcpy(p->office,office);
        p->timeYear = year;
        p->timeMon = month;
        p->timeDay = day;
    }
    
    p->next = NULL;
    //head��Ϊ�� 
    Formp *First = pList->head;
    if (First)
    {
        pList->tail->next = p;//�ӵ�β�� 
        pList->tail = pList->tail->next;
    }
    //headΪ�� 
    else
    {
        pList->head = pList->tail = p;
    }
    
}
