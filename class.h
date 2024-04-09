#include <vector>
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
			int index;
            Book *book;
            List *next;
        };
        
    private:
        List *head;
		char *category_name;
        List *find_book_ptr(const char* name);
		List *find_by_index(int);
        bool is_empty();
		int  size();
		void reassign_indices(List*);

		int sort(List*, int, List*);
		void sortthrough(int, int);

    public:
        List_of_books(const char*);
        void Add_book(const char* name, const char* author, int pages, int availible);
        void search(const char* name);
		void sort_alphabet_descending();
        void sort_alphabet_ascending();
        void show_list();
        void remove_book(const char* name);

        ~List_of_books();
};

class User
{
	protected:
		char* Username;
		char* Password;

	public:
		User();
};

class Librarian: private User
{
	private:
		char* email;
		std::vector<Book> Borrowed;
};

class Client: private User
{

};

class Administrator: private User // can add/remove to/from the system, or etc.
{

};

class Library
{
	private:
		std::vector<List_of_books> BOOKS;
		std::vector<Client> ACCOUNTS;
		std::vector<Librarian> EMPLOYEES;

	friend Administrator;
};


