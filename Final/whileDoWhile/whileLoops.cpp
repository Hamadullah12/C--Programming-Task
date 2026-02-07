// #include <iostream>
// using namespace std;

// int main()
// {
//     int choice;

//     while (true)
//     {
//         cout << "   Simple Menu-Driven System  " << endl;
//         cout << "1. Add Two Numbers" << endl;
//         cout << "2. Subtract Two Numbers" << endl;
//         cout << "3. Check Even or Odd" << endl;
//         cout << "4. Display Multiplication Table" << endl;
//         cout << "5. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;

//         if (choice == 1)
//         {
//             int a, b;
//             cout << "Enter first number: ";
//             cin >> a;
//             cout << "Enter second number: ";
//             cin >> b;
//             cout << "Result: " << a + b << endl;
//         }
//         else if (choice == 2)
//         {
//             int a, b;
//             cout << "Enter first number: ";
//             cin >> a;
//             cout << "Enter second number: ";
//             cin >> b;
//             cout << "Result: " << a - b << endl;
//         }
//         else if (choice == 3)
//         {
//             int num;
//             cout << "Enter a number: ";
//             cin >> num;
//             if (num % 2 == 0)
//                 cout << num << " is Even." << endl;
//             else
//                 cout << num << " is Odd." << endl;
//         }
//         else if (choice == 4)
//         {
//             int num;
//             cout << "Enter a number for multiplication table: ";
//             cin >> num;
//             for (int i = 1; i <= 10; i++)
//             {
//                 cout << num << " x " << i << " = " << num * i << endl;
//             }
//         }
//         else if (choice == 5)
//         {
//             cout << "Exiting program... Goodbye!" << endl;
//             break;
//         }
//         else
//         {
//             cout << "Invalid choice! Please try again." << endl;
//         }
//     }

//     return 0;
// }

// DO WHILE LOOP
// #include <iostream>
// using namespace std;

// int main()
// {
//     int choice;

//     do
//     {
//         cout << "   Simple Menu-Driven System  " << endl;
//         cout << "1. Add Two Numbers" << endl;
//         cout << "2. Subtract Two Numbers" << endl;
//         cout << "3. Check Even or Odd" << endl;
//         cout << "4. Display Multiplication Table" << endl;
//         cout << "5. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;

//         if (choice == 1)
//         {
//             int a, b;
//             cout << "Enter first number: ";
//             cin >> a;
//             cout << "Enter second number: ";
//             cin >> b;
//             cout << "Result: " << a + b << endl;
//         }
//         else if (choice == 2)
//         {
//             int a, b;
//             cout << "Enter first number: ";
//             cin >> a;
//             cout << "Enter second number: ";
//             cin >> b;
//             cout << "Result: " << a - b << endl;
//         }
//         else if (choice == 3)
//         {
//             int num;
//             cout << "Enter a number: ";
//             cin >> num;
//             if (num % 2 == 0)
//                 cout << num << " is Even." << endl;
//             else
//                 cout << num << " is Odd." << endl;
//         }
//         else if (choice == 4)
//         {
//             int num;
//             cout << "Enter a number for multiplication table: ";
//             cin >> num;
//             for (int i = 1; i <= 10; i++)
//             {
//                 cout << num << " x " << i << " = " << num * i << endl;
//             }
//         }
//         else if (choice == 5)
//         {
//             cout << "Exiting program... Goodbye!" << endl;
//         }
//         else
//         {
//             cout << "Invalid choice! Please try again." << endl;
//         }

//     } while (choice != 5);

//     return 0;
// }

// SECOND TASK

// #include <iostream>
// using namespace std;

// int main()
// {
//     char attendance;
//     char repeat = 'y';

//     int total = 0, present = 0, absent = 0;

//     while (repeat == 'y' || repeat == 'Y')
//     {

//         cout << "Enter attendance (P/p for Present, A/a for Absent): ";
//         cin >> attendance;

//         if (attendance == 'P' || attendance == 'p')
//         {
//             present++;
//         }
//         else if (attendance == 'A' || attendance == 'a')
//         {
//             absent++;
//         }
//         else
//         {
//             cout << "Invalid input! Try again." << endl;
//             continue;
//         }

//         total++;

//         cout << "Do you want to mark another student? (y/n): ";
//         cin >> repeat;

//         cout << endl;
//     }

//     float percentage = (present * 100.0) / total;

//     cout << "Total Students: " << total << endl;
//     cout << "Present: " << present << endl;
//     cout << "Absent: " << absent << endl;
//     cout << "Attendance Percentage: " << percentage << "%" << endl;

//     return 0;
// }

// second task on do while loop
// #include <iostream>
// using namespace std;

// int main()
// {
//     char attendance;
//     char repeat;

//     int total = 0, present = 0, absent = 0;

//     do
//     {
//         cout << "Enter attendance (P/p for Present, A/a for Absent): ";
//         cin >> attendance;

//         if (attendance == 'P' || attendance == 'p')
//         {
//             present++;
//         }
//         else if (attendance == 'A' || attendance == 'a')
//         {
//             absent++;
//         }
//         else
//         {
//             cout << "Invalid input! Try again." << endl;
//             continue;
//         }

//         total++;

//         cout << "Do you want to mark another student? (y/n): ";
//         cin >> repeat;

//         cout << endl;

//     } while (repeat == 'y' || repeat == 'Y');

//     float percentage = (present * 100.0) / total;

//     cout << "Total Students: " << total << endl;
//     cout << "Present: " << present << endl;
//     cout << "Absent: " << absent << endl;
//     cout << "Attendance Percentage: " << percentage << "%" << endl;

//     return 0;
// }
