// Functions: Its a block of code runs when it is called . it is used for reusable code
// we cannot declare nested function in main
// #include <iostream>
// using namespace std;
// void printHello()
// {
//     cout << "hello world" << endl;
// }
// void printhi()
// {
//     cout << "Starting print hi" << endl;
//     printHello();
//     cout << "Ending Print hi funtion" << endl;
// }
// int main()
// {
//     printHello();
//     printhi();
//     return 0;
// }

// NESTED FUNCTION INSIDE MAIN FUNCTION
// #include <iostream>
//     using namespace std;
// int main()
// {
//     void myFunc()
//     {
//         cout << "Hello" << endl;
//     }
//     myFunc();
// }
// so its clear that we cannot defined function in main we just have to call it in a main function

// practice problem
// #include <iostream>
// using namespace std;
// void doA()
// {
//     cout << "In D of A\n";
// }
// void doB()
// {
//     cout << "In D of B\n";
//     doA();
// }
// int main()
// {
//     cout << "Starting ..............\n";
//     doA();
//     doB();
//     cout << "Ending ................\n";
//     return 0;
// }

// PARMAETERS: The information that is passed to the functions is known as parameters.
// refernce is used here i will explain it to you.
// #include <iostream>
// using namespace std;
// void ParameterData(string &name, int &age)
// {
//     cout << "what is your name?" << endl;
//     cin.ignore();
//     getline(cin, name);
//     cout << "What is your age ?" << endl;
//     cin >> age;
// }
// int main()
// {
//     string nameData;
//     int ageData;
//     ParameterData(nameData, ageData);
//     cout << "Your name is " << nameData << endl;
//     cout << "Your age is " << ageData << endl;

//     return 0;
// }