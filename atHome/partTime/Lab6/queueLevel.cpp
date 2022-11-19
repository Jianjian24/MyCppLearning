/*********************************************************************
* Name: Ziyu Xue
* Lab 6: Movies Linked List
* Editor(s) used: CodeBook
* Compiler(s) used: CodeBlock
* Description:
* This program manages courses taken by a student.
**********************************************************************/
#include <cstring>
#include <iomanip>
using namespace std;
#include <iostream>
using std::cin;
using std::cout;
using std::ios;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <string>
using std::getline;
using std::string;
#include <iostream>
#include <cstdlib>
#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>

string g_fileName = "movies.txt";
typedef struct movies
{
 string title;
 int year = 0;
 int rating = 0;
 movies* next = NULL;
}Movie;

void AddMovie(Movie*& pHead);//增加不用提示输入的
void print_id(string lab_desc)
{
 cout << "ZIYU XUE\n";
 cout << lab_desc << endl;
 cout << "Editor(s) used: CodeBlock\n";
 cout << "Compiler(s) used: CodeBlock\n";
 cout << "File: " << __FILE__ << "\n";
 cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}

void enQueue(Movie*& pHead, Movie* node)
{
    Movie* tmpNode = pHead;

    if (!tmpNode)
    {
        pHead = node;
        return;
    }

    while (tmpNode->next)
    {
        tmpNode = tmpNode->next;
    }
    tmpNode->next = node;
    
}
void deQueue(Movie* pHead)
{
    Movie* tmpNode = pHead;
    ofstream fout;
    fout.open(g_fileName,ios::out);
    while(tmpNode)
    {
        pHead = pHead->next;
        fout << tmpNode->title << '\n' << tmpNode->year << '\n' << tmpNode->rating << '\n';
        delete tmpNode;
        tmpNode = pHead;
    }  
    fout.close();
    // delete tmpNode;
}

void InitQueueFromFile(Movie*& pHead)
{
    char c[50];
    Movie node;
    ifstream file;
    file.open(g_fileName,ios::in);

    if(!file.is_open())
        return;

    std::string strLine;
    Movie *newNode = NULL;
    int count = 0;
    while(getline(file,strLine))
    {

        if(strLine.empty())   
            continue;
        count++;
        switch (count)
        {
        case 1:
            node.title = strLine;
            break;
        case 2:
            node.year = atoi(strLine.c_str());
            break;
        case 3:
            node.rating = atoi(strLine.c_str());
            newNode = new Movie(node);
            enQueue(pHead, newNode);
            count = 0;
            // cout<<"One node\n" <<endl;     
            break;
        
        default:
            break;
        }
        // cout<<strLine <<endl;
        // if (count == 3)
    }

    file.close();
}

