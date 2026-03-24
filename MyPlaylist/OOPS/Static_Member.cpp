// BANK MANAGEMENT SYSTEM — OOP Concepts Practice
// Topics covered:
//   1.  Classes & Objects
//   2.  Access Modifiers (private / public)
//   3.  Constructor & this-> pointer
//   4.  Getter Functions        — like a window, read private data safely
//   5.  Setter Functions        — like a guarded door, change private data with validation
//   6.  Static Member Variables — one shared copy across all objects (bank-wide records)
//   7.  Static Member Functions — belongs to the class, not any object
//   8.  Const Functions         — promises not to modify the object, safe for const objects
//   9.  Const Object            — locked after creation, can only call const functions
//   10. Const Parameters        — protects the passed-in value from being changed inside the function
//   11. Declare inside class, define outside class — class is a clean menu, bodies live below
//   12. Private Helper Functions — internal tools used by the class itself, nobody outside can call them
//   13. Validation Functions    — validateAmount checks if amount is positive,
//                                  validateWithdraw checks if balance is sufficient

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

    // Private helper functions — internal tools used only inside the class.
    // Nobody outside can call these directly.
    // Think of them as a security guard — deposit and withdraw ask the guard,
    // the guard says yes or no, and they act accordingly.
    // This way the validation rule is written once and reused everywhere.
    bool validateAmount(const int amount) const;   // checks if amount is positive
    bool validateWithdraw(const int amount) const; // checks if balance is sufficient

public:
    // Constructor — called automatically when an object is created.
    Customer(string name, int acc_num, int balance);

    // Getters — like a window. You can see the value but not touch it.
    // Always const because they never modify the object.
    string getName() const;
    int getAccNum() const;
    int getBalance() const;

    // Setters — like a guarded door. You can change the value
    // but only if it passes the validation check inside.
    // Return type is void because we are saving, not returning.
    void setName(string newName);
    void setBalance(int newBalance);

    // Deposit & withdraw — change the balance incrementally (not a direct overwrite).
    // Validation is handled by private helper functions — not written directly here.
    // const parameter means the amount passed in is protected from being changed
    // inside the function. The balance itself is free to change — const only
    // protects the parameter. Each call gets its own fresh amount so future
    // deposits and withdrawals work normally.
    void deposit(const int amount);
    void withdraw(const int amount);

    // Display — marked const so it can be called on const objects too.
    void display() const;

    // Static function — belongs to the class itself, not any object.
    // Can only access static variables. Called using Customer::
    // No static keyword when defining outside — only written in the declaration.
    static void accessStatic();
};

// -- STATIC VARIABLE DEFINITIONS --
// Written once outside the class. Must exist before any object is created.

int Customer::totalCustomer = 0;
int Customer::totalBalance = 0;

// -- FUNCTION DEFINITIONS --
// Every function is linked back to the class using Customer::
// The :: is called the scope resolution operator — it means
// "this function belongs to the Customer class."

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
// One-liners kept compact since they just return a single value.
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
// Before adding the amount, it asks validateAmount first.
// If validateAmount returns false, the function stops immediately using return.
// This keeps the logic clean — no nested ifs, just an early exit.
void Customer::deposit(const int amount)
{
    if (validateAmount(amount) == false)
    {
        cout << "Invalid deposit amount." << endl;
        return; // stop here, do not continue
    }

    balance += amount;
    totalBalance += amount;
    cout << "Deposit of " << amount << " successful." << endl;
}

// Withdraw
// Asks two guards before allowing the withdrawal:
//   1. validateAmount  — is the amount positive?
//   2. validateWithdraw — is the balance sufficient?
// Both must pass. If either fails, function stops with an early return.
void Customer::withdraw(const int amount)
{
    if (validateAmount(amount) == false)
    {
        cout << "Invalid withdrawal amount." << endl;
        return;
    }

    if (validateWithdraw(amount) == false)
    {
        cout << "Insufficient balance." << endl;
        return;
    }

    balance -= amount;
    totalBalance -= amount;
    cout << "Withdrawal of " << amount << " successful." << endl;
}

// validateAmount — private helper
// Returns true if amount is positive, false if zero or negative.
// Used by both deposit and withdraw.
// const because it only reads amount, never changes anything.
bool Customer::validateAmount(const int amount) const
{
    if (amount > 0)
        return true;
    else
        return false;
}

// validateWithdraw — private helper
// Returns true if amount does not exceed current balance.
// Returns false if there are insufficient funds.
// const because it only reads balance, never changes anything.
bool Customer::validateWithdraw(const int amount) const
{
    if (amount <= balance)
        return true;
    else
        return false;
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
    // -- creating objects --
    Customer C1("Hamad", 2983948, 4500);
    Customer C2("Hamdan Khattak", 3948, 8900);

    // -- testing deposit and withdraw --
    C2.deposit(2000);
    C2.withdraw(5000);

    // -- testing setters --
    C1.setName("Hamad Khan");
    // C1.setName(""); // rejected — name stays unchanged
    cout << "C1 name after setName       : " << C1.getName() << endl;

    C1.setBalance(6000);
    cout << "C1 balance after setBalance : " << C1.getBalance() << endl;

    // -- displaying full details --
    C1.display();
    C2.display();

    // -- const object --
    // Locked after creation. Only const functions can be called on it.
    const Customer C6("Rihaboo", 1111, 5000);
    cout << "\nC6 name    : " << C6.getName() << endl;
    cout << "C6 balance : " << C6.getBalance() << endl;
    C6.display();
    // C6.deposit(100); // ERROR — deposit() is not const

    // -- static function --
    // Called on the class itself, not on any object
    Customer::accessStatic();

    return 0;
}