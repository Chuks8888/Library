#include <iostream>
#include <string.h>
#include "class.h"

int main()
{
    List_of_books Novels;
    Novels.Add_book("The Dune", "Someone", 300, 15);
    Novels.show_list();
    Novels.~List_of_books();
    return 0;
}