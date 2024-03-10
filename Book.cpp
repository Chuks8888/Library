#include <iostream>
#include <string.h>

class Book
{
    private:
        const char* Name;
        const char* Author; 
        int Pages;
        int Availible;

    public:
        Book(const char* name = " ", const char* author = " ", int pages = 0, int Availible = 0);
        void print();
};

class List_of_books
{
    private:
        Book *ptr;
        List_of_books *next;
    public:
        List_of_books()  
};

Book::Book(const char* name, const char* author, int pages, int availible)
{
    Name = name;
    Author = author;
    Pages = pages;
    Availible = availible;
}
void Book::print()
{
    std::cout << "Book: " << Name << std::endl;
    std::cout << "Author: " << Author << std::endl;
    std::cout << "Pages: " << Pages << std::endl;
    std::cout << "Copies availible: " << Pages << std::endl;
}

int main()
{
}