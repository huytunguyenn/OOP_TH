#include "Sach.h"



Sach::Sach()
{
	GIA = 0;
}

string Sach::getTEN()
{
	return TEN;
}

string Sach::getMA()
{
	return MA;
}

int Sach::getGIA()
{
	return GIA;
}

void Sach::setTEN(string s)
{
	this->TEN = s;
}

void Sach::setMA(string s)
{
	this->MA = s;
}

void Sach::setGIA(int x)
{
	this->GIA = x;
}
ostream& operator<<(ostream& os, Sach p)
{
	os << "Ten: " << p.TEN << endl;
	os << "Ma: " << p.MA << endl;
	os << "Gia: " << p.GIA << endl;
	return os;
}
istream& operator>>(istream& is, Sach& p)
{
	cin.ignore(1);
	cout << "Nhap Ten: ";
	is >> p.TEN;
	cin.ignore(1);
	cout << "Nhap ma: ";
	is >> p.MA;
	cin.ignore(1);
	cout << "Nhap gia: ";
	is >> p.GIA;
	return is;
}