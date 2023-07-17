#include <stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include "conio.h"
#define USER_LEN sizeof(USER)
#define BOOK_LEN sizeof(BOOK)
typedef struct user/*用户*/
{char num[12];/*号码*/
 char name[30];/*姓名*/
 struct user *next;
}USER;
typedef struct book/*书籍*/
{char nam[30];/*名字*/
 char editor[30];/*作者*/
 int amount;/*数量*/
 int tag1;/*库存标记*/
 int tag2;/*数量是否足够标记*/
 struct book *next;
}BOOK;
char first_menu();/*顶层菜单*/
USER *user_input();/*用户信息输入(完成)*/
BOOK *input_book_list();/*输入图书信息*/
void books_list_save(BOOK *head_book,char filename[]);/*以用户名为文件名存储书籍信息*/
void print_fetch(USER *head_user);/*显示领书单*/
char user_menu();/*教师学生菜单*/
char buyer_menu();/*采购员菜单*/
char issuer_menu();/*发行人员菜单*/
void dispose_buy_list();/*处理订购单*/
BOOK *load(char filename[]);/*打开存储书籍的文件*/
USER *load_user_record(char filename[]);/*打开存储用户信息的文件*/
void print_book_list(BOOK *head_book);/*显示书单(总共20行)*/
BOOK *obliterate(BOOK *head_book);/*删除*/
void save_user_record(USER*head);
void create_file(char filename[]);/*创建空文件（为了以后的追加做准备）*/
void add_to_store(BOOK*new_adding);/*加到库存*/
void print_user_record(USER*head_user);/*打印用户记录*/
int cmp_store(BOOK *head_store,BOOK *head_book);/*检查库存是否存在该书籍*/
void return_list();/*返回领书单*/
void delete_file(char filename[]);/*删除文件*/
void check_about_lack(BOOK *head_book);/*登记入缺书表*/
void week_day();/*显示星期*/
BOOK *together(BOOK *head_book);/*归并相同的名称书籍的数量*/
int check_amount(char input[]);/*检查输入的数字是否合法*/
int amount_do(char input[5]);

/*主要模块*/
void about_system();/*系统备注*/
char quit();/*退出确定*/
void tcher_stu_do();/*教师和学生模块*/
void buyer();/*采购员模块*/
void issuer();/*发行人员模块*/
void main()
{system("color 2f");
 if(fopen("d:\\all_user.txt","r")==NULL)create_file("all_user");
 printf("\n\n\n\n\n                            欢迎进入学校教材订购系统!!!\n\n");
 printf("                                  按任意键继续                         ");
 getch();
 for(;;)
 switch(first_menu())
     {case '0':switch(quit()){case'1':about_system();exit(0);break;
                              case'0':break;
                             }
               break;
      case '1':tcher_stu_do();break;
      case '2':buyer();break;
      case '3':issuer();break;
     }
}
char first_menu()/*顶层菜单*/
{char n;
 system("cls");/*刷屏*/ 
 printf("         |*************************************************************|\n");
 printf("         |=============================================================|\n");
 printf("         |                        (按 '0' 退出，)                      |\n");
 printf("         |===========================MENU==============================|\n");
 printf("         |   请根据选择输入您的身份                                    |\n");
 printf("         |                1.教师或学生                                 |\n");
 printf("         |                2.采购人员                                   |\n");
 printf("         |                3.发行人员                                   |\n");
 printf("         |                                                             |\n");
 printf("         |                                                             |\n");
 printf("         |*************************************************************|\n");
 printf("\n\t\t\t您的选择是(1-3):");
 scanf("%s",&n);
 return(n);
}

