#include <iostream>
#include <string>
using namespace std;
struct StudData
{
    string name;
    int reg;
    int grade;
};

int main()
{
    StudData Data1 = {"Hamad Ullah", 2032, 14};
    cout << "Name                  :" << Data1.name << endl;
    cout << "Registration Number   :" << Data1.reg << endl;
    cout << "Grade                 :" << Data1.grade << endl;

    return 0;
}