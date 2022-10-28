#include <cstring>

#include <iomanip>
using namespace std;

#include <iostream>
using std::cin;
using std::cout;
using std::ios;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::getline;
using std::string;
#include <iostream>

#include <cstdlib>

struct expenses
{
    char desc[1024];
    double amount;
};

struct Course {
    string name;
    int units;
    int year;
    char grade;
};

void show_all(expenses *exp, int n)
{
    int i = 0;
    if (n == 0)
        cout << "\nNo expense entry available\n"
             << endl;
    else
    {
        cout << "Expenses: " << endl;
        while (i < n)
        {
            cout << "Amount(" << exp[i].amount << ") DESC(" << exp[i].desc << ")" << endl;
            i++;
        }
    }
}

void spend(expenses *exp, int n)
{
    double amount;
    string desc;

    // getline(cin, exp[n].desc);
    cin.getline(exp[n].desc, 1024);
    while (1)
    {
        cout << "Please enter the description for the expense: ";
        cin.getline(exp[n].desc, 1024);
        // getline(cin, exp[n].desc);
        if (strlen(exp[n].desc) != 0)
            break;
        cout << "Invalid Description��Description cannot be empty" << endl;
    }

    char am[100];
    while (1)
    {
        cout << "Enter the amount please: ";
        cin >> am;
        exp[n].amount = atof(am);
        if (exp[n].amount > 0)
        {
            char c;
            while ((c = getchar()) != '\n'); // clear buffer before break
            break;
        }
        cout << "Invalid amount. Amount cannot be negative or string. Please try it again." << endl;
    }

    cout << "Amount(" << exp[n].amount << ") DESC(" << exp[n].desc << ")" << endl;
}

void search_amount(expenses *exp, int n)
{
    int i = 0, search;
    cout << "Please enter the amount:";
    cin >> search;
    while (i < n)
    {
        if (exp[i].amount >= search)
        {
            cout << "Amount(" << exp[i].amount << ") DESC(" << exp[i].desc << ")" << endl;
        }
        i++;
    }
}

void search_desc(expenses *exp, int n)
{
    string search;
    cout << "Please enter the search string: ";
    cin >> search;
    int i = 0, j, k;
    j = 0;
    while (j < search.length())
    {
        search[j] = tolower(search[j]);
        j++;
    }

    while (i < n)
    {
        string d_str = exp[i].desc;
        j = 0;
        while (j < strlen(exp[i].desc))
        {
            d_str[j] = tolower(d_str[j]);
            j++;
        }
        if (search.length() > d_str.length())
        {
            cout << "Not Found!" << endl;
            return;
        }
        
        if (d_str.find(search) != string::npos)
        {
            cout << "AMOUNT(" << exp[i].amount << ") DESC(" << exp[i].desc << ")" << endl;
            return;
        }
        else
        {
            cout << "Not Found!" << endl;
            return;
        }    

        i++;
    }
}
void print_id(string lab_desc) 
{
    cout << "Alexa Amazon\n";
    cout << lab_desc << endl;
    cout << "Editor(s) used: CodeBlock\n";
    cout << "Compiler(s) used: CodeBlock\n";
    cout << "File: " << __FILE__ << "\n";
    cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}
int main()
{
    int option, n = 0;
    expenses exp[100];
    print_id("Lab 5A");

    cout << "Welcome to expense tracker.\n"
         << endl;
    do
    {
        cout << "\nExpense Tacking Menu:" << endl;
        cout << "\t1. show all\n\t2. spend\n\t3. search expenses containing this string\n\t4. search expenses with greater than or equal to this amount\n\t5. exit" << endl;
        cout << "Enter your option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            show_all(exp, n);
            break;
        case 2:
            spend(exp, n);
            n++;
            break;
        case 3:
            search_desc(exp, n);
            break;
        case 4:
            search_amount(exp, n);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (option != 5);
}