#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

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
void    outputTableHeading();
int main()
{
    Student stu1;
    Student stu2;
    Student stu3;

    stu1 = getStudentInfo();
    stu2 = getStudentInfo();
    stu3 = getStudentInfo();

    outputTableHeading();
    outputStudent(1, stu1);
    outputStudent(2, stu2);
    outputStudent(3, stu3);

    serializeDownToFile(stu1, stu2, stu3);

    return 0;
}

Student getStudentInfo()
{
    Student stu;
    char buf[100];
    cout << "Please enter the full name of this student: ";
    getline(cin, stu.fullName);
    cout << "Enter "<< stu.fullName <<"'s birth year, gpa, year of enrollment, address : \n";
    cin >> buf ; stu.birthYear = atoi(buf);
    cin >> buf ; stu.gpa = atof(buf); 
    cin >> stu.year;
    cin >> stu.address;
    cin.ignore();

    return stu;
}

void outputTableHeading()
{
    cout.setf(ios::left);
    cout.width(4);cout << "#";
    cout.width(20); cout << "fullName";
    cout.width(6); cout << "gpa";
    cout.width(10); cout << "birthYear" ;
    cout.width(15); cout << "enrollYear" ;
    cout.width(30); cout << "address" ;
    cout << std::endl;
    cout.unsetf(ios::left);
}

void outputStudent(int sequenceNumber, Student anyStudent)
{
    cout.setf(ios::left);
    cout.width(4); cout << sequenceNumber << ' ';
    cout.width(20); cout << anyStudent.fullName;
    // cout.unsetf(ios::left); 
    cout.width(6); cout << anyStudent.gpa;
    cout.width(10); cout << anyStudent.birthYear ;
    cout.width(15); cout << anyStudent.year ;
    cout.width(30); cout << anyStudent.address ;
    cout << std::endl;
}

void serializeDownToFile(Student stu1, Student stu2, Student stu3)
{
    ofstream fout; // declares an object of type "ofstream"
    fout.open("output.txt"); // reopen file, this time for output
    fout << stu1.fullName << "\n"  << stu1.gpa << "\n"  << stu1.birthYear << "\n"  << stu1.year << "\n"  << stu1.address << "\n" ;
    fout << stu2.fullName << "\n"  << stu2.gpa << "\n"  << stu2.birthYear << "\n"  << stu2.year << "\n"  << stu2.address << "\n" ;
    fout << stu3.fullName << "\n"  << stu3.gpa << "\n"  << stu3.birthYear << "\n"  << stu3.year << "\n"  << stu3.address << "\n" ;
    fout.close(); // done with the file
}