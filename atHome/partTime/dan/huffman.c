#include "huffman.h"

#pragma warning(disable : 4996)


/*��������  my_strcpy
 *���ܣ�    ȥ���ַ����Ŀո�
 *���������Ŀ���ַ���
 *          ԭ�ַ���
 *����ֵ�� ��
 */
void my_strcpy(char *_Destination, char const* _Source)
{
    unsigned char i = 0;
    unsigned char y = 0;

    while (_Source[i] != '\0' && i < 72)
    {
        if (_Source[i] != ' ')
        {
            _Destination[y] = _Source[i];
            y++;
        }
        i++;
    }
    _Destination[y] = '\0';
}


/*��������  Tmp_Init
 *���ܣ�    �ַ����ÿո�����
 *����������ַ�����
 *          ����
 *����ֵ�� ��
 */
void Tmp_Init(char* tmp, char n)
{
    char i = 0;

    tmp[n - 1] = '\0';

    for (i = 0; i < n - 1; i++)
    {
        tmp[i] = ' ';
    }
}

/*
 *��������  select
 *���ܣ�    �ҹ���������Ȩ����С��������
 *���������������ָ��
 *          ����
 *          ��С���±�
 *          ��С���±�
 *����ֵ�� ��
 */
void select(Huffman *Tree, int k, int* min1, int* min2)  //ѡ��Ȩֵ��С�Ľ��
{
    *min1 = 0;
    *min2 = 0;
    int small1 = 9999;
    int small2 = 9999;

    int i;

    for (i = 0; i < k; i++)
    {
        if (Tree[i].parent == -1)
        {
            if (Tree[i].weight < small1)
            {
                small2 = small1;
                small1 = Tree[i].weight;
                *min2 = *min1;
                *min1 = i;
            }
            else if (Tree[i].weight < small2)
            {
                small2 = Tree[i].weight;
                *min2 = i;
            }
        }
    }
}

/*��������  DataFile_Create
 *���ܣ�    ����Data_File�ļ���
 *���������0��demo�ļ�����
 *          
 *����ֵ��  1Ϊ�ɹ� 0Ϊʧ��
 */
