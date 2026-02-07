#include <iostream>
using namespace std;
int main()
// {
//     int i = 1;
//     while (i <= 5)
//     {
//         cout << "heello " << i << endl;
//         i++;
//     }
//     return 0;
// }

// guesss game
{
    int correctNum = 7;
    int guessCount = 0;
    int guessNum;
    while (correctNum != guessNum)
    {
        cout << "enter gueess num." << endl;
        cin >> guessNum;
        guessCount++;
    }
    cout << "You win" << endl;
    cout << "guess counts you tried." << guessCount;
    return 0;
}