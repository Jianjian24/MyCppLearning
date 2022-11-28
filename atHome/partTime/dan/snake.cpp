#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#define WIDTH 50
#define HEIGHT 50/*场地*/
int snake_l=4;
double v=100.0;
int x_s,y_s;
int x_0,y_0;
int dir[4][2]={//以相对位置表示方向
    {0,1},
    {1,0},
    {0,-1},
    {-1,0},
};
int dir_s=0;//用索引值的方式标记蛇的方向
int x_f,y_f;
int food[2];
char map[HEIGHT][WIDTH]={' '};
int snake_p[10][2]={-1};
//隐藏光标函数
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = FALSE;    
	cursor.dwSize = sizeof(cursor);    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}
void snake(){
    snake_p[0][0]=rand()%(45-snake_l);
    snake_p[0][1]=rand()%(45-snake_l);
    for(int i=1;i<snake_l;i++){
        snake_p[i][0]=snake_p[i-1][0]+1;//默认横蛇
        snake_p[i][1]=snake_p[0][1];
    }
    /*以下计算方向，可脑*/
    int xt,yt;
    xt=snake_p[0][0]-snake_p[1][0];
    yt=snake_p[0][1]-snake_p[1][1];
    for(int j=0;j<4;j++){
        if(dir[j][0]==xt&&dir[j][1]==yt)
        dir_s=j;
        break;
    }
}
void c_food(){
    x_f=rand()%46;/*控制生成范围 提高容错*/
    y_f=rand()%46;
    food[0]=x_f;
    food[1]=y_f;
    if(x_f<2||y_f<2){
        food[0]=x_f+2;
        food[1]=y_f+2;
    }
}
void map1(){
    int u=0,v=0;
    while(u<50){
        map[u][0]='*';
        map[u][49]='*';
        u++;
    }
    while(v<50){
        map[0][v]='*';
        map[49][v]='*';
        v++;
    }
}
void output(){
    HideCursor();
    for(x_s=0;x_s<50;x_s++){
        for(y_s=0;y_s<50;y_s++){
            bool ifsnake=false;
            bool iffood=false;
            for(int k=0;k<snake_l;k++){//找蛇
                if(x_s==snake_p[k][0]&&y_s==snake_p[k][1]){
                    ifsnake=true;
                    break;
                }
            }
            if(x_s==food[0]&&y_s==food[1]){
                printf("@");
            }
                else if(ifsnake){
                printf("%c",'+');
                }
                    else{
                    printf(" %c ",map[x_s][y_s]);
                    }
        }
        printf("\n");
    }
}

/*内联函数*/
inline bool failed(){
    for(int i=1;i<snake_l;i++){
        if((snake_p[0][0]==snake_p[i][0])&&(snake_p[0][1]==snake_p[i][1]))
        return true;
    }
    if(snake_p[0][0]<0||snake_p[0][0]>50||snake_p[0][1]<0||snake_p[0][1]>50){
    return true;
    }
    return false; 
}
inline bool refood(){
    if(food[0]==snake_p[0][0]&&food[1]==snake_p[0][1])
    return true;
    return false;
}
void direction(){//交互和裁判程序
    char tmp;
    while(1){
        if(!_kbhit()){
            int tx,ty,i;
            tx=snake_p[snake_l-1][0];
            ty=snake_p[snake_l-1][1];
            //刷新蛇位置
            for(i=snake_l-2;i>0;i--){
                snake_p[i+1][0]=snake_p[i][0];
                snake_p[i+1][1]=snake_p[i][1];
            }
            snake_p[0][0]=snake_p[1][0]+dir[dir_s][0];
            snake_p[0][1]=snake_p[1][1]+dir[dir_s][1];
            if(failed())
            {
                printf("GAMEOVER\n");
                break;
            }
            if(refood()){
                c_food();
                snake_l++;
                v*=0.99;
                snake_p[snake_l-1][0]=tx;
                snake_p[snake_l-1][1]=ty;
            }
        }
        else{
            tmp=getchar();
            switch(tmp){
                case 'w':dir_s=3;break;
                case 'a':dir_s=2;break;
                case 's':dir_s=1;break;
                case 'd':dir_s=0;break;
                default:
             getchar();
            }
        }
        COORD point={0,0};
        HANDLE HOutput =GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(HOutput ,point);
        output();
        Sleep(v);
    }
}
int main(void){
    //system("mode con: cols=80 lines=80");//修改控制台窗口大小
    printf("按任意键开始游戏：\n");
    getchar();
    srand((unsigned int)time(NULL));//随机刻种子
    map1();
    c_food();//食物
    snake();//蛇
    output();//生成地图，主要的子函数
    direction();//交互，蛇走
    return 0;
}
