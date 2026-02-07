#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    cout << "Please put first number. " << endl;
    cin >> num1;
    cout << "Please put second number. " << endl;
    cin >> num2;
    char op;
    cout << "Select any operator +,-,*,/" << endl;
    cin >> op;
    if (op == '+')
    {
        cout << "result of num1 and num2 is : " << num1 + num2 << endl;
    }
    else if (op == '-')
    {
        cout << "result of num1 and num2 is :" << num1 - num2 << endl;
    }
    else if (op == '*')
    {
        cout << "result of num1 and num2 is : " << num1 * num2 << endl;
    }
    else if (op == '/')
    {
        if (num2 != 0)
        {
            cout << "result of num 1 and num2 after divisions is :" << num1 / num2 << endl;
        }
        else
        {
            cout << "cannot divide by zero" << endl;
        }
    }
    return 0;
}