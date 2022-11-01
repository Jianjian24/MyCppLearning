#include "stdio.h"
#include "stdlib.h"
#include "extern.h"
#include "conio.h"
#include "string.h"
#include "Windows.h"
#include "time.h"
#include "menu.h"
#define   NR(x)   (sizeof(x)/sizeof(x[0]+0))
#include "Doctor.h"
#include "Patient.h"
#include "PatientFunction.h"
#include "DoctorFunction.h" 
#include "ioRead.h"
#include "ioWrite.h"
#include "Add.h"
#include "userAdd.h"
#include "freeList.h"
#include "usernumR.h"
#include "usernumW.h"
#include "userLogin.h"
#include "findPassword.h"
#include "changPassword.h"
#include "freeUser.h"
#include "Input.h"
#include "inputnumR.h"
#include "ioRead_input.h"
#include "timeJudge.h"
#include "Addinput.h"
#include "ioWrite_input.h"
#include "inputnumW.h"
#include "freeFormlistp.h"
#include "appointmentCheck.h"
#include "otherLook.h"
#include "look.h"
#include "timecpy.h"
#include "findP.h"
#include "findD.h"
#include "findMe.h"
#include "cancel.h"
#include "DoctorLook.h"
#include "illustrate.h"

//���������� 
int main()
{
	//����Ҫ��ʾ�Ĳ˵� 
	char *menu1[] = 
	{
	"��   ҽ����   ��",
	"��   �û���   ��",
	"��  ʹ���ֲ�  ��",
	"��    �˳�    ��",
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
    	showmenu(hOut , menu1 , NR(menu1) , index);
		ret = get_userinput(&index , NR(menu1));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:   Doctorway();      
					break ;  	//ҽ��ͨ�� 
				
				case 1:   Patientway();        
					break ;  	//����ͨ�� 
					
				case 2:   illustrate();        
					break ;  	//ʹ���ֲ� 
								
				case 3:           
					return 0 ;//�˳�ϵͳ 
			}
		}
	}
    return 0;
}

 
