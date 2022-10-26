#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::getline;
using std::string;

#include <cstdlib> // for atoi and atof

struct Student
{
  string fullName;
  double gpa;
  string address;
  string year;
  int birthYear;
};

Student getStudentInfo();
void    outputStudent(int sequenceNumber, Student anyStudent);
void    serializeDownToFile(Student stu1, Student stu2, Student stu3);

int main()
{
    Student stu1;
    Student stu2;
    Student stu3;

    stu1 = getStudentInfo();
    stu2 = getStudentInfo();
    stu3 = getStudentInfo();

    outputStudent(1, stu1);
    outputStudent(2, stu2);
    outputStudent(3, stu3);
}