USER *user_input()/*用户信息输入(完成)*/
{
 USER *p,*head=NULL;
 p=(USER *)malloc(USER_LEN);
 if(!p)
      {printf("\nOut of memory.");
       return (head);
      } 
 system("cls");/*刷屏*/
 printf("         |*************************************************************|\n");
 printf("         |=============================================================|\n");
 printf("         |                        (按 '0' 退出，)                      |\n");
 printf("         |===========================MENU==============================|\n");
 printf("\n\n\n");
 printf("                               姓名:");
 scanf("%s",&p->name);
 if(p->name[0]=='0') return(NULL);
 while(strlen(p->name)>28)
 {system("cls");
  printf("您输入的姓名过长，请重新输入，不要超过28个字符");
  getch();
  system("cls");/*刷屏*/
 printf("         |*************************************************************|\n");
 printf("         |=============================================================|\n");
 printf("         |                        (按 '0' 退出，)                      |\n");
 printf("         |===========================MENU==============================|\n");
 printf("\n\n\n");
  printf("                             姓名:");
  scanf("%s",&p->name);
  if(p->name[0]=='0') return(NULL);
 }
 printf("\n");
 printf("                               号码:");
 scanf("%s",&p->num);
 if(p->num[0]=='0') return(NULL);
 while(strlen(p->num)>7)
 {system("cls");
  printf("您的号码过长请重新输入");
  getch();
  system("cls");
  printf("         |*************************************************************|\n");
  printf("         |=============================================================|\n");
  printf("         |                        (按 '0' 退出，)                      |\n");
  printf("         |===========================MENU==============================|\n");
  printf("\n\n\n");
  printf("                           姓名:%s",p->name);
  printf("\n\n");
  printf("                           号码:");
  scanf("%s",&p->num);
  if(p->num[0]=='0') return(NULL);
 }
 p->next=NULL;
 head=p;
 return head;
} 
                                           
BOOK *input_book_list(BOOK*head)/*输入图书信息*/
{BOOK *p1,*p2;
 char input[50];
 system("cls");
 printf("                           输入书籍的信息      \n\n");
 printf("                如果你知道该图书的主编则输入其姓名，否则输入'0' \n\n");
 printf("                              (按'0' 返回)                            \n\n\n\n");
 if(head!=NULL) {
 		head=p1=p2=(BOOK *)malloc(BOOK_LEN);/*输入第一个结点*/

     do
	 {printf("书名:");/*输入书名*/
	  //scanf("%s",&head->nam);
	  scanf("%s",&head->nam);
      if(head->nam[0]=='0'){return(NULL);}
	  if(strlen(head->nam)>28)printf("输入长度不能大于28个字符,请重新输入\n");
     }while(strlen(head->nam)>28);
	  do
	 {printf("主编:");/*输入主编者名字*/
      scanf("%s",&head->editor);
      if(head->editor[0]=='0')strcpy(head->editor,"UNKNWON");
	  if(strlen(head->editor)>28)printf("输入长度不能大于28个字符，请重新输入\n");
     }while(strlen(head->editor)>28);
	  do
	 {printf("数量:");
      scanf("%s",&input);
	  if(strlen(input)>3)printf("输入不能多于3位,请重新输入\n");
     }while(strlen(input)>3||check_amount(input));
	  head->amount=amount_do(input);/*将字符转成整型*/
      head->tag1=0;
      head->tag2=0;
      head->next=NULL;
  for(;;)/*输入后续的结点*/
      {
       p2=(BOOK *)malloc(BOOK_LEN);
       do
	 {printf("书名:");/*输入书名*/
	  scanf("%s",&p2->nam);
      if(p2->nam[0]=='0')return(head);
	  if(strlen(p2->nam)>28)printf("输入长度不能大于28个字符,请重新输入\n");
     }while(strlen(p2->nam)>28);
	  do
	 {printf("主编:");/*输入主编者名字*/
      scanf("%s",&p2->editor);
      if(p2->editor[0]=='0')strcpy(p2->editor,"UNKNWON");
	  if(strlen(p2->editor)>28)printf("输入长度不能大于28个字符,请重新输入\n");
     }while(strlen(p2->editor)>28);
	  do
	 {printf("数量:");
      scanf("%s",&input);
	  if(strlen(input)>3)printf("输入不能多于3位,请重新输入\n");
     }while(strlen(input)>3||check_amount(input));
	  p2->amount=amount_do(input);/*将字符转成整型*/
      p2->tag1=0;
      p2->tag2=0;
      p2->next=NULL;
      p1->next=p2;
      p1=p2;
     }
   //  return(head);
 }
 else
 {
  p1=p2=head;
  while(p1->next)p1=p1->next;/*将指针移动到最后*/
  for(;;)/*输入后续的结点*/
     {
      p2=(BOOK *)malloc(BOOK_LEN);
       do
	 {printf("书名:");/*输入书名*/
	  scanf("%s",&p2->nam);
      if(p2->nam[0]=='0')return(head);
	  if(strlen(p2->nam)>28)printf("输入长度不能大于28个字符,请重新输入\n");
     }while(strlen(p2->nam)>28);
	  do
	 {printf("主编:");/*输入主编者名字*/
      scanf("%s",&p2->editor);
      if(p2->editor[0]=='0')strcpy(p2->editor,"UNKNWON");
	  if(strlen(p2->editor)>28)printf("输入长度不能大于28个字符,请重新输入\n");
     }while(strlen(p2->editor)>28);
	  do
	 {printf("数量:");
      scanf("%s",&input);
	  if(strlen(input)>3)printf("输入不能多于3位,请重新输入\n");
     }while(strlen(input)>3||check_amount(input));
	  p2->amount=amount_do(input);/*将字符转成整型*/
      p2->tag1=0;
      p2->tag2=0;
      p2->next=NULL;
      p1->next=p2;
      p1=p2;
 }
 }
 return(head);
}

