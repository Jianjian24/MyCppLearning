#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include<stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct HUFF {
    char ch;
    int weight;
    int parent;
    int Lchild, Rchild;
}Huffman, *Huff;


typedef struct My_Data {
    int ch;
    int weight;
}dat;

typedef struct HUFFCODE {
    char code[72];//ch�Ĺ���������
    char ch;
}HuffCode, *pHuffC;

void Create_ToBeTran(void); //��������

char DataFile_Create(char flag);   //����datafile

char HuffTree_Create(Huffman** HuffTree, unsigned char* n);   //������ϣ��

void HuffCoding(Huff* HuffTree, unsigned char n, pHuffC* PHuffCode);   //�õ���������

char HuffCodeFile_Create(unsigned char n, pHuffC* PHuffCode, char flag);  //���������ļ�

#endif // !__HUFFMAN_H__
