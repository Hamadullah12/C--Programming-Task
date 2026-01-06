// #include <iostream>
// using namespace std;
// int main()
// {
//     // Printing table of 6 using do while loop

//     int i = 1;
//     // int j = 6;
//     do
//     {
//         // cout << "Table of 6 is " << j << " x " << i << " = " << j * i << endl;
//         // cout << i * 6 << endl;

//         i++;
//     } while (i <= 10);
// }

// Even And Odd number finder
// #include <iostream>
// using namespace std;
// int main()
// {
//     int i = 1;
//     do
//     {
//         if (i % 2 == 0)
//         {
//             cout << "Even" << i << endl;
//         }
//         else
//         {
//             cout << "Odd " << i << endl;
//         }
//         i++;
//     } while (i <= 30);
// }

// Count down
// #include <iostream>
// using namespace std;
// int main()
// {
//     int i = 10;
//     do
//     {
//         cout << " The coutdown starts .." << i << endl;
//         i--;
//     } while (i >= 1);
// }
// ========================================================================
// Day 2 Break and Continue
// Break : When we want to break the loop in runing so we use break, it will exit the loop.
// #include <iostream>
// using namespace std;
// int main()
// {
//     for (int i = 0; i < 5; i++)
//     {
//         if (i == 2)
//         {
//             break;
//         }
//         cout << i << endl;
//     }
//     return 0;
// }
// Continue:THe purpose of using continue keyword is that it will skip the value where continue is applied
// and complete the loop when the continue value condition comes true so it didnt go down and print the value
// it directly goes up to the loop . it will not break the loop its use to skip the value which we dont want
// as in the below program the even numbers are skiped without disturbing the loop
// #include <iostream>
// using namespace std;
// int main()
// {
//     for (int i = 0; i < 20; i++)
//     {
//         if (i % 2 == 0)
//         {
//             continue;
//         }
//         cout << i << endl;
//     }

//     return 0;
// }

// Practice program

// #include <iostream>
// using namespace std;
// int main()
// {
//     int num;
//     for (int i = 0; i < 10; i++)
//     {
//         cout << "input any number?" << endl;
//         cin >> num;
//         if (num < 0)
//         {
//             cout << "You entered negative value so this is skipped " << endl;
//             continue;
//         }
//         else if (num == 0)
//         {
//             cout << "You entered 0 so the loop is break" << endl;
//             break;
//         }
//     }
//     cout << "You entered" << num << endl;
//     return 0;
// }

// ========================================================================
// POINTERS : Is a data type which store the address of other data types "&" address of operator "*" is a dereference  operator

// #include <iostream>
// using namespace std;
// int main()
// {
//     int a = 5;
//     int *b = &a;
//     cout << "Address of a (&a): " << &a << endl;                // here the address will be same as we assign them to each other "0x5ffe94"
//     cout << "Value stored in b (address of a):  " << b << endl; // here the address will be same as we assign them to each other "0x5ffe94"
//     cout << "the value of a in b is = " << *b << endl;          // Now if we want to find the value at the addres of b we will use derefence operator  "*".

//     // cout << "The value of b on address a is " << *b << endl;

//     // POINTER TO POINTER
//     int **c = &b;

//     cout << "Address of b (&b): " << &b << endl;

//     cout << "Value stored in c (address of b): " << c << endl;
//     cout << "Value at *c (same as b, address of a): " << *c << endl;
//     cout << "Value at **c (value of a): " << **c << endl;

//     return 0;
// }

// ARRAYS AND POINTERS
// ARRAY :It is a collection of items of similar type stored in a contingous memory locations.

#include <iostream>
using namespace std;
int main()
{
    int marks[5] = {23, 43, 54, 23, 65};
    int mathMarks[5] = {456, 234, 554, 231, 653};
    cout << "These are math marks array" << endl;
    // Here i want to change the value of some items from array.
    cout << "I change the value of some array  items " << endl;
    mathMarks[0] = 1;
    mathMarks[1] = 2;
    mathMarks[2] = 3;
    cout << mathMarks[0] << endl
         << mathMarks[1] << endl
         << mathMarks[2] << endl
         << mathMarks[3] << endl
         << mathMarks[4] << endl;
    cout << "These are marks arry" << endl;

    // here i also want to change the value of some items from array.
    cout << "I change the value of some array  items " << endl;

    marks[0] = 4;
    marks[1] = 5;
    marks[2] = 6;
    cout << marks[0] << endl
         << marks[1] << endl
         << marks[2] << endl
         << marks[3] << endl
         << marks[4] << endl;

    return 0;
}