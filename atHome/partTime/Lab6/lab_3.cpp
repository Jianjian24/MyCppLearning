#include <iostream>
using std::cin;
using std::cout;
using std::ios;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iomanip>

#include <algorithm>
using std::swap;

#include <string>
using std::string;

struct Student
{
  string  name;
  int     age;
  float   gpa;
  Student *next;
};

void printStudents(Student *);

int main()
{
  Student *firstStudentPtr = NULL; // an empty linked list, C++11: nullptr

  ifstream fin;
  fin.open("studentObjects.txt");

  cout << " before open file. \n";
  // Create nodes from input file
  while (fin.good())
  {
    string buf;
    getline(fin, buf);
    cout << "buff: " << buf << endl;

    if (buf == "EOF") break;

    Student *temp = new Student;
    temp->name = buf;

    fin >> temp->age;
 fin >> temp->gpa;
 fin.ignore(200, 10);
 cout << "age: " << temp->age << "\t gpa: " << temp->gpa << endl;

    temp->next = firstStudentPtr;
    firstStudentPtr = temp;
  }
  fin.close( );

  // Print student list.  Note: list size is not required
  printStudents(firstStudentPtr);

  return 0;
}

/*************************************************************************
* Purpose:  Sort the list in alphabetical order
* Parameter:
*   firstStudentPtr (IN) - pointer to the head of the list
*
* Return: None
**************************************************************************/
void sortList(Student *firstStudentPtr)
{
  for (Student *p = firstStudentPtr; p; p = p->next)
    for (Student* q = p->next; q; q = q->next)
      if (q->name < p->name)
   {
        // swap entire content
  swap(*p, *q);

        // swap ptr to original value
  swap(p->next, q->next);
   }
}

/*************************************************************************
* Purpose:  Print student info in the linked list
* Parameter:
*   firstStudentPtr (IN) - pointer to the head of the list
*
* Return: None
**************************************************************************/
void printStudents(Student *firstStudentPtr)
{
  int index = 1;
  cout << "\nSeq.  Name             Age    GPA  " << endl;
  for (Student *nodePtr = firstStudentPtr; nodePtr; nodePtr = nodePtr->next, index++)
  {
   cout.width(5);
   cout << std::left << index;
   cout.width(18);
   cout << nodePtr->name;
   cout.width(6);
   cout << nodePtr->age;
   cout.setf(ios::fixed); cout.precision(2);

   cout << nodePtr->gpa << endl;
  }
}

