#include "Sach.h"

Sach::Sach() {
	GIA = 0;
}

ostream& operator<<(ostream& os, Sach p)
{
	os << "Ten: " << p.TEN << endl;
	os << "Ma: " << p.MA << endl;
	os << "Gia: " << p.GIA << endl;
	os << "Tac gia: " << p.TACGIA << endl;
	os << "Nha xuat ban: " << p.NXB << endl;
	return os;
}
istream& operator>>(istream& is, Sach& p)
{
	cout << "Nhap Ten: ";
	getline(is, p.TEN);
	cout << "Nhap ma: ";
	getline(is, p.MA);
	cout << "Nhap tac gia: ";
	getline(cin, p.TACGIA);
	cout << "Nhap nha xuat ban: ";
	getline(cin, p.NXB);
	cout << "Nhap gia: ";
	is >> p.GIA;
	cin.ignore(1);
	return is;
}
