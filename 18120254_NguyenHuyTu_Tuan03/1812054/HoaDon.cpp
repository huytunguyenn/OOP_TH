#include "HoaDon.h"

HoaDon::HoaDon()
{
	Tien = 0;
	Soluong = 0;
}

void HoaDon::addSach(Sach sach, int sl)
{
	s = sach;
	Soluong = sl;
	Tien = Soluong * s.GIA;
}
ostream& operator<<(ostream& os, HoaDon p)
{
	os << p.s<< endl;
	os << "So luong: " << p.Soluong << endl;
	os << "Tien: " << p.s.GIA << "*" << p.Soluong << "= " << p.Tien;
	return os;
}
istream& operator>>(istream& is, HoaDon& p)
{
	cout << "----HOA DON 1 LOAI SACH----" << endl;
	cout << "Ten: " << p.s.TEN << endl;
	cout << "Ma: " << p.s.MA << endl;
	cout << "Gia: " << p.s.GIA << endl;
	cout << "So luong: " << p.Soluong << endl;
	cout << "Tong tien: " << p.s.GIA << "*" << p.Soluong << "= " << p.Tien << endl;
	return is;
}
