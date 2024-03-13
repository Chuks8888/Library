#include <iostream>
#include <string.h>
#include "class.h"

List_of_books::List_of_books()
{
    head = nullptr;
}

void List_of_books::Add_book(const char* name, const char* author, int pages, int availible)
{
    List* ptr = head;
    while(ptr)
    {
        ptr = ptr->next;
    }
    ptr = new List;
    ptr->book = new Book(name, author, pages, availible);
    ptr->next = nullptr;
}

bool List_of_books::is_empty()
{
    return head == nullptr;
}

void List_of_books::show_list()
{
    List* ptr = head;
    while(ptr)
    {
        ptr->book->print();
        std::cout<<std::endl;
        ptr = ptr->next;
    }
}

List_of_books::~List_of_books()
{
    while(head)            
    {
        List* temp = head;
        if(head->next != nullptr)
            head = head->next;
        else 
            head = nullptr;

        delete temp->book;
        delete temp;
    }
}