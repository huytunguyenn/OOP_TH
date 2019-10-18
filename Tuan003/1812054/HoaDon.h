#ifndef _HOADON_H_
#define _HOADON_H_
#include "ListSach.h"
class HoaDon
{
public:
	Sach s;
	int Tien;
	int Soluong;
	HoaDon();
	void addSach(Sach, int);
	friend ostream& operator<<(ostream&, HoaDon);
	friend istream& operator>>(istream&, HoaDon&);
};
#endif

