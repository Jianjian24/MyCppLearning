#ifndef _MENU_H_
#define _MENU_H_
#define  Program "��Ŀ:ҽԺԤԼ�Һ�ϵͳ"
#define  Author  "����:B20030401"
#define  Class   "�༶:�������ѧ�뼼��"
//����ṹ��
CONSOLE_CURSOR_INFO cci; 
//����Ĭ�ϵ�����λ��  	
COORD pos = {0,0};


//����ö��Keyboard�ļ�ֵ���� 
enum 
{
	UP = 72,
	DOWN = 80 ,
	LEFT = 75 ,
	RIGHT = 77 ,
	ENTER = 13 ,
	ESC = 27 ,
};

//��ʾ�˵� 
void showmenu(HANDLE hOut ,char **menu , int size , int index)
{
	int i ; 
	system("cls");	
	//������ʾ���ı�����ɫ 
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | 0x8); 
	//��ʼ������̨��ʾ��X,Y������� 
	pos.X = 30;
	pos.Y = 0 ;
	//������ʾ������̨�ն˵ľ���λ�� 
	SetConsoleCursorPosition(hOut,pos);    
	//����printf�ڿ���̨��Ӧ��λ������� 
	printf("%s",Program);
	pos.X = 30;
	pos.Y = 1 ;
	SetConsoleCursorPosition(hOut,pos);    
	printf("%s",Author);
	pos.X = 30;
	pos.Y = 2 ;
	SetConsoleCursorPosition(hOut,pos);    
	printf("%s",Class);
	for(i = 0 ; i < size ; i++)
	{
		//���i==index��ʾ�ڵ�ǰѡ���λ�ã�Ĭ�ϳ�ʼ����ʾ�ǵ�һ���ʾΪ��ɫ��
		//���������°���ѡ���ʱ�򣬹����ƶ���Ҳ�Ϳ������б�ѡ������� 
		if(i == index)
		{
			//��ɫ 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos.X = 30;
    		pos.Y = 5+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos);    
    		printf("%s",menu[i]);
		}
		//������ʾΪ��ɫ 
		else
		{
			//��ɫ 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos.X = 30;
    		pos.Y = 5+i;
    		//���ù������
    		SetConsoleCursorPosition(hOut,pos);    //���ù������
    		printf("%s",menu[i]);
		}
	}
	//ˢ�±�׼��������� 
	fflush(stdout);
}
 
//��ȡ�û�����Ľӿ� 
int  get_userinput(int *index , int size)
{
	int ch ;
	ch = getch();
	switch(ch)
	{
		//�� 
		//���ѡ���ϣ���ô��������ƶ� 
		case UP : if(*index > 0)  *index -= 1 ;  break; 
		//�� 
		//���ѡ���£���ô��������ƶ� 
		case DOWN :if(*index < size -1)  *index += 1 ;  break;
		//�� 
		case LEFT: 
		case 97:return 0 ;
		//�� 
		case RIGHT:return 0 ;
		//�س� 
		case ENTER: return ENTER ;
		//ESC
		case ESC: return ESC ;
	}
	return 0 ;
}
#endif
