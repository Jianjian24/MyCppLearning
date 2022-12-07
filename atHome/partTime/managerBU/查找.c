#include"stud.h"
void find()
	{
		int k,e,h;
		system("cls");
	    printf("\n\n");
	    printf("\t\t\t\t\t\t\t\t   毕业生信息查找\n\n"); 
	    printf("\t\t\t\t\t\t *******************************************************\n\n\n");
	    printf("\t\t\t\t\t\t 1. 根据学号查找毕业生信息.\n\t\t\t\t\t\t 2. 根据姓名查找毕业生信息.\n\t\t\t\t\t\t 3. 根据QQ查找毕业生信息.\n\t\t\t\t\t\t 4. 根据电话查找毕业生信息.\n");
	    printf("\n\n");
	    printf("\t\t\t\t\t\t *******************************************************\n\n\n");
	    printf("\t\t\t\t\t\t 输入序号执行相应功能:");  
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
		printf("\t\t\t\t\t\t 输入有误,按任意键重新选怿.\n");	 
		h=getchar(); 	 
		 _getch(); 	 
		find(); 
	} 

}