#include <iostream>
#include <string.h>
#include "class.h"

int main()
{
    List_of_books Novels;
	Novels.Add_book("A", "Someone", 300, 15);
    Novels.Add_book("E", "Someone", 300, 15);
	Novels.Add_book("D", "Someone", 300, 15);
	Novels.Add_book("B", "Someone", 300, 15);
	Novels.Add_book("C", "Someone", 300, 15);
	//Novels.remove_book("The Guy");
	Novels.sort_alphabet_descending();
	//Novels.show_list();
	//Novels.sort_alphabet_ascending();
	//Novels.show_list();
	Novels.~List_of_books();
    return 0;
}