int check_amount(char input[])/*检查输入的数字是否合法*/
{int len,n;
 len=strlen(input)-1;
 for(n=0;n<=len;n++)
 {if(!(input[n]>='0'&&input[n]<='9')){printf("输入不合法！！！\n");return 1;}
 }
 return 0;
} 

int amount_do(char input[5])
{int len,n,value=0,hundred=100,ten=10;
 int a[5];
 len=(strlen(input)-1);
 for(n=0;n<=len;n++)/*input中的每一个字符转成整型*/
 {switch(input[n])
     {case'0':a[n]=0;break;
      case'1':a[n]=1;break;
      case'2':a[n]=2;break;
      case'3':a[n]=3;break;
      case'4':a[n]=4;break;
      case'5':a[n]=5;break;
      case'6':a[n]=6;break;
      case'7':a[n]=7;break;
      case'8':a[n]=8;break;
      case'9':a[n]=9;break;
     }  
 }
 switch(len)/*求总值*/
 {case 0:value=a[0];break;
  case 1:value=a[0]*ten+a[1];break;
  case 2:value=a[0]*hundred+a[2];break;
 }
 return(value); 
}
char user_menu()/*教师学生菜单*/
{char n;
 system("cls");/*刷屏*/
 printf("         |*************************************************************|\n");
 printf("         |=============================================================|\n");
 printf("         |                        (按 '0' 退出，)                      |\n");
 printf("         |===========================MENU==============================|\n");
 printf("         |  输入您的选择(1-3):                                         |\n");
 printf("         |            0.退出                                           |\n");
 printf("         |            1.订购书籍                                       |\n");
 printf("         |            2.查看自己的订购单                               |\n");
 printf("         |            3.删除订购单中的某些书籍                         |\n");
 printf("         |            4.查看领书单                                     |\n");
 printf("         |                                                             |\n");
 printf("         |                                                             |\n");
 printf("         |*************************************************************|\n");
 printf("\n\t\t\t您的选择是:");
 scanf("%s",&n);
 return(n);
}

