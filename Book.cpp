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
        Book(const char* name, const char* author, int pages, int Availible);
        void print();
        bool rent();
        void give_back();

        ~Book()
        {
            delete Name;
            delete Author;
        }
};

class List_of_books
{
    private:
        Book *ptr;
        List_of_books *next;
    public:
        List_of_books(const char* name, const char* author, int pages, int availible)
        {
            this->ptr = new Book(name, author, pages, availible);
            this->next = nullptr; 
        }

        // void show_list();

        ~List_of_books();
};

List_of_books *head = nullptr;

Book::Book(const char* name, const char* author, int pages, int availible)
{
    this->Name = name;
    this->Author = author;
    this->Pages = pages;
    this->Availible = availible;
}
void Book::print()
{
    std::cout << "Book: " << Name << std::endl;
    std::cout << "Author: " << Author << std::endl;
    std::cout << "Pages: " << Pages << std::endl;
    std::cout << "Availible: " << Pages << std::endl;
}
bool Book::rent()
{
    if(Availible > 0)
        {
            Availible--;
            return 1;
        }
    else
        return 0;
}
void Book::give_back()
{
    Availible++;
}
List_of_books::~List_of_books()
        {
            while(head)
            {
                List_of_books* temp = head;

                if(this->next != nullptr)
                    head = next;
                else 
                    head = nullptr;

                delete temp->ptr;
                delete temp;
            }
        }  

int main()
{
    return 0;
}