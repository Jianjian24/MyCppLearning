#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

struct Student
{
  int age;
  string name;
};

int main()
{
  Student john; // declare the struct-based object
  john.age = 21; // assigning a value to an attribute
  john.name = "Joseph Doe";

  cout << "Here's our new student:\n";
  cout << "Name: " << john.name << endl;
  cout << "Age:  " << john.age << " years\n";
  
  Student jane {19, "Jane Smith"};  // C++ 11 only
  // jane = {19, "Jane Smith"};      // C++ 11 only
  cout << "Name: " << jane.name << endl;
  cout << "Age:  " << jane.age << " years\n";
  
  Student joe = {23};   // incomplete initialization, it's OK
  
  Student matt = {};  // What is it?
  
}