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
   string name;
  int age;

  double gpa;
};

int main()
{
  const int CAPACITY = 100;
  Student students[CAPACITY]; 
  int size = 0;

  // serialize up
  ifstream fin; 
  fin.open("studentObjects.txt");
  // Read while not EOF or error
  while (fin.good())
  {
    string buf;
    getline(fin, buf);
    if (buf == "EOF") break;
    else {
        // Restore student object
  students[size].name = buf;
        fin >> students[size].age;
  fin.ignore(1000, 10);
        fin >> students[size++].gpa;
  fin.ignore(1000, 10);
 }
  }
  fin.close( );
  
  return 0;
}