void SwapNodeData(Movie* pLeft, Movie* pRight)
{
 Movie tmp;
 tmp.title = pLeft->title; tmp.year = pLeft->year; tmp.rating = pLeft->rating;
 pLeft->title = pRight->title; pLeft->year = pRight->year; pLeft->rating = pRight->rating;
 pRight->title = tmp.title; pRight->year = tmp.year; pRight->rating = tmp.rating;
}
bool InitSeq(Movie* pHead)
{
 if (!pHead)
 return false;
 cout << "(1";
 for (int index = 2; pHead->next; index++, pHead = pHead->next)
 cout << '-' << index;
 cout << ')';
 return true;
}
void AddMovie(Movie*& pHead)
{
 string strName, strTmp;
 char c;
 while ((c = getchar()) != '\n'); // clear buffer before break
 cout << "Enter a movie's name: ";
 getline(cin, strName);
/*********************************************************************
*Function: Main
**********************************************************************/
 int year, rating;
 cout << "Enter the year you saw Star Wars [like 2016]: ";
 getline(cin, strTmp);
 year = atoi(strTmp.c_str());
 if (year == 0)
 {
 cout << "Invalid input. Please try it again." << endl;
 return;
 }
 cout << "Enter your rating for Star Wars [1, 2, 3, 4, 5]: ";
 getline(cin, strTmp);
 rating = atoi(strTmp.c_str());
 if (rating < 1 || rating > 5)
 {
 cout << "Invalid input. Please try it again." << endl;
 return;
 }
 Movie* node = new Movie{ strName, year, rating };
//  node->next = pHead;
//  pHead = node;
if (pHead == NULL)
{
    pHead = node;
    return;
}

Movie* tmpNode = pHead;//add a new node at the back of the queue.
while (tmpNode->next)
    tmpNode = tmpNode->next;

tmpNode->next = node;

}
void UpdateMovie(Movie* pHead, int key)
{
 if (!pHead)
 {
 cout << "Nothing here!\n";
 return;
 }
 Movie* pCur = pHead;
 int count = 1;
 while (count != key && pCur)
 {
 count++;
 pCur = pCur->next;
 }
 char c;
 while ((c = getchar()) != '\n'); // clear buffer before break
 if (pCur)
 {
 string strName, strTmp;
 cout << "Enter a movie's name: ";
 getline(cin, strName);
 int year, rating;
 cout << "Enter the year you saw Star Wars [like 2016]: ";
 getline(cin, strTmp);
 year = atoi(strTmp.c_str());
 if (year == 0)
 {
 cout << "Invalid input. Please try it again." << endl;
 return;
 }
 cout << "Enter your rating for Star Wars [1, 2, 3, 4, 5]: ";
 getline(cin, strTmp);
 rating = atoi(strTmp.c_str());
 if (rating < 1 || rating > 5)
 {
 cout << "Invalid input. Please try it again." << endl;
 return;
 }
 pCur->title = strName;
 pCur->year = year;
 pCur->rating = rating;
 }
}
void RemoveMovie(Movie*& pHead, int key)
{
 if (!pHead)
 {
 cout << "Nothing here!\n";
 return;
 }
 Movie* pCur = pHead, * pSlow = NULL;
 int count = 1;
 while (count != key && pCur)
 {
 count++;
 pSlow = pCur;
 pCur = pCur->next;
 }
 if (pCur)
 {
 Movie* pNext = pCur->next;
 if (count == 1)
 {
 delete pHead;
 pHead = pNext;
 return;
 }
 pSlow->next = pCur->next;
 delete pCur;
 }
}
void ListMovie(Movie* pHead)
{
 cout << "# Title Viewed Rating \n";
 cout << "-- ---------------------------------------- ------ --------\n";
 int index = 1;
 Movie* pCur = pHead;
 while (pCur)
 {
 cout.width(3);
 cout << std::left << index++;
 cout.width(41);
 cout << pCur->title; // (*nodePtr).name
 cout.width(7);
 cout << pCur->year;
 cout.width(7);
 cout << pCur->rating << endl;
 pCur = pCur->next;
 }
}
void SortMovie(Movie* pHead, char key)
{
 switch (key)
 {
 case 't':
 case 'T':
 for (Movie* p = pHead; p; p = p->next)
 for (Movie* q = p->next; q; q = q->next)
 if (q->title < p->title)
 SwapNodeData(p, q);
 case 'v':
 case 'V':
 for (Movie* p = pHead; p; p = p->next)
 for (Movie* q = p->next; q; q = q->next)
 if (q->year < p->year)
 SwapNodeData(p, q);
 case 'r':
 case 'R':
 for (Movie* p = pHead; p; p = p->next)
 for (Movie* q = p->next; q; q = q->next)
 if (q->rating < p->rating)
 SwapNodeData(p, q);
 default:
 break;
 }
}
int main()
{
 Movie* pHead = NULL;
 char option;
 int select = 0;
 InitQueueFromFile(pHead);

 print_id("Lab 6");
 cout << "Menu\n";
 do
 {
 cout << "\tA Add a movie\n\tU Update a movie\n\tE Remove a movie\n\tL List all movies\n\tT arrange by Title\n\tV arrange by year Viewed\n\tR arrange by Rating\n\tQ Quit\n";
 cout << "...your choice: ";
 cin >> option;
 switch (option)
 {
 case 'A':
 case 'a':
 AddMovie(pHead);
 break;
 case 'U':
 case 'u':
 if (!pHead)
 {
 cout << "Nothing here!\n";
 break;
 }
 cout << "...which movie to Update";
 InitSeq(pHead);
 cout << "? ";
 cin >> select;
 UpdateMovie(pHead, select);
 break;
 case 'e':
 case 'E':
 if (!pHead)
 {
 cout << "Nothing here!\n";
 break;
 }
 cout << "...which movie to remove";
 InitSeq(pHead);
 cout << "? ";
 cin >> select;
 RemoveMovie(pHead, select);
 break;
 case 'l':
 case 'L':
 ListMovie(pHead);
 break;
 case 't':
 case 'T':
 case 'v':
 case 'V':
 case 'r':
 case 'R':
 SortMovie(pHead, option);
 break;
 case 'q':
 case 'Q':
    deQueue(pHead);
    exit(0);
 break;
 default:
 cout << "Invalid choice" << endl;
 }
 } while (option != 'q' || option != 'Q');


 
//  Movie* pCur = pHead;
//  Movie* pNext = pHead->next;
//  while (pNext)
//  {
//  delete pCur;
//  pCur = pNext;
//  pNext = pNext->next;
//  }
//  delete pCur;
 system("pause");
}
/*********************************************************************
* Function: Creates single course object and inserts it into
* all_courses[] array.
*
* Parameters:
* course_name (IN): COMSC165
* size (IN): course array size
* all_courses (INOUT): array of courses
* Return: NONE
**********************************************************************/