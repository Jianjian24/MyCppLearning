#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::getline;
using std::string;

struct Student
{
  double gpa;
  string address;
  string year;
  string fullName;
  int birthYear;
};


int main()
{
  
  Student jane = {4.0, "Concord, CA", "Freshman", "Jane Doe", 1995}; // ok in C, C++, and C++11
  cout << "Student info: \n";
  cout << jane.fullName << " " << jane.address << " " << jane.birthYear << endl; 
 
  Student john {4.0, "Concord, CA", "Freshman", "John Smith", 1997}; // no equals, ok in C++11 only
  cout << john.fullName << " " << john.address << " " << jane.birthYear << endl;
   
  jane = {3.9, "Walnut Creek, CA", "Sophomore", "Jane Doe", 1995}; // reassignment, ok in C++11 only
  cout << jane.fullName << " " << jane.address << " " << jane.birthYear << endl; 
   
  Student joe = {}; // OK
 
   
   return 0;
}