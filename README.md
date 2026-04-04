<!-- # C--Programming--Notes Slide 5

Two ways an object can exist
You already know how to create an object normally — BankAccount acc("Ali", 101, 5000);. This is called an automatic object. It lives on the stack and dies automatically when its block ends. You have no control over when it dies.

A dynamic object is created with new. It lives on the heap. It does not die until YOU say delete. You are in complete control of its lifetime — it can outlive the block it was created in.
automatic (stack)
BankAccount acc
("Ali",101,5000);
Dies when block } ends. No pointer needed. No delete needed.
dynamic (heap)
BankAccount* p =
new BankAccount
("Ali",101,5000);
Lives until you say delete. Pointer required. delete required.
new and delete with objects
new does two things at once — allocates memory on the heap AND calls the constructor automatically. delete also does two things — calls the destructor AND frees the heap memory.
BankAccount* p = new BankAccount("Ali", 101, 5000);
// constructor called automatically by new

delete p; // destructor called automatically by delete
p = nullptr; // always set to null after delete
If you forget delete — the object stays in memory forever until the program closes. This is a memory leak.
2 · pointers to fields — accessing member variables
Stack vs heap — where the object lives matters
When you use a normal object (stack) you access members with a dot. When you use a pointer to an object (heap or any pointer) you cannot use a dot directly — you must go through the pointer first.
situation how to access member example
normal object dot operator acc.balance
pointer to object arrow operator OR dereference+dot p->balance
Dereference-then-dot notation: (*p).member
When you have a pointer p to an object, *p gives you the object itself. Then you can use a dot on it to access a member. The parentheses around _p are mandatory — without them the dot runs before the star and you get a compile error because you cannot dot a pointer.
BankAccount_ p = new BankAccount("Ali", 101, 5000);

(_p).balance // correct — () force _ to run first
*p.balance // ERROR — dot runs first on a pointer, illegal
The arrow operator -> — shorthand for (*p).member
p->member is identical to (_p).member. It does exactly the same thing but is much cleaner to write and read. Think of -> as "go to the object this pointer points at, then access its member." This is what everyone uses in practice.
BankAccount_ p = new BankAccount("Ali", 101, 5000);

(\*p).balance // old way — dereference then dot
p->balance // same result — arrow is shorthand

cout << p->balance; // prints 5000
3 · pointers to functions — calling member functions via pointer
Calling functions through a pointer
The same arrow operator is used to call member functions through a pointer. There is nothing new here — it is the same -> you use for fields, just followed by a function name and parentheses.
BankAccount\* p = new BankAccount("Ali", 101, 5000);

p->display(); // calls display() on the object p points at
p->deposit(1000); // calls deposit() on the same object
p->getBalance(); // calls getter through the pointer

// equivalent long way:
(_p).display(); // same result — arrow is just cleaner
4 · selecting the constructor
Which constructor gets called depends on what you pass to new
When you write new ClassName, the compiler picks the constructor that matches the arguments you provide — exactly like normal object creation. If you pass nothing, the default constructor runs. If you pass arguments, the matching parameterized constructor runs. If no matching constructor exists, you get a compile error.
BankAccount_ p1 = new BankAccount; // default constructor
BankAccount* p2 = new BankAccount(); // default constructor — () optional
BankAccount* p3 = new BankAccount("Ali",101,5000); // parameterized
If your class only has a parameterized constructor and no default constructor — new BankAccount with no arguments will fail to compile.
5 · classes and pointers — the three essentials
When your class has a pointer member — three things become critical
If your class has a member variable that is a pointer (for example, a dynamically allocated array inside the class), the compiler's default behavior for three operations becomes dangerous. You must write all three yourself:
Destructor — the default destructor does not delete heap memory. You must write one that calls delete on your pointer member, otherwise every object destruction causes a memory leak.
Copy constructor — the default copy constructor copies the pointer address, not the data it points to. Both objects end up sharing the same heap memory. When one is destroyed, the other's pointer becomes dangling.
Overloaded assignment operator — same problem as copy constructor but triggered by = between existing objects. Same fix needed.
If you forget even one of these three, your program will appear to work but will crash, corrupt data, or leak memory in subtle ways.
6 · memory leaks
What a memory leak is and why it matters
A memory leak happens when you allocate heap memory with new and then lose the pointer to it without calling delete. The memory stays occupied — the OS thinks it is still in use — but your program can never reach or free it.
void openAccount() {
BankAccount\* p = new BankAccount("Ali",101,5000);
// forgot delete p here
} // p destroyed here — but heap memory NEVER freed

