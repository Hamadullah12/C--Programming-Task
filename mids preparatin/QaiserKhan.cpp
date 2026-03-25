
#include <iostream>
using namespace std;
class Book
{
private:
    string title;
    string author;
    int copies;
    // static variable

public:
    static int totalBooks;
    Book(string title, string author, int copies)
    {
        this->title = title;
        this->author = author;
        this->copies = copies;
        totalBooks++;
    }
    ~Book()
    {
        cout << "Object Destroyed" << endl;
        totalBooks--;
    }

    bool isAvailabe()
    {
        if (this->copies > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setAuthor(string author)
    {
        this->author = author;
    }
    void setCopies(int copies)
    {
        this->copies = copies;
    }
    string getTitle()
    {
        return this->title;
    }
    string getAuthor()
    {
        return this->author;
    }
    int getCopies()
    {
        return this->copies;
    }
    void display()
    {
        cout << "TITLE  :" << this->title << endl;
        cout << "AUTHOR :" << this->author << endl;
        cout << "COPIES :" << this->copies << endl;
    }
};
int Book::totalBooks = 0;
int main()
{

    Book b1("PHYSICS", "NEWTON", 7);
    Book b2("ENGLISH", "ZUBAIR", 20);
    b1.display();
    b2.display();
    cout << "Total Books :" << Book::totalBooks << endl;
    cout << "B1 Availabe :" << b1.isAvailabe();
    cout << "B2 Availabe :" << b2.isAvailabe();
    return 0;
}