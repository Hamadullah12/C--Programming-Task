#include <iostream>
using namespace std;
void printHello()
{
    cout << "hello world"<<endl;
}
void printhi()
{
    cout << "Starting print hi" << endl;
    printHello();
    cout << "Ending Print hi funtion" << endl;
}
int main()
{
    printHello();
    printhi();
    return 0;
}