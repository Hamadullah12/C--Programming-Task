// SETTER FUNCTION: A function used to update private data safely. It usually includes logic to validate the input (e.g., ensuring a balance isn't negative).
// GETTER FUNCTION: A "read-only" function that returns the value of a private variable so it can be seen outside the class without being changed.
// STATIC MEMBER: A variable shared by all objects of the class. Only one copy exists in memory for the whole class.
// STATIC FUNCTION: A tool that belongs to the class itself. It can be called using the class name and can ONLY access static variables.
// CONST KEYWORD (Three Ways):
//    1. Const Function: A member function that promises not to modify any variables of the object.
//    2. Constant Parameter: A variable passed into a function that cannot be changed by that function.
//    3. Const Object: An object that is "locked" and can only call const functions; its data cannot be changed after creation.
// FOR LONG COMMENTS JUST DO ALT+Z.
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

    void display() const
    {
        cout << "NAME           :" << name << endl;
        cout << "ACCOUNT NUMBER :" << acc_num << endl;
        cout << "BALANCE        :" << balance << endl;
    }
    void totalCustomerDisplay() const
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
            cout << "Withdrawl of amount is done" << amount << endl;
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
    // C5.totalCustomerDisplay();
    // ACCESSING  STATIC MEMBER OF TOTAL ACCOUNT AND BALANCE FROM STATIC FUNCTION  HERE .
    C5.deposit(19870);
    C2.withdraw(5000);
    C5.withdraw(10870);
    C5.display(); // here when you are depositing and withdrawing an amount so before checking it make sure that you display after the amount process happen other wise no change will be seen while withdreawl will be done

    Customer::accessStatic();
    return 0;
}

// == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == =
