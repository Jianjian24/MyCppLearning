/*********************************************************************
* Name: Ziyu Xue
* Lab 1: Console Programming Basics
* Editor(s) used: CodeBook
* Compiler(s) used: CodeBlock
* Description:
*     This program manages courses taken by a student.
**********************************************************************/
#include <iomanip>
using namespace std;

#include <iostream>
using std::cin;
using std::cout;
using std::ios;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <string>
using std::string;
using std::getline;

#include <cstdlib>

using namespace std;


int main() 
{
char choice; 
while(true) 
{
cout<<"Would you like to perform other calculation?(Y/N)"<<endl; 
cin >> choice; 
if(choice == 'Y'|| choice =='y'){ 
return true; 
}else if(choice =='N'||choice =='n'){ 
return false; 
}
}
return 0; 
}
//Use a boolean: 
int main() 
{
char choice; 
bool run = true; //@stefaanv 
while(run) 
{
// Make your calculation 
cout<<"Would you like to perform other calculation?(Y/N)"<<endl; 
cin >> choice; 
if(choice =='N'||choice =='n'){ 
run = false; 
}
}
return 0; 
}
//Use break to exit your loop: 
int main() 
{
char choice; 
while(true) 
{
// Make your calculation 
cout<<"Would you like to perform other calculation?(Y/N)"<<endl; 
cin >> choice; 
if(choice =='N'||choice =='n'){ 
break; 
}
}
return 0; 
}
//But both these solution will consider any character entered exept N/n as "continue", if you want to avoid this: 
int main() 
{
char choice; 
bool run = true; 
while(run) 
{
// Make your calculation 
do{ 
cout<<"Would you like to perform other calculation?(Y/N)"<<endl; 
cin >> choice; 
choice = tolower(choice);//Put your letter to its lower case 
}while (choice != 'n' && choice != 'y') 
if(choice =='n'){ 
run = false; 
}
}
return 0; 
}
#include <iostream> 
using namespace std; // This is for demonstration purposes ONLY 
// never use this statement in your actual program. preŜ x cout and 
// cin with std:: 
int main() 
{
char choice; 
while(true) 
{
cout<<"Would you like to perform other calculations?(Y/N)"<<endl; 
cin >> choice; 
if(choice == 'Y'|| choice =='y'){ 
continue; // instead of returning, skip to the next iteration 
// and ask again 
}else if(choice =='N'||choice =='n'){ 
break; // return could be used here to break the while loop and 
// terminate the program. But be explicit and use a statement speciŜ cally 
// made for breaking out of loops 
}
}
return 0; 
}
#include <iostream> 
using namespace std; // This is for demonstration purposes ONLY 
// never use this statement in your actual program. preŜ x cout and 
// cin with std:: 
int main() 
{
char choice; 
do { // do everything in the do block while... 
cout <<"Would you like to perform other calculations?(Y/N)"<< endl; 
cin >> choice; 
if (choice != 'Y' and choice != 'y' and choice != 'N' and choice != 'n') // if needed add input 
cout << choice << " is not a valid option. Try agian" << endl; // validation 
} while (choice !='N' && choice !='n'); // the user input does not equal 'N'andr 'n' 
return 0; 
}