void tcher_stu_do()/*教师和学生模块*/
{USER *head_user;
 BOOK *head_book;
 head_user=user_input();/*输入教师或学生的信息*/
 if(head_user==NULL)return;
 save_user_record(head_user);/*追加存储信息到磁盘*/
 for(;;)
 {
  switch(user_menu())/*教师学生菜单*/           /***********************************************************************************************************************/
  {case '0':switch(quit()){
                           case'1':about_system();exit(0);break;
                           case'0':break;
                          }
            break;
   case '1':head_book=load(head_user->num);/*首先检测之前是否有订购单*/
            head_book=input_book_list(head_book);/*输入订购单*/
			head_book=together(head_book);/*归并相同的名称书籍的数量*/
            print_book_list(head_book);
			if(head_book)books_list_save(head_book,head_user->num);/*以用户的号码为文件名存储订购单*/
            break;
   case '2':head_book=load(head_user->num);/*装载已存储的订购单*/
            if(head_book)print_book_list(head_book);/*查询自己的订购单*/
            else {system("cls");printf("\n\n\n\n并没有属于您的订购单。又或是你的订购单已经经过处理，请到查询领书单");getch();}
            break;
   case '3':head_book=load(head_user->num);/*装载已存储的订购单*/
            if(head_book){print_book_list(head_book);/*查询自己的订购单*/
                          head_book=obliterate(head_book);
                          print_book_list(head_book);/*修改自己的订购单*/
                          if(head_book)books_list_save(head_book,head_user->num);
						  else delete_file(head_user->num);
                         }
            else {system("cls");printf("\n\n\n\n没有属于您的订购单 .\n请先输入订购单.\n按任意键继续............");getch();}
            break;
   case '4':
	        print_fetch(head_user);
            break;/*查看个人的领书单-----------------------------------*/
  }

 }
}

void books_list_save(BOOK *head_book,char filename[])/*以filename为文件名存储书籍信息*/
{
 FILE *fp;
 BOOK *p;
 char a[100]="d:\\";
 char b[5]=".txt";
 strcat(a,filename);
 strcat(a,b);
 if((fp=fopen(a,"w"))==NULL)
   {printf("Cannot open the file\n");
    return;
   }
 p=head_book;
 while(p!=NULL)
   {fwrite(p,BOOK_LEN,1,fp);
    p=p->next;
   }
 fclose(fp);
 printf("Save the file successfully!\n");
}

BOOK *load(char filename[])/*打开文件*/
{BOOK *p1,*p2,*head=NULL;
 FILE *fp;
 char a[100]="d:\\";
 char b[5]=".txt";
 strcat(a,filename);
 strcat(a,b);
 if((fp=fopen(a,"r"))==NULL)
   {    return(NULL);
   }
  p1=(BOOK *)malloc(BOOK_LEN);
  if(!p1)
   {printf("Out of memory!\n");
    return(head);
   }
  head=p1;
  while(!feof(fp))
   {if(fread(p1,BOOK_LEN,1,fp)!=1) break;
    p1->next=(BOOK *)malloc(BOOK_LEN);
    if(!p1->next)
      {printf("Out of memory!\n");
       return (head);
      }
  p2=p1;
  p1=p1->next;
   }
  p2->next=NULL;
  fclose(fp);
  return (head);
}
void print_book_list(BOOK *head_book)/*显示订购单(总共10行)*/
{int n,i,j,t;
 char m;
 BOOK *q,*point[10];
 USER *p;
 for(i=0;i<=9;i++)point[i]=NULL;/*指针数组初置为空*/
 for(q=head_book,j=1;q;q=q->next,j++)/*设置一个指针数组用来标记每一页的初指针*/
  {if(j%10==1)point[j/10+1]=q;
  }
 i=1;/*页数*/
 while(q=point[i])
 { n=1;
   system("cls");/*刷屏*/
   printf("*************************************<List>*************************************");
   printf("|   '1' -上一页                  '2' -下一页                    '0' -确认      |");
   printf("================================================================================");
   printf("================================================================================");
   printf("| 编号 |              书名            |              主编            | 数量 |\n");
   printf("--------------------------------------------------------------------------------");
  while(q&&n<=10)/*每页显示17行*/
   {printf("|  %-3d |%-30s|%-30s|%-6d|\n",n,q->nam,q->editor,q->amount);
    n++;
    q=q->next;
   }
  q=NULL;
 printf("================================================================================");
 printf("第%d页",i);
 m=getch();
 if(m=='0')break;
 else if(m=='1')
        {if(point[i-1]){i-=1;}
         else {printf("\n\n这是第一页，没有上一页了!!!按任意键继续 ");getch();}
        }
 else if(m=='2')
       {if(point[i+1]){i+=1;}
        else {printf("\n\n这是最后一页，没有下一页了!!!按任意键继续");getch();}
       }
 }
 return;
}

