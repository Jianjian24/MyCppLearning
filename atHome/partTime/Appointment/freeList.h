void freeList(List *pList)//����ռ��ͷ� 
{
    Patient *p,*q;
    for (p = pList->head; p ;p = q)
    {
        q = p->next;
        free(p);
    }
    
}
