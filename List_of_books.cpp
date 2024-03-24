#include <cstdint>
#include <iostream>
#include <string.h>
#include "class.h"

List_of_books::List_of_books()
{
    this->head = nullptr;
}

void List_of_books::Add_book(const char* name, const char* author, int pages, int availible)
{
    List* ptr = head;
    while(ptr)
    {
        if(ptr->next == nullptr)
        {
            ptr->next = new List;
            ptr = ptr->next;
            break;
        }
        ptr = ptr->next;
    }
    if(head == nullptr)
    {
        ptr = new List;
        head = ptr;
    }
    ptr->book = new Book(name, author, pages, availible);
    ptr->next = nullptr;
	ptr->index = size() - 1;
}

List_of_books::List* List_of_books::find_book_ptr(const char* name)
{
    List* ptr = head;
    while(ptr)
    {
        if(strcmp(name, ptr->book->Name) == 0)
            return ptr;

        ptr = ptr->next;
    }
    return nullptr;
}

bool List_of_books::is_empty()
{
    return head == nullptr;
}

void List_of_books::search(const char* name)
{
    List *ptr = find_book_ptr(name);
    if(ptr == nullptr)
        std::cerr << "Book " << name << " not found" << std::endl;
    else std::cerr << "Book " << ptr->book->Name << " found" << std::endl;
}

void List_of_books::show_list()
{
    List* ptr = head;
    while(ptr)
    {
        ptr->book->print();
		std::cout<< " " << ptr->index;
        std::cout<<std::endl;
        ptr = ptr->next;
    }
}

void swap_elements(List_of_books::List* element_1, List_of_books::List* element_2)
{
	Book* temp = element_1->book;
    element_1->book = element_2->book;
    element_2->book = temp;
}

int List_of_books::size()
{
	List* ptr = head;
	int size = 0;
	while(ptr)
	{
		size++;
		ptr = ptr->next;
	}
	return size;
}

void sort(List_of_books::List* head, List_of_books::List* left_ptr, List_of_books::List* right_ptr, List_of_books::List* middle_ptr)
{
	int i = left_ptr->index;
	int j = right_ptr->index;
	while(left_ptr != middle_ptr && right_ptr!=middle_ptr)
	{
		
	}
}

void sortthrough(List_of_books::List* head, int left, int right, int middle)
{
	if(left != right)
	{
		List_of_books::List* left_ptr = head;
		List_of_books::List* right_ptr = head;
		List_of_books::List* middle_ptr = head;

		for(int i = 0; i < left; i++)
			left_ptr = left_ptr->next;
		for(int i = 0; i < right; i++)
			right_ptr = right_ptr->next;  
		for(int i = 0; i < middle; i++)
			middle_ptr = middle_ptr->next;

		sort(head, left_ptr, right_ptr, middle_ptr);

		sortthrough(head, left, middle, middle/2);
		sortthrough(head, middle, right, (middle + right)/2);
	}
}

void List_of_books::sort_alphabet_descending()
{
    int middle = (size())/2;
	sortthrough(head, 0, size(), middle);

	// use qiuick sort https://pl.wikipedia.org/wiki/Sortowanie_szybkie
}

List_of_books::List* List_of_books::find_by_index(int ind)
{
	List* ptr = head;
	for(int i = 0; i < ind; i++)
		ptr = ptr->next;
	return ptr;
}

void List_of_books::reassign_indices(List* ptr_to_remove)
{
	List* ptr = ptr_to_remove->next;
	int size = ptr_to_remove->index;
	while(ptr)
	{
		ptr->index = size;
		size++;
		ptr = ptr->next;
	}

}

void List_of_books::remove_book(const char* name)
{
    if(is_empty() != 1)
    {
        if(find_book_ptr(name) != nullptr)
        {
            List* ptr_to_remove = find_book_ptr(name);
            if(ptr_to_remove == head)
            {
                if(head->next == nullptr)
                {
                    delete head->book;
                    delete head;
                }
                else
                {
                    head = head->next;
					reassign_indices(ptr_to_remove);
                    delete ptr_to_remove->book;
                    delete ptr_to_remove;
                }
            }
            else
            {
                List* ptr_before = head;
                while(ptr_before->next != ptr_to_remove)
                    ptr_before = ptr_before->next;
                if(ptr_to_remove->next == nullptr)
                {
                    delete ptr_to_remove->book;
                    delete ptr_to_remove;
                    ptr_before->next = nullptr;
                }
                else
                {
                    ptr_before->next = ptr_to_remove->next;
					reassign_indices(ptr_to_remove);
                    delete ptr_to_remove->book;
                    delete ptr_to_remove;
                }
            }
        }
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
