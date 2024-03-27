all:
	g++ -g -c Book.cpp -c List_of_books.cpp -c main.cpp
	g++ Book.o List_of_books.o main.o -o Library
	del *.o