void print_fetch(USER *head_user)/*显示用户表单*/
{char a[10]="f";
 BOOK*head_book;
 strcat(a,head_user->num);
 head_book=load(a);
 if(head_book==NULL)
 {system("cls");
    printf("\n\n\n\n\n可能您的订购单还未经过发行人员的审核，请多等待几天\n");
    printf("又或许之前您并没有提交订购单，请确定您已经填写订购单 \n\n按任意键继续");getch();
   }
   else{system("cls");
	        printf("                                       提示       \n\n");
	        printf("               如果您发现订购的某些书籍不在您的领书单里面，即表明该书库存却货。\n");
			printf("            请稍等几日后再提交该书的订购申请。\n");
            printf("               在您查询过领书单之后，系统将会删除领书单!!!!\n\n\n\n\n\n");
			printf("\n\n\n                        按任意键后将显示领书单");
			getch();
	    print_book_list(head_book);
		delete_file(a);
   }
}

void buyer()/*采购员模块*/                      /************************************************************************************************************************/
{USER *head_buyer;
 BOOK *absent_books;
 BOOK*new_adding=NULL;
 head_buyer=user_input();/*输入采购员的信息*/
 if(head_buyer==NULL)return;
 for(;;)
 {switch(buyer_menu())/*菜单*/
  {case '0':switch(quit()){case'1':about_system();exit(0);break;
                           case'0':break;
                          }
            break;
   case '1':/*输入进书单*/
            new_adding=input_book_list(new_adding);
			new_adding=together(new_adding);/*归并相同名称书籍的数量*/
            books_list_save(new_adding,"new_add");
            print_book_list(new_adding);
            add_to_store(new_adding);
			break;
   case '2':absent_books=load("lack");
	       if(absent_books)
		   {absent_books=together(absent_books);
			books_list_save(absent_books,"lack");
			system("cls");
			printf("\n\n\n                                  提示\n\n");
			      printf("                   在您查询过缺书单之后，系统将会删除缺书单\n\n\n\n");
			printf("\n\n\n                          按任意键后将显示缺书单");
			getch();
	        print_book_list(absent_books);
			delete_file("lack");
           }else {system("cls");printf("\n\n\n\n\n\                             暂无缺书记录!!!");getch();}
			break;/*查看书库缺书单*/
  }
 }
}
char buyer_menu()/*采购员菜单*/
{char n;
 system("cls");/*刷屏*/
 printf("         |*************************************************************|\n");
 printf("         |=============================================================|\n");
 printf("         |                        (按 '0' 退出，)                      |\n");
 printf("         |===========================MENU==============================|\n");
 printf("         |  输入您的选择(0-2):                                         |\n");
 printf("         |            0.退出                                           |\n");
 printf("         |            1.填写进书单                                     |\n");
 printf("         |            2.查看缺书单                                     |\n");
 printf("         |                                                             |\n");
 printf("         |                                                             |\n");
 printf("         |*************************************************************|\n");
 printf("\n\t\t\t您的选择是:");
 scanf("%s",&n);
 return(n);
}

