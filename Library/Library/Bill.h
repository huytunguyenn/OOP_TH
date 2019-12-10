#pragma once
#include "ListBook.h"
#include"Book.h"
class Bill
{
private:
	Book book;
	int Tien;
	int Soluong;

public:
	Bill(const Bill&);
	Bill(Book book, int , int  );
	Bill();
	~Bill();
	void CreateBill(ListBook&);
	void OutputBill(HANDLE hConsoleOutput, COORD arr[]);
	void changeSoluong();
	int getTien();
	int getSoluong();
	Book getBook();
};

