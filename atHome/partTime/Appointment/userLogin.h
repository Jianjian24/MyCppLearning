#include <sys/time.h>

extern void userLogin(int order)//���˿ڹ��õĵ�¼����������orderΪ�ж�ҽ�����û������� ���û�Ϊ0��ҽ��Ϊ1 
{
   	system("cls");
	List list;
    list.head =list.tail = NULL;
    char u[30],n[30],p[30],office[30];
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
    if(!flag)//���ñ���ж��Ƿ�����Ӧ�˺� 
	{
		printf("\n\t\t\t\t��δע�ᣬ��ע�����ʹ�ã�����\t\t\t\t");
            system("PAUSE");
            return ;
	}
    else
	{
	    printf("\t\t\t\t���������룺\n\n\t\t\t\t");
	    scanf("%s",p);
	    if(strcmp(q->password, p) != 0)
		{
	        printf("\t\t\t\t������������ԣ�����\n\n\t\t\t\t");
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
	    	if(order == 1)
	    	{
	    		strcpy(n,q->name);
	    		strcpy(office,q->office);
	    		DoctorFunction(u,n,office); //����ҽ�����ܺ��� 
			}
			else
			{
				strcpy(n,q->name);
				PatientFunction(u,n);//�����û����ܺ��� 
			}
	    }
	    else
	    {
			printf("\t\t\t\t��֤����������µ�¼\n\n\t\t\t\t");
	        system("PAUSE");
	        system("cls");
	    }
	    freeList(&list);//�ͷ���������Ŀռ� 
	    }
}

