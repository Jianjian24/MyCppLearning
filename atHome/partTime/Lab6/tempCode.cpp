#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
 int data;
 struct LNode *next;
}LNode,*LinkList;

//*********链表初始化**********//
void InitLinkList(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));
    if(!L)
    return ;
    // L = NULL;      //无头结点
}
//**********链表的建立（首元结点单独输入）**********//
void CreateLinkList_Tail(LinkList &L,int n)
{
    int i;
    LinkList pre,p;
    printf("请输入首元结点的数据值:");
    L = (LinkList)malloc(sizeof(LNode));
    scanf("%d",&L->data);         //首元结点的值
    pre = L;
    printf("请输入剩余%d个结点的数据值:\n",n-1);
    for(i=0;i<n-1;i++){
    p = (LinkList)malloc(sizeof(LNode));
    scanf("%d",&p->data);
    pre->next = p;       //尾插法建立链表
    pre = p;
}
 pre->next = NULL;
}
//*********链表遍历显示***********//
void show(LinkList L){
 LinkList p;
 p = L;
 while(p){
  printf("%5d",p->data);
  p = p->next;
 }
 printf("\n");
}
//********求取链表长度**********//
int ListLength(LinkList L){
    int count;
    LinkList p;
    count = 0;
    p = L;
    while(p){
        count++;
        p = p->next;
    }
    return count;
}
//******从链表La中删除自第i个元素起共len个元素，并将删除元素赋到空链表Lc中*****//
void ListDelete(LinkList &La,LinkList &Lc,int i,int len)    
{
    int index = 0;
    LinkList pLaPre = La, pLc = Lc;
    LinkList pSlow = NULL;
    if (i == 0)
    {
        for (int index = 0; index < len; index++)
        {
            pLc->data = La->data;
            pLc->next = (LinkList)malloc(sizeof(LNode));
            pSlow = pLc;
            pLc = pLc->next;
            La = La->next;
        }
        pSlow->next = NULL;

        printf("所要删除的链表元素有:\n");
        show(Lc);

        return;
    }

    //先移动到要删除的节点
    while (index != i - 1 && pLaPre)
    {
        pLaPre = pLaPre->next;
        index++;
    }

    LinkList pCur = pLaPre->next;
    for (int index = 0; index < len; index++)
    {
        pLc->data = pCur->data;
        pLc->next = (LinkList)malloc(sizeof(LNode));
        pSlow = pLc;
        pLc = pLc->next;
        pCur = pCur->next;
    }
    pSlow->next = NULL;
    pLaPre->next = pCur;
    printf("所要删除的链表元素有:\n");
    show(Lc);
}
//*******Lc插入到表lb的第i个元素之后*********//
void ListInsert(LinkList &Lb,LinkList &Lc,int i,int len)
{    
    LinkList pLbNext = Lb, pLcNext = Lc;
    int count = 0;
    //将Lc的指针挪到末尾
    while (pLcNext->next)
    {
        pLcNext = pLcNext->next;
    }
    if (i == 0)
    {
        pLcNext->next = Lb;
        Lb = Lc;        
        show(Lb);
        return;
    }
    //先将Lb的指针挪动到i-1的位置
    while(pLbNext && count != i - 1)
    {
        pLbNext = pLbNext->next;
        count++;
    }
    pLcNext->next = pLbNext->next;
    pLbNext->next = Lc;
    
    show(Lb);
}
int main(){
    int m,n,k;
    LinkList La,Lb,Lc;
    InitLinkList(La);
    InitLinkList(Lb);
    InitLinkList(Lc);
    CreateLinkList_Tail(La,3);    //建立含5个元素的链表La
    CreateLinkList_Tail(Lb,3);     //建立含5个元素的链表Lb
    printf("链表La为:\n");
    show(La);
    printf("链表Lb为:\n");
    show(Lb);

    printf("请输入从La的第几个元素起开始删除:\n");
    scanf("%d",&m);//
    printf("请输入共删除几个元素:\n");
    scanf("%d",&n);
    if(n>ListLength(La)-m){       // len值非法
        printf("所需删除链表的长度len有错误，请重新输入!\n");
        return 0;
    }
 else{
    ListDelete(La,Lc,m,n);     // 删除操作
    printf("链表La删除元素后为:\n");
    show(La);
    printf("请输入从Lb的第几个元素之前插入:\n");
    scanf("%d",&k);
    printf("将删除的La链表元素插入到Lb中后,Lb为:\n");
    ListInsert(Lb,Lc,k,n);  //插入操作
    return 0;
 }
}
