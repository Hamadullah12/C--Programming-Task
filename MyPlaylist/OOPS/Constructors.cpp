#include <iostream>
using namespace std;
class Customer
{
    string name;
    int acc_num;
    int balance;

public:
    // Default Constructor:
    Customer()
    {
        name = "Hamad";
        acc_num = 189383;
        balance = 67398;
    }
    // PARAMETARIZED CONSTRUCTOR:
    Customer(string name, int acc_num, int balance)
    {
        // this mehod stores the address of main object
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;
    }
    void Display()
    {
        cout << name << " " << acc_num << " " << balance << endl;
    }
};
int main()
{
    Customer A1;
    Customer A2("Hmd", 3345, 1987);
    A1.Display();
    A2.Display();
    return 0;
}