char DataFile_Create(char flag)
{
    dat* mydata;
    
    unsigned char i = 0;
    
    FILE* pTobeTrain;

    FILE* pDataFile;

    
    char ch;

    mydata = (dat*)malloc(sizeof(dat) *70);

    for (i = 0; i < 71; i++)
    {
        if (i < 10)mydata[i].ch = i + '0';
        else if (i < 36)mydata[i].ch = i + 'A' - 10;
        else if (i < 62)mydata[i].ch = i + 'a' - 36;
        else if (i == 62)mydata[i].ch = '?';
        else if (i == 63)mydata[i].ch = ',';
        else if (i == 64)mydata[i].ch = '.';
        else if (i == 65)mydata[i].ch = '!';
        else if (i == 66)mydata[i].ch = '^';
        else if (i == 67)mydata[i].ch = '"';
        else if (i == 68)mydata[i].ch = ' ';
        else if (i == 69)mydata[i].ch = '\n';
        //else mydata[i].ch = '*';
        mydata[i].weight = 0;
    }

    if (flag == 0)
    pTobeTrain = fopen("demo.txt", "r");
    else
    {
        pTobeTrain = fopen("ToBeTran.txt", "r");
        if (pTobeTrain == NULL)
        {
            printf("TobeTran.txt��ʧ��");
            return 0;
        }
    }

    

    while ((ch = fgetc(pTobeTrain)) != EOF)
    {
        if (ch <= '9' && ch >= '0')      //������ʱ����mydata[ch - '0']
        {
            mydata[ch - 48].weight++;
        }
        else if (ch <= 'Z' && ch >= 'A')      //��д��ĸ����mydata[ch - 'A' + 10]
        {
            mydata[ch - 55].weight++;
        }
        else if (ch <= 'z' && ch >= 'a')      //mydata[ch - 'a' + 10 +26]
        {
            mydata[ch - 61].weight++;
        }
        else if (ch == '?')     //mydata[ch - ('?' / ',' / '.' .....) + 26 + 26 + 10 + (0 / 1 / 2 / 3....)] ch - 1
        {
            mydata[62].weight++;
        }
        else if (ch == ',')    //+1  ch + 19
        {
            mydata[63].weight++;
        }
        else if (ch == '.')        //+2   ch + 18
        {
            mydata[64].weight++;
        }
        else if (ch == '!')        //+3   ch + 32
        {
            mydata[65].weight++;
        }
        else if (ch == '^')      //+4   ch - 28
        {
            mydata[66].weight++;
        }
        else if (ch == '"')
        {
            mydata[67].weight++;
        }
        else if (ch == ' ')
        {
            mydata[68].weight++;
        }
        else if (ch == '\n')
        {
            mydata[69].weight++;
        }
        //else    //*
        //{
        //    mydata[70].weight++;
        //}
    }

    pDataFile = fopen("DataFile.txt", "w+");
    if (pDataFile == NULL)
    {
        printf("DataFile create failed!\n");
        return 0;
    }

    
    for (i = 0; i < 70; i++)
    {
        if (mydata[i].weight)
        fprintf(pDataFile, "%c %d\n", mydata[i].ch, mydata[i].weight);
    }

    //for (i = 0; i < 2 * n - 1; i++)
//{
//    huffmantree[i].parent = -1;
//    huffmantree[i].Lchild = -1;
//    huffmantree[i].Rchild = -1;
//}
//for (i = 0; i < n; i++)huffmantree[i].weight = w[i];

//for (i = n; i < 2 * n - 1; i++)
//{
//    select(huffmantree, i, &min1, &min2);
//    huffmantree[i].weight = huffmantree[min1].weight + huffmantree[min2].weight;
//    huffmantree[min1].parent = i;
//    huffmantree[min2].parent = i;
//    huffmantree[i].Lchild = min1;
//    huffmantree[i].Rchild = min2;
//}

    free(mydata);
    fclose(pDataFile);
    fclose(pTobeTrain);

    return 1;
}


/*��������  Create_ToBeTran
 *���ܣ�    �������Ĵ���tobetran�ļ�
 *�����������
 *����ֵ�� ��
 */
void Create_ToBeTran(void)
{
    char ch;
    FILE* p_ToBeTran;

    p_ToBeTran = fopen("ToBeTran.txt", "w+");

    printf("�����������СдӢ����ĸ������\n \" . ? ! ^ , �ո���� ���з���   ����52 + 10 + 8 = 70���ַ�\n");
    printf("������Ҫ�����Դ�ļ�\n������'#'����\n");
    while ((ch = getchar()) != '#')
    {
        fputc(ch, p_ToBeTran);
    }

    fclose(p_ToBeTran);
}


/*��������  HuffTree_Create
 *���ܣ�    ��datafile���ɹ�������, �������ڵõ���������ָ��ͳ���
 *���������������������ָ��
 *          ����ָ��
 *����ֵ�� ��
 */
