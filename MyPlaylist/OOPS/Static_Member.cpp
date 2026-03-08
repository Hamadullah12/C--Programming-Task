#include <iostream>
using namespace std;
class Customer
{
private:
    string name;
    int acc_num, balance;

    // static variable for total customer
    static int totalCustomer;

public:
    Customer(string name, int acc_num, int balance)
    {
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;
        totalCustomer++;
        cout << "Constructor is called and value is incremented " << endl;
    }
    void display()
    {
        cout << "NAME           :" << name << endl;
        cout << "ACCOUNT NUMBER :" << acc_num << endl;
        cout << "BALANCE        :" << balance << endl;
        cout << "  TOTAL CUSTOMER :" << totalCustomer << endl;
    }
};
int Customer::totalCustomer = 0;
int main()
{
    Customer C1("Hamad", 2983948, 1000);
    Customer C2("Ahmed", 3948, 100);
    Customer C3("Jawad", 248, 10);

    C1.display();
    Customer C4("Ali", 2983948, 1000);
    C4.display();
    Customer C5("Hadi", 2983948, 1000);
    C5.display();
    return 0;
}