#include <iostream>
using namespace std;
class Item
{
private:
    string name;
    int id;
    double *price;
    static int totalItems;

public:
    Item()
    {
        name = "Generic";
        id = 0;
        price = new double;
        *price = 0.0;
        totalItems++;
        cout << "Default Constructor is added." << endl;
    }
    Item(string name, int id, double price)
    {
        this->name = name;
        this->id = id;
        this->price = new double;
        *(this->price) = price;
        totalItems++;
        cout << "Parametarized constructor is called" << endl;
        cout << "Name " << name << " Is added." << endl;
    }
    ~Item()
    {
        totalItems--;
        cout << "Name" << name << " has been destroyed" << endl;
        delete price;
    }
    void display() const
    {
        cout << " Item Name :" << name << endl;
        cout << " Item Id :" << id << endl;
        cout << " Item Price :" << *price << endl;
    }
    static void showTotal()
    {
        cout << "Total items in warehouse are " << totalItems << endl;
    }
};
int Item ::totalItems = 0;
int main()
{
    Item i1;
    i1.display();
    Item::showTotal();

    Item *i2 = new Item("Toyota", 23, 293899389.60);
    i2->display();
    Item::showTotal();

    // now as we creating dynamic object in heap now we have to relase meemory means delete this obj.
    delete i2;
    Item::showTotal();

    return 0;
}