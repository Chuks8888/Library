#include <iostream>
#include <string.h>
#include "class.h"

Book::Book(const char* name, const char* author, int pages, int availible)
{
    this->Name = new char[strlen(name) + 1];
    this->Name = name;
    
    this->Author = new char[strlen(author) + 1];
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

Book::~Book()
{
    std::cerr << "Book " << Name << " deleted" << std::endl;
    delete[] Name;
    delete[] Author;
}