void add_to_store(BOOK*new_adding)/*加到库存*/
{	BOOK *p,*head_store;
	p=head_store=load("store");/*先载入库存的链表*/
	while(p->next)p=p->next;
	p->next=new_adding;/*将新的链表接如库存链表表尾*/
	head_store=together(head_store);/*归并相同的名称书籍*/
	books_list_save(head_store,"store");
}

void issuer()/*发行人员模块*/
{USER *head_issuer,*head_user;
 BOOK *head_book,*head_new,*head_store=NULL;
 head_issuer=user_input();/*输入采购员的信息*/
 if(head_issuer==NULL)return;
 for(;;)
 {                                                     /*******************************************************************************************************************/
  switch(issuer_menu())/*菜单*/
  {case '0':switch(quit()){case'1':about_system();exit(0);break;
                           case'0':break;
                          }
   case '1':dispose_buy_list();/*返回领书单给用户*/
            break;
   case '2':head_new=load("new_add");/*查看进书通知*/
	        if(head_new)print_book_list(head_new);
			else {system("cls");printf("\n\n\n\n                  尚无进书通知");getch();}
            break;/*显示书单(总共10行)*/
   case '3':if(load("store")==NULL)
            {head_store=input_book_list(head_store);
	         head_store=together(head_store);
             books_list_save(head_store,"store");
             print_book_list(head_store);
            }
            else{system("cls");printf("库存表已经存在，收到进书通知之后系统将自动更新库存");getch();}
            break;
   case '4':head_store=load("store");/*查看库存*/
            print_book_list(head_store);
            break;
  }
 }
}
char issuer_menu()/*发行人员菜单*/
{char n;
 system("cls");/*刷屏*/
 printf("         |*************************************************************|\n");
 printf("         |=============================================================|\n");
 printf("         |                        (按 '0' 退出，)                      |\n");
 printf("         |===========================MENU==============================|\n");
 printf("         |  请输入您的选择(1-4):                                       |\n");
 printf("         |            0.退出                                           |\n");
 printf("         |            1.处理订购单                                     |\n");
 printf("         |            2.查看进书通知                                   |\n");
 printf("         |            3.输入系统初始的库存书籍                         |\n");
 printf("         |            4.查看库存                                       |\n");
 printf("         |                                                             |\n");
 printf("         |*************************************************************|\n");
 printf("\n\t\t\t您的选择是:");
 scanf("%s",&n);
 return(n);
}

void dispose_buy_list()/*处理订购单*/
{int n=0;
 USER*p,*head_user;
 BOOK*head_book,*head_store,*store,*q,*p3,*p4,*copy;
 head_store=load("store");
 head_user=load_user_record("all_user");
 if(head_user==NULL){printf("没有用户提交订购单!!!\n");}
 if(head_store==NULL){printf("\n库存是空的!!!请您先检查库存!!!\n");}
 if(head_store==NULL||head_user==NULL){printf("按任意键继续");getch();return;}
 if(head_user&&head_store)
 {p=head_user;
  while(p)
    {head_book=load(p->num);
     if(head_book)
       {n++;
		print_book_list(head_book);
        if(cmp_store(head_store,head_book)>0)/*与库存相比较，当库存有满足需求的书籍时*/
             {
                books_list_save(head_store,"store");/*存储修改后的库存*/
                return_list(head_book,p);/*返回领书单*/           
                delete_file(p->num);/*删除原来的订购单*/
             }
        else if(cmp_store(head_store,head_book)==0)
		     {p3=head_store;/*若该用户所有订购的书籍库存都不能满足*/
		      p4=head_book;
		      while(p3->next)p3=p3->next;
			  for(p4=head_book;p4;p4=p4->next)/*在库存表尾生成新的接点*/
			  {copy=(BOOK *)malloc(BOOK_LEN);
			   strcpy(copy->nam,p4->nam);
			   strcpy(copy->editor,p4->editor);
			   copy->next=NULL;
			   copy->amount=-p4->amount;
			   copy->tag1=0;
			   copy->tag2=0;
			   p3->next=copy;
			   p3=copy;
			  }
              head_store=together(head_store);/*合并同名书籍的数量*/
	          books_list_save(head_store,"store");
		     }  
       }
     p=p->next;
    }
   if(n==0){system("cls");printf("\n\n\n\n\n\n                               没有用户提交订购单!!!");getch();}
 }
 check_about_lack(head_store);
 return;
}

