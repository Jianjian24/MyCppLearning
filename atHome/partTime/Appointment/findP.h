void findP(char u[],char n[])//�鿴�ҵľ�����Ϣ
{
	//����Ҫ��ʾ�Ĳ˵� 
	char *menu5P[] = 
	{
	"��    ��ǰ��������    ��",
	"��    ����������    ��",
	"��   ������һ��   ��",
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
    	showmenu(hOut , menu5P , NR(menu5P) , index);
		ret = get_userinput(&index , NR(menu5P));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:         findMe(u,n,"office",0,0); 
					break ;  	//��ǰ���� 
				
				case 1:         findMe(u,n,"office",0,1);   
					break ;  	//������� 
					
				case 2:           
					return  ;//������һ�� 
			}
		}
	}
    return ;
}
