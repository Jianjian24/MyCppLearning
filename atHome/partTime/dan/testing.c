#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

extern int n;

typedef struct project
{
	double dur, upcost, rate, TI, FB, FC, NPV;
    double cf[255],amount[255], PV[255];//, amount[255];
    char pn;
}project;
	project pros[255];

void readArray(float cf[], double dur, double q, char pn, char upcost, char rate)
{
    
    for (int j = 0; j < n ; j++)
    {
        printf("Enter the name of the project:\n");
        scanf("%s",&pros[j].pn);
        printf("Enter the upfront cost for project %s:\n",pn);
        scanf("%lf",&pros[j].upcost);
        printf("Enter rate of return or discount rate:\n");
        scanf("%lf",&pros[j].rate);
        printf("Enter the duration(in years):\n");
        scanf("%s",&pros[j].dur);
        for(int i = 0; i < pros[j].dur; i++)
        {
            double q = 0 ;
            printf("Cash flows for year %d :\n", i+1);
            scanf("%lf",&q);
            pros[j].cf[i] = q;
        }
        printf("\n");
    }
}

void writing(double cf[], char dur, double q, char pn, char upcost, char rate)
{
    for (int j = 0; j < n ; j++)
    {
        printf("Enter the name of the project: %s \n", pros[j].pn);
        printf("Enter the upfront cost for project Mars: %f \n", pros[j].upcost);
        printf("Enter rate of return or discount rate: %f \n", pros[j].rate);
        printf("Enter the duration(in years): %s \n", pros[j].dur);
        for(int i = 0; i < pros[j].dur; i++)
        {
            printf("Enter the cash inflow-outflows during year %d: %f\n", i+1, pros[j].cf[i]);
        }
    }
}

void writeArray(double cf[], double PV[], char pn, double amount[], char upcost, char rate)
{
    for (int j = 0; j < n ; j++)
    {
        pros[j].TI=0, pros[j].FB=0, pros[j].FC=0, pros[j].NPV=0;
        printf("\t\t\t\t\t\t%s\n",pros[j].pn);
        printf("---------------------------------------\n");
        printf("Year\t\t|\tCash\t\t|PV Factor\t\t|Amount\n");
        printf("\t\t|\tInflows/Outflows\t\t|\n");
        printf("---------------------------------------\n");
        for(int i = 0; i < pros[j].dur; i++)
        {
            pros[j].PV[i] = 1/pow(1+pros[j].rate/100, i+1);
            pros[j].amount[i] = pros[j].cf[i]*pros[j].PV[i];
            printf("%d\t\t|\t%f\t\t|%f\t\t|%lf", i+1, pros[j].cf[i], pros[j].PV[i], pros[j].amount[i]);
            pros[j].TI = pros[j].TI + pros[j].cf[i];
            pros[j].FB = pros[j].FB + pros[j].amount[i];
            pros[j].FC = pros[j].upcost;
            pros[j].NPV = pros[j].FB - pros[j].FC;
        }
        // printf("---------------------------------------\n");
        printf("Total Income: $%2.f",pros[j].TI);
        printf("Present Value of Future Benefits: $%2.f",pros[j].FB);
        printf("Present Value of Future Costs: $%2.f",pros[j].FC);
        printf("Net Present Value: $%2.f",pros[j].NPV);
    }
}

