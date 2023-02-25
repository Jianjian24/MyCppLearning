#include <iostream>
#include <deque>
using namespace std;

int main()
{
   deque <int> c1;
   
   c1.push_back( 10 );
   c1.push_back( 20 );
   c1.push_back( 30 );

   c1.resize(4);
   cout << "The size of c1 is: " << c1.size( ) << endl;
   cout << "The value of the last element is " << c1.back( ) << endl;

//    c1.resize( 5 );
//    cout << "The size of c1 is now: " << c1.size( ) << endl;
//    cout << "The value of the last element is now " << c1.back( ) << endl;

//    c1.resize( 2 );
//    cout << "The reduced size of c1 is: " << c1.size( ) << endl;
//    cout << "The value of the last element is now " << c1.back( ) << endl;
    return 0;
}