// BANK MANAGEMENT SYSTEM — OOP Concepts Practice
// Topics covered:
//   1.  Classes & Objects
//   2.  Access Modifiers (private / public)
//   3.  Constructor & this-> pointer
//   4.  Getter Functions
//   5.  Setter Functions
//   6.  Static Member Variables
//   7.  Static Member Functions
//   8.  Const Functions
//   9.  Const Object
//   10. Const Parameters
//   11. Declare inside class, define outside class

#include <iostream>
using namespace std;

// -- CLASS DEFINITION --
// Only declarations live here. All bodies are written below the class.
// Think of this section as a menu — it tells you what the class can do,
// not how it does it.

class Customer
{
private:
    // These variables are locked inside the class.
    // Nobody outside can read or change them directly.
    string name;
    int acc_num;
    int balance;

    // Static variables are shared across ALL objects.
    // Only one copy exists in memory — these are bank-wide records.
    static int totalBalance;
    static int totalCustomer;
    // Helper Functions
    bool validateAmount(const int amount) const;
    bool validateWithdraw(const int amount) const;

public:
    // Constructor — called automatically when an object is created.
    Customer(string name, int acc_num, int balance);

    // Getters like a window. You can see the value but not touch it.
    // Always const because they never modify the object.
    string getName() const;
    int getAccNum() const;
    int getBalance() const;

    // Setters — like a guarded door. You can change the value
    // but only if it passes the validation check inside.
    void setName(string newName);
    void setBalance(int newBalance);

    // Deposit & withdraw — these change the balance incrementally.
    // const parameter means the amount passed in cannot be
    // accidentally changed inside the function. The balance itself
    // is free to change — const only protects the parameter.
    void deposit(const int amount);
    void withdraw(const int amount);

    // Display — marked const so it can be called on const objects too.
    void display() const;

    // Static function — belongs to the class itself, not any object.
    // Can only access static variables. Called using Customer::
    static void accessStatic();
};

// -- STATIC VARIABLE DEFINITIONS --
// Written once outside the class. Must exist before any object is created.

int Customer::totalCustomer = 0;
int Customer::totalBalance = 0;

// -- FUNCTION DEFINITIONS --
// Every function is linked back to the class using Customer::
// This is called the scope resolution operator.

// Constructor
// this-> is used because the parameter names are the same as
// the private variable names. Without it, the compiler gets confused.
Customer::Customer(string name, int acc_num, int balance)
{
    this->name = name;
    this->acc_num = acc_num;
    this->balance = balance;

    totalCustomer++;         // one more customer added to bank
    totalBalance += balance; // add their opening balance to bank total
}

// Getters
// One-liners kept compact since they just return a value.
string Customer::getName() const { return name; }
int Customer::getAccNum() const { return acc_num; }
int Customer::getBalance() const { return balance; }

// Setter — name
// Rejects empty strings. If valid, saves directly into the private variable.
void Customer::setName(string newName)
{
    if (newName != "")
        name = newName;
    else
        cout << "Invalid: name cannot be empty." << endl;
}

// Setter — balance
// This is a direct overwrite, not an incremental change.
// We calculate the difference first so totalBalance stays accurate.
// Example: old balance = 4500, newBalance = 6000
//   diff = 6000 - 4500 = 1500
//   totalBalance += 1500  (not += 6000, that would be wrong)
void Customer::setBalance(int newBalance)
{
    if (newBalance >= 0)
    {
        int diff = newBalance - balance;
        totalBalance += diff;
        balance = newBalance;
        cout << "Balance updated successfully." << endl;
    }
    else
    {
        cout << "Invalid: balance cannot be negative." << endl;
    }
}

// Deposit
// Adds to balance incrementally. const on amount means the value
// passed in is protected — but balance and totalBalance are free to change.
// Each call gets its own fresh amount so future deposits work normally.
void Customer::deposit(const int amount)
{
    if (amount > 0)
    {
        balance += amount;
        totalBalance += amount;
        cout << "Deposit of " << amount << " successful." << endl;
    }
    else
    {
        cout << "Invalid deposit amount." << endl;
    }
}

// Withdraw
// Subtracts from balance incrementally. Checks two things:
//   1. amount must be positive
//   2. amount must not exceed current balance
void Customer::withdraw(const int amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        totalBalance -= amount;
        cout << "Withdrawal of " << amount << " successful." << endl;
    }
    else
    {
        cout << "Invalid withdrawal: insufficient funds or bad amount." << endl;
    }
}

// Helper Functions
bool Customer::validateAmount(const int amount) const
{
    if (amount > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Customer::validateWithdraw(const int amount) const
{
    if (amount <= balance)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Display
// const function — only reads data, never changes anything.
// This is why a const object can safely call it.
void Customer::display() const
{
    cout << "\nName           : " << name << endl;
    cout << "Account Number : " << acc_num << endl;
    cout << "Balance        : " << balance << endl;
}

// Static function
// No static keyword here — only written inside the class declaration.
// Can only access totalCustomer and totalBalance (static variables).
void Customer::accessStatic()
{
    cout << "\nTotal Customers : " << totalCustomer << endl;
    cout << "Total Balance   : " << totalBalance << endl;
}

// -- MAIN FUNCTION --

int main()
{
    // Creating regular customer objects
    Customer C1("Hamad", 2983948, 4500);
    Customer C2("Ahmed", 3948, 8900);

    // Deposit and withdraw — const parameter, but balance changes freely
    C2.deposit(2000);
    C2.withdraw(5000);

    // Reading private data safely through getters
    cout << "\nC1 name    via getter : " << C1.getName() << endl;
    cout << "C1 balance via getter : " << C1.getBalance() << endl;

    // Setter for name — valid call updates, invalid call is rejected
    C1.setName("Hamad Khan");
    // C1.setName(""); // rejected — name stays "Hamad Khan"
    cout << "C1 name after setName       : " << C1.getName() << endl;

    // Setter for balance — uses diff trick internally
    C1.setBalance(6000);
    cout << "C1 balance after setBalance : " << C1.getBalance() << endl;

    // Display full details
    C1.display();
    C2.display();

    // Const object — locked after creation
    // Only const functions (getters, display) can be called on it
    const Customer C6("Zara", 1111, 5000);
    cout << "\nC6 name    : " << C6.getName() << endl;
    cout << "C6 balance : " << C6.getBalance() << endl;
    C6.display();
    // C6.deposit(100); // ERROR — deposit() is not const, cannot modify a const object

    // Static function — called on the class itself, not on any object
    Customer::accessStatic();

    return 0;
}