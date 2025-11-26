#include <iostream>
#include <ctime>
using namespace std;

void printDate()
{
    cout << ctime(0); // prints current date & time in one line
}

int main()
{
    printDate(); // function call
    return 0;
}
