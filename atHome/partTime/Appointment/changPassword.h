extern void changPassword(int order)//���˿ڹ��õ�������ĺ���������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
{
    system("cls");
	List list;
    list.head =list.tail = NULL;
    char u[30],n[30],p[30],c[30];
    int r,y;
    int flag = 0;
    usernumR(order);//�ļ������������Ķ�ȡ 
    ioRead(&list,order);//���ļ�д��������õ�����list�� 
    printf("\n\n\t\t\t\t����������˺�\n\n\t\t\t\t");
    scanf("%s",u);
    Patient *q;
    for ( q= list.head; q ; q = q->next)
    {
        if(strcmp(q->user,u) == 0)
        {
        	flag = 1;
            break;
        }
    }
    if(!flag)
    {
        printf("\n\t\t\t\t��δע�ᣬ��ע�����ʹ�ã�����\t\t\t\t");
        system("PAUSE");
        return ;
    }
    printf("\t\t\t\t������ԭ���룺\n\n\t\t\t\t");
    scanf("%s",p);
    if(strcmp(q->password, p) != 0){
        printf("\t\t\t\t������������ԣ�����\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
        printf("\n");
        return;
    }
    printf("\n\n\t\t\t\t��������ĺ�����루���볤�Ȳ�������ʮ���ַ�����\n\n\t\t\t\t");
    scanf("%s",c);
    printf("\n\n\t\t\t\t���ٴ�������ĺ�����룺\n\n\t\t\t\t");
    scanf("%s",p);
    if(strcmp(p, c) != 0){
        printf("\n\n\t\t\t\t�������벻һ������������\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
        printf("\n");
        return;
    }
    printf("\t\t\t\t��������֤�룺\n\n\t\t\t\t");
    srand((unsigned)time(NULL));//��������ӵ����� 
    r = rand();
    printf("%d\n\n\t\t\t\t",r);
	scanf("%d",&y);
    if (r == y)
    {
        strcpy(q->password,p);
        printf("\t\t\t\t������ĳɹ���\n\n\t\t\t\t");
        system("PAUSE");
    }
    else
    {
        printf("\t\t\t\t��֤����������µ�¼\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
    }
    ioWrite(&list,order);////������listд���ļ���  
    freeList(&list);//�ͷ�����list�Ŀռ�
}
