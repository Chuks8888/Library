class Book
{
    private:
        const char* Name;
        const char* Author; 
        int Pages;
        int Availible;

    public:
        Book(const char* name, const char* author, int pages, int Availible);
        void print();
        bool rent();
        void give_back();
        ~Book();
};

class List_of_books
{
    private:
        struct List
        {
            Book *book;
            List *next;
        };
        List *head;
    public:
        List_of_books();
        void Add_book(const char* name, const char* author, int pages, int availible);
        bool is_empty();
        void show_list();
        //void remove_book();
        ~List_of_books();
};