char HuffTree_Create(Huffman** HuffTree, unsigned char* n)
{
    unsigned char i = 0;
    *n = 71;
    int min1, min2;

    char tmp[4];  //һ������������999��
    unsigned char y = 0;

    char ch;

    //FILE* pTobeTrain;
    FILE* pDataFile;

    //if (flag == 0)pTobeTrain = fopen("demo.txt", "r");
    //else
    //{
    //    pTobeTrain = fopen("ToBeTran.txt", "r");
    //    if (pTobeTrain == NULL)
    //    {
    //        printf("TobeTran.txt��ʧ��");
    //        return 0;
    //    }
    //}
    pDataFile = fopen("Datafile.txt", "r");

    dat* mydata;
    

    mydata = (dat*)malloc(sizeof(dat) * 71);          //��ʱ����

    //i = 0;
    while ((ch = fgetc(pDataFile)) != EOF)
    {
        mydata[i].ch = ch;
        ch = fgetc(pDataFile);  //��ȡ�ո�
        y = 0;
        while ((ch = fgetc(pDataFile)) != '\n')
        {
            tmp[y] = ch;
            y++;
        }
        tmp[y] = '\0';
        mydata[i].weight = atoi(tmp);
        i++;
    }
    *n = i;
   /* i++;*/
    (*HuffTree) = (Huff)malloc(sizeof(Huffman) * (2 * (*n) - 1));

    while (i > 0)                                         //��Ȩֵ
    {
        i--;
        (*HuffTree)[i].ch = mydata[i].ch;
        (*HuffTree)[i].weight = mydata[i].weight;
    }

    free(mydata);                                   //�ͷ��ڴ�
    

    for (i = 0; i < 2 * (*n) - 1; i++)
    {
        (*HuffTree)[i].parent = -1;
        (*HuffTree)[i].Lchild = -1;
        (*HuffTree)[i].Rchild = -1;
    }   

    for (i = *n; i < 2 * (*n) - 1; i++)
    {
        (*HuffTree)[i].ch = '#';
    }

//for (i = 0; i < n; i++)HuffTree[i].weight = w[i];


    for (i = *n; i < 2 * (*n) - 1; i++)
    {
        select(*HuffTree, i, &min1, &min2);
        (*HuffTree)[i].weight = (*HuffTree)[min1].weight + (*HuffTree)[min2].weight;
        (*HuffTree)[min1].parent = i;
        (*HuffTree)[min2].parent = i;
        (*HuffTree)[i].Lchild = min1;
        (*HuffTree)[i].Rchild = min2;
    }

 //   for (i = 0; i < (*n) * 2 - 1; i++)
 //   {
	//if ((*HuffTree)[i].ch == '\n')printf("- %d %d %d %d\n", (*HuffTree)[i].weight, (*HuffTree)[i].parent, (*HuffTree)[i].Lchild, (*HuffTree)[i].Rchild);   //�س���ʾ�����㣬��-���
	//else printf("%c %d %d %d %d\n", (*HuffTree)[i].ch, (*HuffTree)[i].weight, (*HuffTree)[i].parent, (*HuffTree)[i].Lchild, (*HuffTree)[i].Rchild);
 //   }

    //fclose(pTobeTrain);
    fclose(pDataFile);

    return 1;
}

/*��������  HuffCoding
 *���ܣ�    ���ɹ���������
 *�������������������
 *          ���������鳤��
 *          ��������������
 *����ֵ�� ��
 */
void HuffCoding(Huff *HuffTree, unsigned char n, pHuffC* PHuffCode)
{
    char* tmp;
    char i, start;
    int parent;
    int pos;

    //HuffCode phuffcode;

    *PHuffCode = (pHuffC)malloc(sizeof(HuffCode) * n);

    tmp = (char*)malloc(sizeof(char) * n);

    //system("cls");
    //for (i = 0; i < n * 2 - 1; i++)
    //{
    //    if ((*HuffTree)[i].ch == '\n')printf("- %d %d %d %d\n", (*HuffTree)[i].weight, (*HuffTree)[i].parent, (*HuffTree)[i].Lchild, (*HuffTree)[i].Rchild);   //�س���ʾ�����㣬��-���
    //    else printf("%c %d %d %d %d\n", (*HuffTree)[i].ch, (*HuffTree)[i].weight, (*HuffTree)[i].parent, (*HuffTree)[i].Lchild, (*HuffTree)[i].Rchild);
    //}
    //system("pause");
    //system("cls");

    for (i = 0; i < n; i++)
    {
        Tmp_Init(tmp, n);
        start = n - 1;
        pos = i;
        parent = (*HuffTree)[i].parent;
        while (parent != -1)
        {
            if ((*HuffTree)[parent].Lchild == pos)tmp[--start] = '0';
            else tmp[--start] = '1';
            pos = parent;
            parent = (*HuffTree)[parent].parent;
        }
        (*PHuffCode)[i].ch = (*HuffTree)[i].ch;
        //printf("%s, %d\n", tmp, strlen(tmp));
        //system("pause");
        strcpy((*PHuffCode)[i].code, tmp);
        
    }

    //system("cls");
    //for (i = 0; i < n; i++)
    //{
    //    //if ((*HuffTree)[i].ch == '\n')printf("- %s\n", (*PHuffCode)[i].code);   //�س���ʾ�����㣬��-���
    //    //else
    //    printf("%c\n", (*PHuffCode)[i].ch);
    //}
    //system("pause");
    //system("cls");

    free(tmp);
}

