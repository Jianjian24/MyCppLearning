#include"stud.h"
void find()
	{
		int k,e,h;
		system("cls");
	    printf("\n\n");
	    printf("\t\t\t\t\t\t\t\t   ��ҵ����Ϣ����\n\n"); 
	    printf("\t\t\t\t\t\t *******************************************************\n\n\n");
	    printf("\t\t\t\t\t\t 1. ����ѧ�Ų��ұ�ҵ����Ϣ.\n\t\t\t\t\t\t 2. �����������ұ�ҵ����Ϣ.\n\t\t\t\t\t\t 3. ����QQ���ұ�ҵ����Ϣ.\n\t\t\t\t\t\t 4. ���ݵ绰���ұ�ҵ����Ϣ.\n");
	    printf("\n\n");
	    printf("\t\t\t\t\t\t *******************************************************\n\n\n");
	    printf("\t\t\t\t\t\t �������ִ����Ӧ����:");  
		scanf("%d",&k);
		switch(k)
		{
		case 1:find1();break;
        case 2:find2();break;
		case 3:find3();break;
		case 4:find4();break;
		default: e=1;
		}
		if(e==1) 
	{	 
		printf("\t\t\t\t\t\t ��������,�����������ѡ��.\n");	 
		h=getchar(); 	 
		 _getch(); 	 
		find(); 
	} 

}