void Maxincome(){                 
    int r=1;
    for(int j = 0; j < n ; j++)
    {
        if(pros[j].TI=pros[j+1].TI){
            continue;
        }
        else{
            r = 0;
            break;
        }
    }
    if( r = 0 )
    {    
        int i,j,temp;
        double com[255];
        com[i] = pros[j].TI;             
        for(i=1;i<=sizeof(pros[j].TI)/sizeof(double)-1;i++)          /*i代表排序轮数，总轮数=元素个数-1*/
        {
            for(j=0;j<sizeof(pros[j].TI)/sizeof(double)-i;j++)       /*j代表每轮排序次数，次数=个数-轮数-1，但j初值为0*/
            {
                if(com[i]<com[i+1])   /*如果前一项比后一项大，则两项的值互换*/
                {
                    temp=com[i];
                    com[i]=com[i+1];
                    com[i+1]=temp;
                }
            }
        }
        for(j=0;j<=sizeof(pros[j].TI)/sizeof(double);j++)
        {
            if(pros[j].TI==com[0]){
                printf("%s",pros[j].pn);
                break;
            }
            else{
                continue;
            }
        }
    }
    else
    {
        int i,j,temp;                     /*temp为数值交换时使用的临时变量*/
        double com[255];
        com[i] = pros[j].NPV;
        for(i=1;i<=sizeof(pros[j].NPV)/sizeof(double)-1;i++)          /*i代表排序轮数，总轮数=元素个数-1*/
        {
            for(j=0;j<sizeof(pros[j].NPV)/sizeof(double)-i;j++)       /*j代表每轮排序次数，次数=个数-轮数-1，但j初值为0*/
            {
                if(com[i]<com[i+1])   /*如果前一项比后一项大，则两项的值互换*/
                {
                    temp=com[i];
                    com[i]=com[i+1];
                    com[i+1]=temp;
                }
            }
        }
        for(j=0;j<=sizeof(pros[j].NPV)/sizeof(double);j++)
        {
            if(pros[j].NPV==com[0]){
                printf("%s",pros[j].pn);
                break;
            }
            else{
                continue;
            }
        }
    }
} 

void H_NPV(){                 
    int r=1;
    for(int j = 0; j < n ; j++)
    {
        if(pros[j].NPV=pros[j+1].NPV){
            continue;
        }
        else{
            r = 0;
            break;
        }
    }
    if( r = 0 )
    {    
        int i,j,temp;                     /*temp为数值交换时使用的临时变量*/
        double com[255];
        com[i] = pros[j].NPV;
        for(i=1;i<=sizeof(pros[j].NPV)/sizeof(double)-1;i++)          /*i代表排序轮数，总轮数=元素个数-1*/
        {
            for(j=0;j<sizeof(pros[j].NPV)/sizeof(double)-i;j++)       /*j代表每轮排序次数，次数=个数-轮数-1，但j初值为0*/
            {
                if(com[i]<com[i+1])   /*如果前一项比后一项大，则两项的值互换*/
                {
                    temp=com[i];
                    com[i]=com[i+1];
                    com[i+1]=temp;
                }
            }
        }
        for(j=0;j<=sizeof(pros[j].NPV)/sizeof(double);j++)
        {
            if(pros[j].NPV==com[0]){
                printf("%s",pros[j].pn);
                break;
            }
            else{
                continue;
            }
        }
    }
    else
    {
        int i,j,temp;
        double com[255];
        com[i] = pros[j].TI;             
        for(i=1;i<=sizeof(pros[j].TI)/sizeof(double)-1;i++)          /*i代表排序轮数，总轮数=元素个数-1*/
        {
            for(j=0;j<sizeof(pros[j].TI)/sizeof(double)-i;j++)       /*j代表每轮排序次数，次数=个数-轮数-1，但j初值为0*/
            {
                if(com[i]<com[i+1])   /*如果前一项比后一项大，则两项的值互换*/
                {
                    temp=com[i];
                    com[i]=com[i+1];
                    com[i+1]=temp;
                }
            }
        }
        for(j=0;j<=sizeof(pros[j].TI)/sizeof(double);j++)
        {
            if(pros[j].TI==com[0]){
                printf("%s",pros[j].pn);
                break;
            }
            else{
                continue;
            }
        }
    }
} 

int main(){
    printf("Enter the number of projects:\n");
    scanf("%d",&n);
    printf("Enter the number of projects: %d\n", n);
    readArray(pros[255].cf[255], pros[255].dur, pros[255].pn, pros[255].upcost, pros[255].rate, q);
    writing(pros[255].cf[255], pros[255].dur, q, pros[255].pn, pros[255].upcost, pros[255].rate);
    writeArray(pros[255].cf[255], pros[255].PV[255], pros[255].pn, pros[255].amount[255], pros[255].upcost, pros[255].rate);
    Maxincome();
    H_NPV();
}




