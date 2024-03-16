#include <iostream>
#include <string.h>
#include "class.h"

int main()
{
    List_of_books Novels;
    Novels.Add_book("The Dune", "Someone", 300, 15);
    Novels.Add_book("Witcher", "Someone", 300, 15);
    Novels.Add_book("Lord of the rings", "Someone", 300, 15);
    Novels.Add_book("Hobbit", "Someone", 300, 15);
    Novels.remove_book("The Dune");
    Novels.show_list();
    Novels.~List_of_books();
    return 0;
}