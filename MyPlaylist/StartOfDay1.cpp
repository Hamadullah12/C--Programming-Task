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