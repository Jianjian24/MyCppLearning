void freeUser(int order)////���˿ڹ��õ��˺�ע������������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1 
{
    system("cls");
	List list;
    list.head =list.tail = NULL;
    char u[30],n[30],p[30];
    int r,y;
    int flag = 0;
    usernumR(order);
    ioRead(&list,order);
    printf("\n\n\t\t\t\t���ٴ�ȷ��������\n\t\t\t\t");
    printf("\n\t\t\t\t����������˺�\n\n\t\t\t\t");
    scanf("%s",u);
    Patient *q,*t;
    for ( t = NULL,q= list.head; q ; t = q,q = q->next)
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
    printf("\t\t\t\t���������룺\n\n\t\t\t\t");
    scanf("%s",p);
    if(strcmp(q->password, p) != 0){
        printf("\t\t\t\t������������ԣ�����\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
        printf("\n");
        return;
    }
    printf("\t\t\t\t��������֤�룺\n\n\t\t\t\t");
    srand((unsigned)time(NULL));
    r = rand();
    printf("%d\n\n\t\t\t ",r);
	scanf("%d",&y);
    if (r == y)
    {
        //freeUserList(&list,u,n,p);
            if (t)
            {
                t->next = q->next;
            }
            else
            {
                list.head = q->next;
            }
            free(q);
            printf("\t\t\t\tע���ɹ���\n\n\t\t\t\t");
        	system("PAUSE");
    }
    else
    {
        printf("\t\t\t\t��֤�����������\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
    }
    ioWrite(&list,order);
    usernumW(order);
    freeList(&list);
    
}
