#include <iostream>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int copies;

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
        cout << "Object Destroyed: " << this->title << endl;
        totalBooks--;
    }

    bool isAvailable()
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

    void setTitle(string title) { this->title = title; }
    void setAuthor(string author) { this->author = author; }
    void setCopies(int copies) { this->copies = copies; }

    string getTitle() { return this->title; }
    string getAuthor() { return this->author; }
    int getCopies() { return this->copies; }

    void display()
    {
        cout << "TITLE  : " << this->title << endl;
        cout << "AUTHOR : " << this->author << endl;
        cout << "COPIES : " << this->copies << endl;
    }
};

int Book::totalBooks = 0;

class EBook : public Book
{
private:
    float fileSize;

public:
    EBook(string title, string author, int copies, float fileSize)
        : Book(title, author, copies)
    {
        this->fileSize = fileSize;
    }

    ~EBook()
    {
        cout << "EBook Destroyed!" << endl;
    }

    void setFileSize(float fileSize) { this->fileSize = fileSize; }
    float getFileSize() { return this->fileSize; }

    void downloadStatus()
    {
        if (this->fileSize > 0)
        {
            cout << "Status : Downloadable!" << endl;
        }
        else
        {
            cout << "Status : Not Downloadable!" << endl;
        }
    }

    void display()
    {
        Book::display();
        cout << "FILE SIZE : " << this->fileSize << " MB" << endl;
    }
};

int main()
{
    Book b1("PHYSICS", "NEWTON", 7);
    Book b2("ENGLISH", "ZUBAIR", 0);

    cout << "BOOK DETAILS" << endl;
    b1.display();
    cout << "B1 Available : " << b1.isAvailable() << endl;
    b2.display();
    cout << "B2 Available : " << b2.isAvailable() << endl;
    cout << "Total Books : " << Book::totalBooks << endl;

    EBook e1("C++ Programming", "Bjarne", 5, 15.5);
    EBook e2("Java Basics", "James", 3, 0);

    cout << "EBOOK DETAILS" << endl;
    e1.display();
    e1.downloadStatus();
    e2.display();
    e2.downloadStatus();

    cout << "Total Books : " << Book::totalBooks << endl;

    return 0;
}