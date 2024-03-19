#include <iostream>
#include <string.h>
#include "class.h"

int main()
{
    List_of_books Novels;
    Novels.Add_book("The Man", "Someone", 300, 15);
	Novels.Add_book("The Guy", "Someone", 300, 15);
	Novels.Add_book("The Child", "Someone", 300, 15);
	Novels.remove_book("The Guy");
	Novels.sort_alphabet_descending();
	Novels.show_list();
	
	Novels.~List_of_books();
    return 0;
}
