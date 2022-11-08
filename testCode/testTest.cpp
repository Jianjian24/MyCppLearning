void myStrncat (char *toString, char *fromString, int maxBytes)
{
    int len = 0;
    while (fromString[len] != '\0')//get the length of fromString
        ++len;

    int endIndex = 0;
    if (len <= maxBytes)
        endIndex = len;
    else
        endIndex = maxBytes;

    //move index to the end of toString
    int index = 0;
    while (toString[index] != '\0')
        ++index;

    int i = 0;
    for (; i < endIndex; i++)
        toString[index++] = fromString[i];
    
    toString[i] = '\0';
    
}

int totalCost(int* c1, int* c2)
{
    return *c1 + *c2;
}

int main()
{
    int *cost1 = new int(100);
    int *cost2 = new int(200);

    totalCost(cost1, cost2);
}