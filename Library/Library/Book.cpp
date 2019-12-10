#include "Book.h"





Book::Book(string Tensach, string Masach, int Giatien)
{
	this->Tensach = Tensach;
	this->Masach = Masach;
	this->Giatien = Giatien;
}

//Sach::Sach(const string Tensach,const string Masach,const int Giatien)
//{
//	this->Tensach = Tensach;
//	this->Masach = Masach;
//	this->Giatien = Giatien;
//}


Book::Book(const Book& Book)
{
	Tensach = Book.Tensach;
	Masach = Book.Masach;
	Giatien = Book.Giatien;
	NXB = Book.NXB;
	Author = Book.Author;
}

Book::Book()
{
}

void Book::set(Book a)
{
	Masach = a.get_Masach();
	Tensach = a.get_Tensach();
	Giatien = a.get_Giatien();
}

void Book::set_Tensach(string s)
{
	Tensach = s;
}

void Book::set_Masach(string s)
{
	Masach = s;
}

void Book::set_Giatien(int n)
{
	Giatien = n;
}

void Book::set_NXB(string s)
{
	this->NXB = s;
}

void Book::set_Author(string s)
{
	this->Author = s;
}

void Book::input_sach(HANDLE hConsoleOutput, COORD arr[])
{
	string tensach;
	string masach;
	string NXB;
	string Author;
	int giatien;
	SetConsoleCursorPosition(hConsoleOutput, arr[1]);
	cin >> tensach;
	SetConsoleCursorPosition(hConsoleOutput, arr[2]);
	cin >> masach;
	SetConsoleCursorPosition(hConsoleOutput, arr[3]);
	cin >> giatien;
	SetConsoleCursorPosition(hConsoleOutput, arr[4]);
	cin >> Author;
	SetConsoleCursorPosition(hConsoleOutput, arr[5]);
	cin >> NXB;
	this->NXB = NXB;
	this->Author = Author;
	this->set_Tensach(tensach);
	this->set_Masach(masach);
	this->set_Giatien(giatien);

	/*cout << "Nhap ten sach" << endl;
	cin.ignore();
	getline(cin, tensach);
	cout << "Nhap ma sach" << endl;
	cin >> masach;
	cout << "Nhap gia tien " << endl;
	cin >> giatien;
	this->set_Tensach(tensach);
	this->set_Masach(masach);
	this->set_Giatien(giatien);*/
}

void Book::output_sach(HANDLE hConsoleOutput, COORD arr[])
{
	SetConsoleCursorPosition(hConsoleOutput, arr[1]);
	cout << Tensach;
	SetConsoleCursorPosition(hConsoleOutput, arr[2]);
	cout << Masach;
	SetConsoleCursorPosition(hConsoleOutput, arr[3]);
	cout << Giatien;
	SetConsoleCursorPosition(hConsoleOutput, arr[4]);
	cout << this->Author;
	SetConsoleCursorPosition(hConsoleOutput, arr[5]);
	cout << this->NXB;

}
void Book::outputSach()
{
	cout << "Ten sach" << endl;
	cout << Tensach << endl;
	cout << "Ma sach" << endl;
	cout << Masach << endl;
	cout << "Gia Tien" << endl;
	cout << Giatien << endl;
}
COORD GetConsoleCursorPosition()
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO conBufInfo;
	GetConsoleScreenBufferInfo(hConsoleOutput, &conBufInfo);
	return conBufInfo.dwCursorPosition;
}

string Book::get_Tensach()
{
	return Tensach;
}

string Book::get_Masach()
{
	return Masach;
}

string Book::get_Author()
{
	return Author;
}

int Book::get_Giatien()
{
	return Giatien;
}

string Book::get_NXB()
{
	return NXB;
}
