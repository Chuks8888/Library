#include <iostream>

class Book
{
    private:
        const char* Name;
        const char* Author;
        int Pages;

    public:
        Book(const char* name, char* author = "Noname", int pages);
        void print();
        

};
Book::Book(const char* name, char* author = "Noname", int pages)
{
    Name = name;
    Author = author;
    Pages = pages;
}
void Book::print()
{
    std::cout << "Book: " << Name << std::endl;
    std::cout << "Author: " << Author << std::endl;
    std::cout << "Pages: " << Pages << std::endl;
}

int main()
{
    return 0;
}