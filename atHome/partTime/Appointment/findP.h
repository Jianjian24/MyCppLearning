void findP(char u[],char n[])//查看我的就诊信息
{
	//定义要显示的菜单 
	char *menu5P[] = 
	{
	"＊    以前就诊数据    ＊",
	"＊    今后就诊数据    ＊",
	"＊   返回上一级   ＊",
	};

    int i;
    int ret ;
    int index = 0 ;
    HANDLE hOut;
    SetConsoleTitleA(Program);
    //获取当前的句柄---设置为标准输出句柄 
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //获取光标信息
    GetConsoleCursorInfo(hOut, &cci); 
	//设置光标大小   
    cci.dwSize = 1; 
	//设置光标不可见 FALSE   
    cci.bVisible =  0; 
    //设置(应用)光标信息
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
					break ;  	//以前数据 
				
				case 1:         findMe(u,n,"office",0,1);   
					break ;  	//今后数据 
					
				case 2:           
					return  ;//返回上一级 
			}
		}
	}
    return ;
}