void delete_file(char filename[])/*删除文件*/
{char a[10]="d:\\";
 char b[5]=".txt";
 strcat(a,filename);
 strcat(a,b);
 remove(a);
 return;
}

int cmp_store(BOOK *head_store,BOOK *head_book)/*检查库存是否存在该书籍且足够数目*/
{BOOK *p1,*p2,*head_lack,*p3;
 int count=0;
 p1=head_book;
 p2=head_store;
 if(p2)
 while(p1)
   {p2=head_store;
    while(p2&&strcmp(p1->nam,p2->nam)!=0)p2=p2->next;
    if(p2)/*如果指针不空*/
      {p1->tag1=1;/*则标记为存在*/
       if(p1->amount<=p2->amount)
       {p1->tag2=1;/*如果数目存在，则标记足够*/
        p2->amount=p2->amount-p1->amount;/*将库存记录的数量改成取书后的数量*/
        count++;
       }
      }	
    p1=p1->next;
   }
 return(count);
}

void check_about_lack(BOOK *head_store)/*登记入缺书表*/
{BOOK *p;
 FILE *fp;
 if((fp=fopen("d:\\lack.txt","a"))==NULL)
 {return ;}
 p=head_store;
 while(p)
   { if(p->amount<=0)
     {   fwrite(p,BOOK_LEN,1,fp);
     }
     p=p->next;
   }
 fclose(fp);
 return;
}

void return_list(BOOK *head_book,USER *head_user)/*返回领书单*/
{BOOK*p;
 FILE*fp;
 char a[100]="d:\\f";
 char b[5]=".txt";
 strcat(a,head_user->num);
 strcat(a,b);
 if((fp=fopen(a,"a"))==NULL)
   {return;
   }
 p=head_book;
 while(p)
 {if(p->tag1==1&&p->tag2==1)fwrite(p,BOOK_LEN,1,fp);
  p=p->next;
 }
 fclose(fp);
 return;
}

void about_system()/*系统备注*/
{system("cls");/*刷屏*/
 printf("         |*************************************************************|\n");
 printf("         |=============================================================|\n");
 printf("         |                      感谢您的使用!!!!                       |\n");
 printf("         |                                                             |\n");
 printf("         |                       (按任意键继续)                        |\n");
 printf("         |                                                             |\n");
 printf("         |*************************************************************|\n");
 getch();
}

char quit()/*退出确定*/
{char n;
 system("cls");/*刷屏*/
 printf("         |*************************************************************|\n");
 printf("         |=============================================================|\n");
 printf("         |                                                             |\n");
 printf("         |                                                             |\n");
 printf("         |                       您确定要退出吗？                      |\n");
 printf("         |                                                             |\n");
 printf("         |                    按‘1’确定 ，按任意键取消               |\n");
 printf("         |                                                             |\n");
 printf("         |                                                             |\n");
 printf("         |=============================================================|\n");
 printf("         |*************************************************************|\n");
 n=getch();
 return n;
}


