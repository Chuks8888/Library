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