void Add(List *pList,char number[],char number1[],char number2[],char number3[],int order)//���˿ڹ��õ�������������������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
{
    //����ռ� 
    Patient *p = (Patient*)malloc(sizeof(Patient));
    strcpy(p->password,number2);
    strcpy(p->name,number1);
    strcpy(p->user,number);
    if(order == 1)
    {
    	strcpy(p->office,number3);
	}
    p->next = NULL;
    //�ж�head�Ƿ�Ϊ�� 
    Patient *First = pList->head;
    if (First)
    {
        pList->tail->next = p;//����tail->next 
        pList->tail = pList->tail->next;
    }
    //headΪ�� 
    else
    {
        pList->head = pList->tail = p;//����head 
    }
    
}