BOOK *obliterate(BOOK *head_book)/*删除*/
{BOOK *p1,*p2;
 char book_name[30],edit_name[30];
 system("cls");/*刷屏*/
  printf("                          输入您相要删除的书籍名称                      \n");
  printf("                                                                        \n");
  printf("                               输入‘0’返回                            \n");
 for(;;)
{if(head_book)
 {printf("书名：");
  scanf("%s",book_name);
  if(book_name[0]=='0')break;
  printf("主编：");
  scanf("%s",edit_name);
  p1=p2=head_book;
  if(!strcmp(head_book->nam,book_name)&&!strcmp(head_book->editor,edit_name)){head_book=head_book->next;printf("……删除成功\n\n");}/*删除对象为首结点的情况*/
  else/*删除对象为中间结点*/
    {for(p1=head_book,p2=head_book->next;p2&&strcmp(p2->nam,book_name)&&strcmp(p2->editor,edit_name);p1=p2,p2=p2->next);/*查找到需删除接点时终止循环*/
       if(p2)
	   { p1->next=p1->next->next;
         printf("……删除成功\n");
       }    
       else printf("您的订购单中没有该书籍！！！！\n\n");                                               
    }
 }
 else {printf("\n您的订购单为空！！！！\n");getch();break;}
}
 return(head_book);
}


void save_user_record(USER*head_user)/*追加记录用户名单-----------------------------------------------------------------*/
{FILE *fp;
 USER *p,*q;
 char a[100]="d:\\all_user.txt";
 p=load_user_record("all_user");
 while(p)/*检测该用户记录是否已经存在*/
    {if(strcmp(p->num,head_user->num)==0)
     {printf("\n\n\n\n\n                          %s 欢迎您使用本系统！！！",head_user->name);/*若存在，则结束该追加记录函数*/
      getch();
      return;
     }
     else p=p->next;
    }
 if(!p)
 {if((fp=fopen(a,"a"))==NULL)
   {printf("Cannot open the file\n");
    return;
   }
 fwrite(head_user,USER_LEN,1,fp);
 printf("\n\n\n\n\n                           %s 欢迎您首次使用本系统！！！",head_user->name);
 getch();
 }
 fclose(fp);
 return;
}


void print_user_record(USER*head_user)/*打印用户记录*/
{USER*p;
 p=load_user_record("all_user");
 while(p)
 {printf("NO.%s   NAME: %s\n",p->num,p->name);
  p=p->next;
 }
 getch();
 return;
}


USER *load_user_record(char filename[])
{USER *p1,*p2,*head=NULL;
 FILE *fp;
 char a[100]="d:\\";
 char b[5]=".txt";
 strcat(a,filename);
 strcat(a,b);
 if((fp=fopen(a,"r"))==NULL)
   {return(head);
   }
 p1=(USER *)malloc(USER_LEN);
 if(!p1)
   {printf("Out of memory!\n");
    return(head);
   }
 head=p1;
 while(!feof(fp))
   {if(fread(p1,USER_LEN,1,fp)!=1) break;
    p1->next=(USER *)malloc(USER_LEN);
    if(!p1->next)
      {printf("Out of memory!\n");
       return (head);
      }
    p2=p1;
    p1=p1->next;
   }
 p2->next=NULL;
 fclose(fp);
 return (head);
}

void create_file(char filename[])/*创建空文件（为了以后的追加做准备）*/
{char a[100]="d:\\";
 char b[5]=".txt";
 strcat(a,filename);
 strcat(a,b);
 if(fopen(filename,"at")==NULL)
   {printf("Cannot open the file\n");
   }
}

BOOK *together(BOOK *head_book)/*归并相同的名称书籍*/
{BOOK *p1,*p2,*p3;
 if(head_book)
  {if(head_book->next)
   for(p1=head_book;p1;p1=p1->next)
	   for(p2=p1,p3=p2->next;p3;p2=p3,p3=p3->next)
	   {if(!strcmp(p1->nam,p3->nam)&&!strcmp(p1->editor,p3->editor))
	                   {p1->amount+=p3->amount;
	                    p2->next=p2->next->next;
			    p3=p2;
	                   }
	 }
  }
 return(head_book);
}