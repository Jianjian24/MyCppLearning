void PatientFunction(char u[],char n[])//�û��˹���ģ�飬ͬʱ���ܴ�����˺š�����
{
	//����Ҫ��ʾ�Ĳ˵� 
	char *menu3P[] = 
	{
	"��  ԤԼ�Һ�  ��",
	"�� �鿴ԤԼ�� ��",
	"��  ȡ��ԤԼ  ��",
	"��  �޸�ԤԼ  ��",
	"��  ע���˺�  ��",
	"�� ������һ�� ��",
	};

    int i;
    int ret ;
    int index = 0 ;
    HANDLE hOut;
    SetConsoleTitleA(Program);
    //��ȡ��ǰ�ľ��---����Ϊ��׼������ 
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //��ȡ�����Ϣ
    GetConsoleCursorInfo(hOut, &cci); 
	//���ù���С   
    cci.dwSize = 1; 
	//���ù�겻�ɼ� FALSE   
    cci.bVisible =  0; 
    //����(Ӧ��)�����Ϣ
    SetConsoleCursorInfo(hOut, &cci);   
    while(1)
    {
    	showmenu(hOut , menu3P , NR(menu3P) , index);
		ret = get_userinput(&index , NR(menu3P));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:         look(u,n);
					break;		//ԤԼ�Һ� 
				
				case 1:         findP(u,n);  
					break ;  	//�û��鿴�Լ���ԤԼ��Ϣ 
				
				case 2:			cancel(u,n,"office",0);
					break ;  	//�û�ȡ���Լ���ԤԼ 
				
				case 3:			cancel(u,n,"office",0);look(u,n);
					break ;  	//�޸�ԤԼ��Ϣ
					
				case 4:			freeUser(0);
					break ;  	//�û�ע���Լ����˺� 
					
				case 5:           
					return;     //������һ�� 
			}
		}
	}
    return ;
}
