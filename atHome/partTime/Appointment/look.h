void look(char u[],char n[])//�û��˹���ģ�飬�鿴ԤԼ�Ŀ��ҵ�ҽ���Ϳ�Լ�� 
{
	//����Ҫ��ʾ�Ĳ˵� 
	char *menu4P1[] = 
	{
	"��      �ڿ�      ��",
	"��      ���      ��",
	"��      ����      ��",
	"��      ����      ��",
	"��     ��ҽ��     ��",
	"��  �۶����ʺ��  ��",
	"��     ��ǻ��     ��",
	"��   ����������   ��",
	"��     �����     ��",
	"��     �����     ��",
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
    	showmenu(hOut , menu4P1 , NR(menu4P1) , index);
		ret = get_userinput(&index , NR(menu4P1));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:         otherLook(u,n,"l","�ڿ�",0,1);
					break ;  	
				
				case 1:         otherLook(u,n,"l","���",0,1);
					break ;  	
				
				case 2:         otherLook(u,n,"l","����",0,1); 
					break ;  	
				
				case 3:			otherLook(u,n,"l","����",0,1);
					break ;  	
					
				case 4:			otherLook(u,n,"l","��ҽ��",0,1);
					break ;  	
					
				case 5:			otherLook(u,n,"l","�۶����ʺ��",0,1);
					break ;  	
				
				case 6:			otherLook(u,n,"l","��ǻ��",0,1);
					break ;  	
					
				case 7:			otherLook(u,n,"l","����������",0,1);
					break ;  	
					
				case 8:			otherLook(u,n,"l","�����",0,1);
					break ;  	
					
				case 9:			otherLook(u,n,"l","�����",0,1);
					break ;  	
				
				case 10:           
					return  ;//������һ�� 
			}
		}
	}
    return ;
}
