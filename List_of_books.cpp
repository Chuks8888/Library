#include <iostream>
#include <string.h>

#pragma once
#include "List_of_books.h"
#include "Book.h"


List_of_books::List_of_books(const char* name, const char* author, int pages, int availible)
    {
        head = nullptr;
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

            temp->ptr.~Book();
            delete temp;
        }
    }