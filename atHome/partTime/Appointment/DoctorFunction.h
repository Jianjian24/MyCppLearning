void DoctorFunction(char u[],char n[],char office[])//ҽ���˹���ģ�飬ͬʱ���ܴ�����˺š����������� 
{
	//����Ҫ��ʾ�Ĳ˵� 
	char *menu3D[] = 
	{
	"��    ���ų���    ��",
	"���鿴ԤԼ�ҵĲ��ˣ�",
	"���鿴�ҵĳ�����Ϣ��",
	"��    ȡ������    ��",
	"��    �޸ĳ���    ��",
	"��    ע���˺�    ��",
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
    	showmenu(hOut , menu3D , NR(menu3D) , index);
		ret = get_userinput(&index , NR(menu3D));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:         lnput(u,n,office,1);  
					break ;  	//���ų��� 
				
				case 1:         DoctorLook(u,n,office);   
					break ;  	//�鿴ԤԼ�ҵĲ��� 
				
				case 2:         findD(u,n,office); 
					break ;  	//�鿴�ҵĳ�����Ϣ
				
				case 3:			cancel(u,n,office,1);
					break ;  	//ȡ������ 
				
				case 4:			cancel(u,n,office,1);lnput(u,n,office,1);
					break ;  	//�޸ĳ�����Ϣ 
					
				case 5:			freeUser(1);
					break ;  	//�û�ע���Լ����˺� 
					
				case 6:           
					return;     //������һ�� 
			}
		}
	}
    return ;
}
