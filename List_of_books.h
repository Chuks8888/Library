#include "Book.h"
class List_of_books
{
    private:
        struct List
        {
            Book ptr;
            List *next;
        };
        List *head;
    public:
        List_of_books(const char* name, const char* author, int pages, int availible);

        //void show_list();

        ~List_of_books();
};