// call this 1000 times → 1000 objects leaking in memory
In long-running programs (servers, games, ATMs) memory leaks cause the program to gradually consume all available RAM and eventually crash or slow down to a halt.
Fix: always delete before the pointer goes out of scope. No exceptions.
7 · destructors — releasing dynamic memory
Why you must write a destructor when you have pointer members
The default destructor that the compiler provides does nothing with heap memory. It only destroys the pointer variable itself — not what it points to. If your class allocates heap memory in the constructor, you must write a destructor that frees it.
class BankAccount {
private:
int\* transactionHistory; // pointer member
public:
BankAccount(int size) {
transactionHistory = new int[size]; // heap allocated
}
~BankAccount() {
delete[] transactionHistory; // MUST free it here
transactionHistory = nullptr;
}
};
The destructor is called automatically when the object goes out of scope or when delete is called on it. You never call it manually.
8 · copy constructors
What a copy constructor is
A copy constructor is a special constructor that creates a new object as a copy of an existing object. It takes one parameter — a reference to an object of the same class. It must be a reference, not a value, because passing by value would itself call the copy constructor — causing infinite recursion.
BankAccount(const BankAccount& other) {
name = other.name;
accNum = other.accNum;
balance = other.balance;
}
When the copy constructor runs automatically
The compiler calls your copy constructor automatically in three situations — you do not call it yourself:
When you initialize a new object from an existing one: BankAccount b2 = b1;
When you pass an object by value to a function: void process(BankAccount acc)
When a function returns an object by value
BankAccount b1("Ali", 101, 5000);
BankAccount b2 = b1; // copy constructor called here automatically
BankAccount b3(b1); // also calls copy constructor — same thing
Default copy constructor — field by field cloning
If you do not write a copy constructor, the compiler provides one automatically. It copies every field from the source object into the new object one by one. For simple fields (int, double, string) this works perfectly fine. The problem only appears when one of those fields is a pointer.
9 · shallow copy vs deep copy — the most important concept
Shallow copy — the dangerous default
When the compiler copies a pointer member, it copies the address — not the data the pointer points to. Both the original and the copy now hold the same address. They point to the same heap memory. This is called a shallow copy.

The danger: when one object is destroyed, its destructor frees that shared heap memory. The other object's pointer is now dangling — pointing at freed memory. When it is destroyed too, it tries to free the same memory a second time — this is called a double free and crashes the program.
object pointer member heap memory
original b1 0x61fe20 SHARED — both point here
copy b2 0x61fe20
b1 is destroyed → frees 0x61fe20. b2 is destroyed → tries to free 0x61fe20 again → CRASH.
Deep copy — the correct solution
A deep copy does not copy the address. It allocates brand new heap memory for the copy and then copies the actual data into it. Both objects now have their own independent heap memory. Destroying one has no effect on the other. This is done by writing your own copy constructor.
object pointer member heap memory
original b1 0x61fe20 own memory — {1000,2000}
copy b2 0x61ff40 own memory — {1000,2000}
BankAccount(const BankAccount& other) {
name = other.name;
balance = other.balance;
// deep copy — allocate NEW memory, copy data
history = new int[other.size]; // NEW allocation
for(int i=0; i<other.size; i++)
history[i] = other.history[i]; // copy DATA not address
}
Now b1 and b2 each own their own heap memory. Destroying one is completely safe and independent.
10 · copy constructor types
Default vs user-defined copy constructor
default (compiler-provided)
Automatically provided if you write none. Does field-by-field copy. Safe for plain data types. Dangerous when class has pointer members — causes shallow copy.
user-defined
You write it yourself. You control exactly what gets copied. Mandatory when class has pointer members to ensure deep copy and avoid double-free crashes.
Rule: if your class has a pointer member and you write a destructor — always also write a copy constructor. They go together.
11 · arrays of pointers to objects
What an array of pointers to objects is
Instead of storing objects directly in an array, you store pointers to objects. Each element of the array is a pointer, and each pointer points to its own independently created object on the heap. This is different from a dynamic array of objects.
array of objects
BankAccount arr[3];
3 objects stored directly. All created at once. Access with dot: arr[i].member
array of pointers
BankAccount* arr[3];
3 pointers. Each needs its own new. Access with arrow: arr[i]->member
BankAccount* bank[3]; // array of 3 pointers

bank[0] = new BankAccount("Ali", 101, 5000);
bank[1] = new BankAccount("Hamad", 102, 8000);
bank[2] = new BankAccount("Zara", 103, 3000);

// access with arrow because bank[i] is a pointer
cout << bank[0]->getBalance(); // prints 5000
bank[1]->deposit(1000); // deposits into Hamad's account

// each pointer needs its own delete
for(int i=0; i<3; i++) {
delete bank[i];
bank[i] = nullptr;
} -->
