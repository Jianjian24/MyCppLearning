void DoctorLook(char u[],char n[],char office[])//�鿴�ҵĳ�����Ϣ
{
	//����Ҫ��ʾ�Ĳ˵� 
	char *menu5D[] = 
	{
	"��    ��ǰԤԼ����    ��",
	"��    ���ԤԼ����    ��",
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
    	showmenu(hOut , menu5D , NR(menu5D) , index);
		ret = get_userinput(&index , NR(menu5D));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:         otherLook(u,n,n,office,1,0); 
					break ;  	//��ǰ���� 
				
				case 1:         otherLook(u,n,n,office,1,1);   
					break ;  	//������� 
					
				case 2:           
					return  ;//������һ�� 
			}
		}
	}
    return ;
}
