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
    char code[72];//ch的哈夫曼编码
    char ch;
}HuffCode, *pHuffC;

void Create_ToBeTran(void); //创建明文

char DataFile_Create(char flag);   //创建datafile

char HuffTree_Create(Huffman** HuffTree, unsigned char* n);   //建立哈希树

void HuffCoding(Huff* HuffTree, unsigned char n, pHuffC* PHuffCode);   //得到编码数组

char HuffCodeFile_Create(unsigned char n, pHuffC* PHuffCode, char flag);  //创建编码文件

#endif // !__HUFFMAN_H__
