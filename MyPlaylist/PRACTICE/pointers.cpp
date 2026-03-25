// #include <iostream>
// using namespace std;
// class Patient
// {
// private:
//     string name;
//     int age;
//     string disease;

// public:
//     Patient(string name, int age, string disease)
//     {
//         this->name = name;
//         this->age = age;
//         this->disease = disease;
//     }
//     ~Patient()
//     {
//         cout << "Patient" << this->name << "destroyed" << endl;
//     }
//     void setName(string name)
//     {
//         this->name = name;
//     }
//     void setAge(int age)
//     {
//         this->age = age;
//     }
//     void setDisease(string disease)
//     {
//         this->disease = disease;
//     }
//     void display()
//     {
//         cout << "name    :" << this->name << endl;
//         cout << "age     :" << this->age << endl;
//         cout << "disease :" << this->disease << endl;
//     }
// };
// int main()
// {
//     Patient *p = new Patient("Abcd", 21, "Heart Surgery");
//     p->display();

//     Patient *patients = new Patient[2]{
//         Patient("Ali", 13, "Flue"),
//         Patient("Ahmer", 34, "Thalasemia")};
//     for (int i = 0; i < 2; i++)
//     {
//         patients[i].display();
//     }
//     p = nullptr;
//     delete p;
//     delete[] patients;
//     patients = nullptr;
//     return 0;
// }

#include <iostream>
using namespace std;
class bank
{
private:
    string name;
    int acc;
    int bal;

public:
    bank(string n, int a, int b) : name(n), acc(a), bal(b) {};
    ~bank()
    {
        cout << name << "destroyed" << endl;
    }
    void dis()

    {
        cout << "Name" << name << " accunt" << acc << "balance" << bal << endl;
    }
};
int main()
{
    bank *b = new bank("Ali", 1283129, 1893);
    b->dis();
    delete b;
    b = nullptr;
    return 0;
}