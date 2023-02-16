#include <stdio.h>
#include <stdlib.h>
#include <cstring>
void enterNumber(void);
int Calculator(void);

int Sum, Max,Min;


int main()
{

    printf("%d\n%d\n%d",Sum,Max,Min);
    return 0;
}

void enterNumber(void)
 {   int i;//counter
     int string[100];
     FILE *fpw;
     fpw=fopen("UserNumber.txt","w+");
    if(fpw==NULL)
    {
        fputs("File error",stderr);
        exit(1);
    }
    printf("enter a series of numbers\n");
    while(scanf("%d",string)!=EOF)
   {
       for(i=0;i<strlen(string);i++)
    {
        scanf("%d\n",&string[i]);
        fprintf(fpw,"%d\n",string[i]);
    }
   }
    fclose(fpw);

 }
int Calculator(void)
   {
    int intarray[100];
    int i=0;
    FILE *fp;
    int rc;
    fp=fopen("UserNumber.txt","r");
    if(fp==NULL)
    {
        fputs("File error",stderr);
        exit(1);
    }
    while(1)
    {
        rc=fscanf(fp,"%d",&intarray[i]);
        if(rc<=0)
        break;
        i++;
    }

       //calculate Sum
             int Sum = 0;
            for (int i = 0; i <strlen(intaarray); i++)
        {
                Sum += intarray[i];
        }
            return Sum;


     //calculate max
        int Max=intarray[0];
        for(int j=0;j<strlen(intarray);j++)
        if (intarray[j] > Max)
        Max=intarray[j];
        return Max;


     //calculate min

       int Min=intarray[0];
       for(int k=0;k<strlen(intarray);k++)
         if (intarray[k] < Min)
         Min=intarray[k];
        return Min;

        fclose(fp);
   }
