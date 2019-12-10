#include "HoaDon.h"

HoaDon::HoaDon(){
	Tien = 0;
	Soluong = 0;
}

void HoaDon::addSach(Sach sach, int sl){
	this->s = sach;
	this->Soluong = sl;
	this->Tien = Soluong * s.GIA;
}
ostream& operator<<(ostream& os, HoaDon p){
	os << p.s << endl;
	os << "So luong: " << p.Soluong << endl;
	os << "Tien: " << p.s.GIA << "*" << p.Soluong << "= " << p.Tien;
	return os;
}


void HoaDon::changeSoluong(){
	int n;
	cout << "Nhap so luong ban muon thay doi: ";
	cin >> n;
	this->Soluong = n;
	this->Tien = s.GIA*n;
}
