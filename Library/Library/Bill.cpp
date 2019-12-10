#include "Bill.h"




Bill::Bill(const Bill& hoadon)
{
	book = hoadon.book;
	Tien = hoadon.Tien;
	Soluong = hoadon.Soluong;
}

Bill::Bill(Book book, int soluong, int Tien)
{
	this->book = book;
	this->Tien = Tien;
	this->Soluong = soluong;
}


Bill::Bill()
{
}




Bill::~Bill()
{
}

void Bill::CreateBill(ListBook& List_sach)
{
	book = List_sach.addBooktoBill();
	if (book.get_Tensach() == "") {
		Soluong = 0;
	}
	else {
		cout << "Vui long nhap so luong " << endl;
		cin >> Soluong;
	}
	Tien = book.get_Giatien() * Soluong;
}

void Bill::OutputBill(HANDLE hConsoleOutput, COORD arr[])
{
	SetConsoleCursorPosition(hConsoleOutput, arr[1]);
	cout << book.get_Tensach();
	SetConsoleCursorPosition(hConsoleOutput, arr[2]);
	cout << book.get_Masach();
	SetConsoleCursorPosition(hConsoleOutput, arr[3]);
	cout << Soluong;
	SetConsoleCursorPosition(hConsoleOutput, arr[4]);
	cout << book.get_Giatien();
	SetConsoleCursorPosition(hConsoleOutput, arr[5]);
	cout << Tien;
}

void Bill::changeSoluong()
{
	int n;
	cout << "Nhap so luong ban muon thay doi" << endl;
	cin >> n;
	this->Soluong = n;
	this->Tien = this->book.get_Giatien() * n;
}

int Bill::getTien()
{
	return Tien;
}

int Bill::getSoluong()
{
	return this->Soluong;
}

Book Bill::getBook()
{
	return this->book;
}




