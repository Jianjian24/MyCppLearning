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
  int birthYear;
  double gpa;
  string fullName;
  string address;
  string year;
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

    return 0;
}

Student getStudentInfo()
{
    Student stu;
    char buf[100];
    cout << "Please enter the full name of this student: ";
    getline(cin, stu.fullName);
    cout << "Enter "<< stu.fullName <<"'s birth year, gpa, year of enrollment, address : \n";
    cin >> stu.birthYear ; stu.birthYear = atoi(buf); cin.ignore(1000, 100);
    cin >> stu.gpa ; stu.gpa = atof(buf); cin.ignore(1000, 100);
    cin >> stu.address;
    cin >> stu.year;

    return stu;
}



void outputStudent(int sequenceNumber, Student anyStudent)
{

}

void serializeDownToFile(Student stu1, Student stu2, Student stu3)
{
  
}