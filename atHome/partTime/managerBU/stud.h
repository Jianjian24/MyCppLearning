#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 100
struct student            /*定义学生结构体*/
{ 
char num[20];
char name[20];
char sex[5];
char cla[5];
char QQ[20];
char tele[20];
char job[5];
char city[10];
};
struct student stu[N];
 void enter();
 void input(); 
 void save();
 void display();
 void add(); 
 void delet();
 void amend();
 void preside(); 
 void find();
 void find1();
 void find2();
 void find3();
 void find4();
 void output();
extern int t;

