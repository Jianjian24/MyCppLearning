extern void userAdd(int order)//���˿ڹ��õ�ע�ắ��������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1  
{
    if(order == 1)
	{
		int passw = 120120;//������Ķ��� 
		int pass;
		printf("\n\n\t\t\t\t������ҽԺ������\n\n\t\t\t\t");
		scanf("%d",&pass);
		if(passw != pass)
		{
			printf("\t\t\t\t��������ȷ�������룡��\n\n\t\t\t\t");
            system("PAUSE");
            return ;
		}
	}
	List list;
    list.head =list.tail = NULL;
    char u[30],n[30],p[30],c[30],o[30];
    usernumR(order);//�ļ������������Ķ�ȡ 
    ioRead(&list,order);//���ļ�д��������õ�����list�� 
    printf("\n\n\t\t\t\t����������˺�\n\n\t\t\t\t");
    scanf("%s",u);
    Patient *q;
    for ( q= list.head; q ; q = q->next)
    {
        if(strcmp(q->user,u) == 0)
        {
            printf("\t\t\t\t���˺��ѱ�ע�ᣬ���������룡��\n\n\t\t\t\t");
            system("PAUSE");
            return ;
        }
    }
    printf("\n\n\t\t\t\t���������������\n\n\t\t\t\t");
    scanf("%s",n);
    if(order == 1)
    {
	    printf("\n\n\t\t\t\t��������Ŀ��ң�\n\n\t\t\t\t");
		scanf("%s",o);
	}
    printf("\n\n\t\t\t\t���������루���볤�Ȳ�������ʮ���ַ�����\n\n\t\t\t\t");
    scanf("%s",c);
    printf("\n\n\t\t\t\t��������һ�����룺\n\n\t\t\t\t");
    scanf("%s",p);
    if(strcmp(p, c) != 0){
        printf("\n\n\t\t\t\t�������벻һ������������\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
        printf("\n");
        return;
    }   
    printf("\t\t\t\t����ɹ���\n\n\t\t\t\t");
    system("PAUSE");
    Add(&list,u,n,p,o,order);//Ϊ������������ 
    ioWrite(&list,order);//������list������д���ļ� 
	usernumW(order);//����������д���ļ� 
	freeList(&list);//�ͷ�����Ŀռ� 
}

