extern void findPassword(int order)//���˿ڹ��õ�����Ѱ�غ���������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1
{
    system("cls");
	List list;
    list.head =list.tail = NULL;
    char u[30],n[30],p[30];
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
    else
    {
    printf("\t\t\t\t���������������\n\n\t\t\t\t");
    scanf("%s",n);
    if(strcmp(q->name, n) != 0){
        printf("\t\t\t\t��������û����Ƿ������������ԣ�����\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
        printf("\n");
        return;
    }
    printf("\t\t\t\t��������֤�룺\n\n\t\t\t\t");
    srand((unsigned)time(NULL));//������������� 
    r = rand();
    printf("%d\n\n\t\t\t\t",r);
	scanf("%d",&y);
    if (r == y)
    {
        printf("\t\t\t\t��������ǣ�%s\n\n\t\t\t\t",q->password);
        system("PAUSE");
    }
    else
    {
        printf("\t\t\t\t��֤����������³���\n\n\t\t\t\t");
        system("PAUSE");
        system("cls");
    }
    freeList(&list);//�ͷ�����Ŀռ� 
	}
}
