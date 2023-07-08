#include "../../../jian.h"

struct SLinkNode
{
    int data;
    SLinkNode* next;

    SLinkNode(int newData)
    {
        data = newData;
        next = nullptr;
    }
};

void revert(SLinkNode* head)
{
    SLinkNode* cur = head->next;
    SLinkNode* pre = nullptr;
    SLinkNode* tmp = nullptr;

    while (cur)
    {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }

//     return pre;
// }
// {
    while (pre)
    {
        cout << "now is" << pre->data << '\n';
        pre = pre->next;
    }
     
}

// void revert(SLinkNode* phead)
// {
//     SLinkNode* pre = nullptr;
//     SLinkNode* tmp = nullptr;

//     while (phead)
//     {
//         tmp = pre;
//         pre = phead;
//         phead = phead->next;
//         pre->next = tmp;
//     }

//     while (pre)
//     {
//         cout << "now is" << pre->data << '\n';
//         pre = pre->next;
//     }
     
// }



int main()
{
    SLinkNode* head = new SLinkNode(12);
    SLinkNode* tmp = head;
    tmp->next = new SLinkNode(13);
    tmp = tmp->next;
    tmp->next = new SLinkNode(14);
        tmp = tmp->next;
    tmp->next = new SLinkNode(15);
        tmp = tmp->next;
    tmp->next = new SLinkNode(16);

    tmp = head;

    while (tmp)
    {
        cout << "test is" << tmp->data << '\n';
        tmp = tmp->next;
    }

    // revert(head);

    return 0;
}