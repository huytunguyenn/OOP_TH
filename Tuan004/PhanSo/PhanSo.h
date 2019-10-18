#ifndef _PHANSO_H_
#define _PHANSO_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class PhanSo {
public:
	int TU;
	int MAU;
	PhanSo() {
		MAU = 1;
		TU = 0;
	}
	friend ostream& operator<<(ostream&, PhanSo);
	friend istream& operator>>(istream&, PhanSo&);
	PhanSo operator+(PhanSo);
	PhanSo operator-(PhanSo);
	PhanSo operator*(PhanSo);
	PhanSo operator/(PhanSo);
	int UCLN(int, int);
	void rutgonPhanSo();
	PhanSo chuyenPhanSo(string ps);
	PhanSo tinhBieuThuc(string);
};


#endif
