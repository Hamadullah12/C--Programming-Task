#include <iostream>
using namespace std;
class Customer
{
private:
    string name;
    int acc_num, balance;
    // Now to keep record of total balance in bank

    static int totalBalance;
    // static variable for total customer
    static int totalCustomer; // it will be same for all objects
    // it is the attribute of a class.

public:
    Customer(string name, int acc_num, int balance)
    {
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;

        totalCustomer++;
        totalBalance += balance;
        // cout << "Constructor is called and value is incremented " << endl;
    }
    // ~Customer()
    // {
    //     totalCustomer--;
    //     cout << "destructor is decrementing the total customer" << endl;
    //     cout << "Total customer after destructor : " << totalCustomer << endl;
    // }

    void display()
    {
        cout << "NAME           :" << name << endl;
        cout << "ACCOUNT NUMBER :" << acc_num << endl;
        cout << "BALANCE        :" << balance << endl;
    }
    void totalCustomerDisplay()
    {
        cout << "  TOTAL CUSTOMER :" << totalCustomer << endl;
    }
    // function for deposit amount in  bank
    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            totalBalance += amount;
        }
    }
    // Function for withdrawl
    void withdraw(int amount)
    {
        if (amount <= balance && amount > 0)
        {
            balance -= amount;
            totalBalance -= amount;
        }
    }
    // STATIC MEMBER CLASS FUNCTION TO ACCESS FROM PRIVATE DIRECTLY
    static void accessStatic()
    {
        cout << "Total accounts are accesing using static function :" << totalCustomer << endl;
        cout << "Total balance are accessing using static function :" << totalBalance << endl;
    }
};
int Customer::totalCustomer = 0; // no accounts are created now
int Customer::totalBalance = 0;  // total balance is initially zero
int main()
{
    Customer C1("Hamad", 2983948, 4500);
    Customer C2("Ahmed", 3948, 8900);
    // C2.totalCustomerDisplay();
    Customer C3("Jawad", 248, 10);
    // C2.totalCustomerDisplay();
    Customer C4("Ali", 2983948, 8000);
    Customer C5("Hadi", 2983948, 1000);
    C5.totalCustomerDisplay();

    // ACCESSING  STATIC MEMBER OF TOTAL ACCOUNT AND BALANCE FROM STATIC FUNCTION  HERE .
    C5.deposit(10);
    C2.withdraw(5000);
    C5.withdraw(8000);
    Customer::accessStatic();
    return 0;
}