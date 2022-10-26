#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::getline;
using std::string;

#include <cstdlib> // for atoi and atof

struct Student
{
  int age;
  string name;
  double gpa; // grade point average
};

// function prototypes
void outputTableHeading();
void outputStudent(int, Student);
Student inputStudent();

int main()
{
  Student jack;
  jack.age = 18;
  jack.name = "Jack Smith";
  jack.gpa = 2.89;

  Student jill;
  jill.age = 19;
  jill.name = "Jill Smith";
  jill.gpa = jack.gpa + 1.0; // a whole letter grade above Jack!

  // get some user input about a 3rd student
  Student classMate; // a classmate of Jack and Jill
  cout << "Enter the name of Jack and Jill's classmate: ";
  getline(cin, classMate.name);

  string buf;
  cout << "And what's " << classMate.name << "'s age? ";
  cin >> buf; classMate.age = atoi(buf.c_str());
  //cin.ignore(1000, 10); // not required, why ?

  cout << "And now " << classMate.name << "'s grade point average: ";
  cin >> buf; classMate.gpa = atof(buf.c_str());
  //cin.ignore(1000, 10);

  // now output the three students in a nice table
  outputTableHeading();
  outputStudent(1, jack);
  cout << "in main: " << jack.age << endl;
  outputStudent(2, jill);
  outputStudent(3, classMate);

  Student alexa;
  alexa = inputStudent();

  return 0;
}

void outputTableHeading()
{
  cout << "   # Name                 Age Grade Point Average\n";
  cout << "---- -------------------- --- -------------------\n";
}

void outputStudent(int sequenceNumber, Student anyStudent)
{
  cout.width(4); cout << sequenceNumber << ' ';
  cout.setf(ios::left); cout.width(20); cout << anyStudent.name;
  cout.unsetf(ios::left); cout.width(4); cout << anyStudent.age;
  cout.width(6); cout << anyStudent.gpa << endl;

  anyStudent.age = 99;  // can you change anyStudent's data?
  cout << "in func: " << anyStudent.age << endl;
}


Student inputStudent()
{
    Student newStudent;

    // Read studen't data

    return newStudent;
}