/*��������  HuffCodeFile_Create
 *���ܣ�    ���ɱ����ļ�
 *�������������������
 *          ���������鳤��
 *          ��������������
 *          ��demo�������ɻ���user����
 *����ֵ�� �ɹ�����1 ���򷵻�0
 */
char HuffCodeFile_Create(unsigned char n, pHuffC* PHuffCode, char flag)
{
    FILE* pCodeFile;
    FILE* pTobeTrain;

    char tmp[36];

    char ch;

    unsigned char i;

    pCodeFile = fopen("CodeFile.txt", "w+");
    
    if (flag == 0)pTobeTrain = fopen("demo.txt", "r");
    else
    {
        pTobeTrain = fopen("ToBeTran.txt", "r");
        if (pTobeTrain == NULL)
        {
            printf("TobeTran.txt��ʧ��");
            return 0;
        }
    }
    


    while ((ch = fgetc(pTobeTrain)) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            //printf("%d", i);
            //printf("%d,%d\n", (*PHuffCode)[i].ch, ch);
            if ((*PHuffCode)[i].ch == ch)
            {
                my_strcpy(tmp, (*PHuffCode)[i].code);
                fprintf(pCodeFile, "%s", tmp);
                break;
            }
        }
    }
    fclose(pCodeFile);
    fclose(pTobeTrain);

    return 1;
}

/*��������  Textfile_Create
 *���ܣ�    ��ȡDataFile��CodeFile�������룬������������
 *�����������
 *����ֵ�� �ɹ�����1 ���򷵻�0
 */
char Textfile_Create(void)
{
    FILE* pCodeFile;
    FILE* pDataFile;
    FILE* pTextfile;

    Huff tmp_huff; 
    pHuffC tmp_huffcode;
    unsigned char tmp_n = 0;
    unsigned char pos = 0;
    unsigned char i = 0;
    unsigned char length = 0;
    char ch;

    pCodeFile = fopen("CodeFile.txt", "r");
    pDataFile = fopen("DataFile.txt", "r");
    if (pDataFile == NULL || pCodeFile == NULL)
    {
        if (pCodeFile == NULL) printf("�޷���ȡ��codefile.txt\n");
        if (pDataFile == NULL)printf("�޷���ȡ��pDataFile.txt\n");
        return 0;
    }
    pTextfile = fopen("Textfile.txt", "w+");

    HuffTree_Create(&tmp_huff, &tmp_n);
    HuffCoding(&tmp_huff, tmp_n, &tmp_huffcode);

    {             //���벿��
        pos = 2 * tmp_n - 2;

        printf("������Ϊ:\n");
        while ((ch = fgetc(pCodeFile)) != EOF) 
        {
            if (ch == '0' + 0)
                pos = tmp_huff[pos].Lchild;
            else if (ch == '0' + 1)
                pos = tmp_huff[pos].Rchild;
            else
                return 0;
            if (tmp_huff[pos].Lchild == -1 && tmp_huff[pos].Rchild == -1)   //ÿ���һ���ַ��������һ��
            {
                putchar(tmp_huff[pos].ch);
                fputc(tmp_huff[pos].ch, pTextfile);
                pos = 2 * tmp_n - 2;
            }
            i++;
        }
        printf("\n");
        //if (pos == 2 * tmp_n - 2)
        //    return 0;
        //return 1;
    }

    free(tmp_huff);
    free(tmp_huffcode);
    fclose(pCodeFile);
    fclose(pDataFile);
    fclose(pTextfile);

    return 1;
}