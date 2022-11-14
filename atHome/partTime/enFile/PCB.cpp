#include <stdio.h>
#include <stdlib.h>
struct PCB
{
    int pid;//进程标识符
    int rr;//已运行时间
    int time;//进程要求运行时间
    char sta;//进程的状态
    struct PCB *next;//链接指针
};
struct PCB pcb1,pcb2,pcb3,pcb4,pcb5,*tail,*head,*rp;
void init()//初始化各个进程的运行时间
{
    int time;
    pcb1.pid = 1;
    pcb2.pid = 2;
    pcb3.pid = 3;
    pcb4.pid = 4;
    pcb5.pid = 5;
    pcb1.rr =pcb2.rr =pcb3.rr =pcb4.rr =pcb5.rr = 0;
    pcb1.sta = pcb2.sta = pcb3.sta = pcb4.sta = pcb5.sta = 'w';
    printf("请输入进程p1需要运行的时间:");
    scanf("%d",&time);
    pcb1.time =time;
    printf("请输入进程p2需要运行的时间:");
    scanf("%d",&time);
    pcb2.time=time;
    printf("请输入进程p3需要运行的时间:");
    scanf("%d",&time);
    pcb3.time=time;
    printf("请输入进程p4需要运行的时间:");
    scanf("%d",&time);
    pcb4.time =time;
    printf("请输入进程p5需要运行的时间:");
    scanf("%d",&time);
    pcb5.time=time;
    pcb1.next=&pcb2;
    pcb2.next=&pcb3;
    pcb3.next=&pcb4;
    pcb4.next=&pcb5;
    pcb5.next=&pcb1;
    head=&pcb1;
    tail=&pcb5;
}
void printf1()//显示表头
{
    printf("+---------------|---------------|---------------|---------------+\n");
    printf("|\tpid\t|\trr\t|\ttime\t|\tSTA\t|\n");
    printf("|---------------|---------------|---------------|---------------|\n");
}
void printf2()//显示各个进程的初始状态
{
    printf("processes p%d running\n",head->pid);
    printf1();
    printf("|\t%d\t|\t%d\t|\t%d\t|\t%c\t|\n",head->pid,head->rr,head->time,head->sta);
    printf("|---------------|---------------|---------------|---------------|\n");
    rp=head;
    while(rp!=tail)
    {
        rp=rp->next;
        printf("|\t%d\t|\t%d\t|\t%d\t|\t%c\t|\n",rp->pid,rp->rr,rp->time,rp->sta);
        printf("|---------------|---------------|---------------|---------------|\n");
    }
}
void operation()//运行
{
    int flag=1;
    while(flag<=5)
    {
        head->rr++;
        if((head->rr==head->time)||(head->time==0))
        {
            tail->sta='w';//将进程状态设置为等待态
            head->sta='f';//将进程状态设置为执行态
            printf2();
            head=head->next;
            tail->next=head;
            flag++;
        }
        else
        {
            tail->sta='w';//将进程状态设置为等待态
            head->sta='r';//将进程状态设置为就绪态
            printf2();
            tail=head;
            head=head->next;
        }
    }
}
int main()
{
    init();
    printf2();
    operation();

    return 0;
}
