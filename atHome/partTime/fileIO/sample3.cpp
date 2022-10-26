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
  int age;
  string name;
  double gpa;
};

int main()
{
  // default in case TXT file does not yet exist
  Student a = {0, "unknown", 0}; 

  // serialize up
  ifstream fin; // declares an object
  fin.open("studentObjects.txt");
  if (fin.good()) // only read from the file if it exists!
  {
    // restore student object "a"
    fin >> a.age; fin.ignore(1000, 10);
    getline(fin, a.name);
    fin >> a.gpa; fin.ignore(1000, 10);
  }
  fin.close(); // done with the file -- for input, anyway...

  // output the current state of the student record
  cout << a.name << " is " << a.age << " years old, with a " << a.gpa << " GPA.\n";

  // edit the student record
  char buf[10];
  cout << "Enter a new name for " << a.name << ": ";
  getline(cin, a.name);
  cout << "Enter " << a.name << "'s age: ";
  cin >> buf; a.age = atoi(buf); cin.ignore(1000, 10);
  cout << "Enter " << a.name << "'s GPA: ";
  cin >> buf; a.gpa = atof(buf);

  // serialize down
  ofstream fout; // declares an object of type "ofstream"
  fout.open("studentObjects.txt"); // reopen file, this time for output
  fout << a.age << "\n" << a.name << "\n" << a.gpa << "\n";
  fout.close(); // done with the file
}