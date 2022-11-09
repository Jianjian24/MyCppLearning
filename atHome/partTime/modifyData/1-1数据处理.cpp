#include "stdio.h"
#include "IOTXTl.h"
#include "stdlib.h"

int main()
{
	int k,m,n,q,j,rout;
	int b,d,i;
	int a,e,f,h;
	unsigned long int c;
	float data[2*N],num[N][2];
	FILE *fp;
	char filename[100],ch[20];
	int lampta[6]={1,2,3,4,5,6};
	int t_0[5]={1,2,3,4,5};
	int seta[6]={1,2,3,4,5,6};
	e=1;
	for(f=1;f<=1;f++)
	{
	for(a=0;a<=1;a++)
	{		
		j=0,k=0;m=0;n=0;q=0;
		sprintf(filename," 这里写你的文件名 ");
		// sprintf(filename,"D:\\abaqus\\blast-s\\%d-%d.txt",lampta[a],seta[f]);
		fp=fopen(filename,"r");			
		if(fp==NULL)
		{
			continue;
		}
	//	fscanf(fp,"%s",ch);
	//	printf("%s\n",ch);
		for(c=0;c<2*N;c++)
		{
			float tempnum;
			fscanf(fp,"%f",&tempnum);
			data[c]=tempnum;//���ݴ���data
		}
//		printf("data=%lf\n",data[1999]);
		for(b=0;b<2;b++)
		{
			for(d=0;d<N;d++)
			{
				num[d][b]=data[b+2*d];
			//	printf("%lf",num[d][b]);
			}
		}
		for(d=0;d<N;d++)
		{
			excel_x[d]=num[d][0];
			excel_y[d]=num[d][1];
		}
 //		printf("%lf\n%lf\n",excel_x[925],excel_y[925]);
 //   	fclose(fp);
		while(excel_y[k]<excel_y[k+1])
		{
			k++;
		}
		Wm[a]=excel_y[k];
		tsatm[a]=excel_x[k];
		q=k;
    	printf("���ֵ���=%d\n��󱥺�ʱ��=%lf\n��󱥺��Ӷ�=%lf\n",q,tsatm[a],Wm[a]);
		//printf("%d-%d.txt\t",lampta[a],seta[f]);
		//printf("%lf\t%lf\t",tsatm[a],Wm[a]);
		if(excel_y[N-1]>excel_y[N-2])
		{
			rout=1;
			for(k=N-1;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;
		} 
		else
		{
			rout=2;
			for(k=N-1;excel_y[k]<excel_y[k-1];)
				k--;
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;	
		}//�ҵ�������һ����ֵ
		m=k;
//		printf("�յ�ֵ���=%d\n�յ�ֵ=%lf\n",m,excel_x[m]);
		if(excel_y[N-1]>excel_y[N-2])
		{
			rout=1;
			for(k=N-1;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;
		}//������8����ֵ
		else
		{
			rout=2;
			for(k=N-1;excel_y[k]<excel_y[k-1];)
				k--;
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;			
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;			
			for(;excel_y[k]>excel_y[k-1];)
				k--;			
			for(;excel_y[k]<excel_y[k-1];)
				k--;			
			for(;excel_y[k]>excel_y[k-1];)
				k--;
			for(;excel_y[k]<excel_y[k-1];)
				k--;			
			for(;excel_y[k]>excel_y[k-1];)
				k--;			
			for(;excel_y[k]<excel_y[k-1];)
				k--;			
		}//������9����ֵ
		n=k;
//		printf("���ֵ���=%d\n���ֵ=%lf\nrout=%d\n",n,excel_x[n],rout);
		Wf[a]=0;
		for(j=n;j<=m;j++)
		{
			Wf[a]=Wf[a]+excel_y[j]/(m-n+1);
		}
		if(Wf[a]<=Wm[a])
		{
//		printf("q=%d\n",q);
			j=q+1;
			while(excel_y[j]>Wf[a])
			{
				j++;
			}
		}
		else
		{
			j=q+1;
			while(excel_y[j]<Wf[a])
			{
				j++;
			}		
		}
		h=j;
		tsatf[a]=excel_x[h];
  		printf("�����Ӷ����=%d\n�����Ӷȱ���ʱ��tsatf=%lf\nWf=%lf\n",h,tsatf[a],Wf[a]);
//		printf("%lf\t%lf\n",tsatf[a],Wf[a]);
//		printf("�������");
       WriteIntoTXT("file.txt",filename);
	}
	}
	printf("�������");
	system("pause");
	return 0;
}	

