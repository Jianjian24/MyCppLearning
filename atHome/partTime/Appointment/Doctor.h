void Doctorway(void)//ҽ���˵Ľ��溯�� 
{
	//����Ҫ��ʾ�Ĳ˵� 
	char *menu2D[] = 
	{
	"�� ��¼(ҽ��) ��",
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
    	showmenu(hOut , menu2D , NR(menu2D) , index);
		ret = get_userinput(&index , NR(menu2D));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:         userLogin(1);  
					break ;  	//ҽ����¼ 
				
				case 1:          userAdd(1);
					break ;  	//ҽ��ע�� 
				
				case 2:          findPassword(1); 
					break ;  	//ҽ��Ѱ������ 
				
				case 3:			changPassword(1);
					break ;  	//ҽ���޸����� 
				
				case 4:           
					return  ;//������һ�� 
			}
		}
	}
    return ;
}
