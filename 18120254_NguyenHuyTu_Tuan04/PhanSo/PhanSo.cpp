#include "PhanSo.h"

ostream& operator<<(ostream& os, PhanSo p) {
	cout << p.TU << '/' << p.MAU;
	return os;
}
istream& operator>>(istream& is, PhanSo& p) {
	cout << "Nhap tu so: ";
	cin >> p.TU;
	cout << "Nhap mau so:";
	cin>> p.MAU;
	return is;
}
int PhanSo::UCLN(int a, int b) {
	a = abs(a);
	b = abs(b);
	if (a == b)
		return a;
	else if (a > b)
		return UCLN(a - b, b);
	else
		return UCLN(a, b - a);
}
void PhanSo::rutgonPhanSo() {
	int x = UCLN(TU, MAU);
	if ((TU > 0 && MAU < 0) || (TU < 0 && MAU < 0)) {
		TU = -TU;
		MAU = -MAU;
	}
	TU /= x;
	MAU /= x;
}
PhanSo PhanSo::operator+(PhanSo q) {
	PhanSo kq;
	kq.TU = this->TU * q.MAU + q.TU * this->MAU;
	kq.MAU = this->MAU * q.MAU;
	kq.rutgonPhanSo();
	return kq;
}
PhanSo PhanSo::operator-(PhanSo q) {
	PhanSo kq;
	kq.TU = this->TU * q.MAU - q.TU * this->MAU;
	kq.MAU = this->MAU * q.MAU;
	kq.rutgonPhanSo();
	return kq;
}
PhanSo PhanSo::operator*(PhanSo q) {
	PhanSo kq;
	kq.TU = this->TU * q.TU;
	kq.MAU = this->MAU * q.MAU;
	kq.rutgonPhanSo();
	return kq;
}
PhanSo PhanSo::operator/(PhanSo q) {
	PhanSo kq;
	kq.TU = this->TU * q.MAU;
	kq.MAU = this->MAU * q.TU;
	kq.rutgonPhanSo();
	return kq;
}
PhanSo PhanSo::chuyenPhanSo(string ps) {
	string tu, mau;
	int index = ps.find('/');
	for (int j = 0; j < index; j++) {
		tu.push_back(ps.at(j));
	}
	for (int j = index + 1; j < ps.length(); j++) {
		mau.push_back(ps.at(j));
	}
	PhanSo kq;
	kq.TU = atoi(tu.c_str());
	kq.MAU = atoi(mau.c_str());
	return kq;
}
PhanSo PhanSo::tinhBieuThuc(string str)
{
	string so;
	string ps;
	PhanSo tong; // tong=0
	int i = 0;
	// lay phanso dau tien ra + vao phanso tong
	for (; i < str.length(); i++) {
		ps.push_back(str.at(i));
		if (str.at(i) == '+' || str.at(i) == '-')
			break;
	}
	tong = tong + chuyenPhanSo(ps);
	while(i<str.length()){
		//reset string
		ps.clear();
		if (str.at(i) == '+') {
			i++;
			for (; i < str.length(); i++) {
				ps.push_back(str.at(i));
				if (str.at(i) == '+' || str.at(i) == '-')
					break;
			}
			tong = tong + chuyenPhanSo(ps);
		}
		else if (str.at(i) == '-') {
			i++;
			for (; i < str.length(); i++) {
				ps.push_back(str.at(i));
				if (str.at(i) == '+' || str.at(i) == '-')
					break;
			}
			tong = tong - chuyenPhanSo(ps);
		}
	}
	return tong;
}


