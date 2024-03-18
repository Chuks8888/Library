class Book
{
    private:
        char* Name;
		char* Author; 
        int Pages;
        int Availible;

    public:
        Book(const char* name, const char* author, int pages, int Availible);
        void print();
        bool rent();
        void give_back();
        ~Book();

        friend class List_of_books;
};

class List_of_books
{
    public:
        struct List
        {
            Book *book;
            List *next;
        };
        
    private:
        List *head;
        List *find_book_ptr(const char* name);
        bool is_empty();
        void swap_elements(List*, List*);
		int  size();

    public:
        List_of_books();
        void Add_book(const char* name, const char* author, int pages, int availible);
        void print_if_found(const char* name);
		void sort_alphabet_descending();
        void show_list();
        void remove_book(const char* name);
        ~List_of_books();
};
