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
        std::cout<< "index: " << ptr->index << std::endl;
        ptr->book->print();
        std::cout<<std::endl<<std::endl;
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

int List_of_books::sort(List* left_ptr, int right, List* middle_ptr)
{
    //middle_ptr->book->print();
	int position = left_ptr->index;
	for(int i = position; i<right; i++)
	{
		if(strcmp(left_ptr->book->Name, middle_ptr->book->Name) <= 0)
		{
			swap_elements(left_ptr, find_by_index(position));
            position++;
		}
        left_ptr = left_ptr->next;
	}
	swap_elements(middle_ptr, find_by_index(position));
    return position;
}

void List_of_books::sortthrough(int left, int right)
{
	if(left < right)
	{
        int middle = left + (right-1)/2;

		List* left_ptr = this->find_by_index(left);
		List* middle_ptr = this->find_by_index(middle);
		List* right_ptr = this->find_by_index(right);

		swap_elements(middle_ptr, right_ptr);
		int position = sort(left_ptr, right, right_ptr);

		sortthrough(left, position-1);  // left part
		sortthrough(position+1, right); // right part
	}
}

void List_of_books::sort_alphabet_descending()
{
	sortthrough(0, size()-1);
}

void List_of_books::sort_alphabet_ascending()
{
	sortthrough(0, size()-1);
}

List_of_books::List* List_of_books::find_by_index(int ind)
{
    if(ind > size()-1)
        return nullptr;
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
