void Patientway(void)//�û��˵Ľ��溯�� 
{
	//����Ҫ��ʾ�Ĳ˵� 
	char *menu2P[] = 
	{
	"�� ��¼(�û�) ��",
	"�� ���˺�ע�� ��",
	"��  �һ�����  ��",
	"��  �޸�����  ��",
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
    	showmenu(hOut , menu2P , NR(menu2P) , index);
		ret = get_userinput(&index , NR(menu2P));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:         userLogin(0);   
					break ;  	//�û���¼ 
				
				case 1:         userAdd(0);    
					break ;  	//�û�ע�� 
				
				case 2:         findPassword(0);  
					break ;  	//�û�Ѱ������ 
				
				case 3:			changPassword(0);
					break ;  	//�û��޸����� 
				
				case 4:           
					return  ;//������һ�� 
			}
		}
	}
    return ;
}
