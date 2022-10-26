#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;  // need this for file input
using std::ofstream;   // need this for file output

#include <string>
using std::string;

struct Student
{
  int age;
  string name;
  double gpa;
};

int main()
{
  Student john; // declare the struct-based object
  john.age = 21; // assigning a value to an attribute
  john.name = "Joseph Doe";
  john.gpa = 3.8;

  cout << "Here's our new student:\n";
  cout << "Name: " << john.name << endl;
  cout << "Age:  " << john.age << " years\n";
  cout << "GPA:  " << john.gpa << endl;
  

  Student jane {18, "Jane Smith", 3.4};  // C++ 11 only
  //jane = {19, "Jane Smith"};      // C++ 11 only
  cout << "Name: " << jane.name << endl;
  cout << "Age:  " << jane.age << " years\n";
  cout << "GPA:  " << jane.gpa << endl;
  
  // serialize down
  ofstream fout; // declares an object of type "ofstream"
  fout.open("studentObjects.txt");
  fout << john.age << "\n" << john.name << "\n" << john.gpa << "\n";
  fout << jane.age << "\n" << jane.name << "\n" << jane.gpa << "\n";
  fout << "EOF\n"; // stands for end-of-file
  
  fout.close(); // done with the file
}