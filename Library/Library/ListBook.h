#pragma once
#include"Book.h"
#include<vector>
class ListBook
{
private:
	vector <Book> List_Book;
public:
	//construtor
	ListBook();
	//method
	//tra ve book thu i
	Book GetBookPosition_i(int i);
	//them sach vao bill
	Book addBooktoBill();
	//xoa sach
	void deleteBook(int Vitri);
	//cap nhap gia
	void updatePrice(int Vitri);
	void inputList();
	void outputList();
	int get_soluong();
	int Optional();
	//tim sach
	void findFunction();
	//tim sach tra ve vi tri
	int findFuntionReturnVitri();
	//day 1 book vao list book
	void pushBack(Book s);
	//tim sach bang ten tra ve vi tri
	int findBookbyName(string);
	//tim sach bang ma sach tra ve vi tri
	int findBookbyMasach(string);
};
void printTable(HANDLE hConsoleOutput, COORD arr[]);



