/*
Binary file I/Os example.

*/
#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;  // need this for file input
using std::ofstream;   // need this for file output
using std::fstream;

#include <iostream>
using std::ios;

#include <string>
using std::string;

#include <cstring>  // for strlen

int main(int argc, char *argv[])
{
  string file_name = "random.dat";

  // Create the binary file
  ofstream outfile;
  outfile.open(file_name, ios::out | ios::binary);
  if(!outfile.good()) {
    cout << "Cannot open file.\n";
    return 1;
  }

  char line[] = "12345678901234567890";
  // Skip to 10th byte and write a char.
  outfile.write(line, strlen(line));
  outfile.seekp(10, ios::beg);
  outfile.put('X');
  outfile.close();


  ifstream infile;
  infile.open(file_name, ios::in | ios::binary);
  if(!infile.good()) {
     cout << "Cannot open file: " << file_name << endl;;
     return 1;
  }

  char ch;

  cout << "From offset 5 bytes to the end: " << endl;
  infile.seekg(5, ios::beg);
  while(infile.get(ch))
     cout << ch;

  cout << "\n Done " << endl;
  return 0;
}

