#include "PhanSo.h"


int main() {
	PhanSo p, q;
	cout << "----CAC PHEP TINH + - * / 2 PHAN SO----" << endl;
	cout << "Nhap vao phan so thu nhat"<<endl;
	cin >> p;
	cout << "Nhap vao phan so thu hai"<<endl;
	cin >> q;
	cout << p << "+" << q << "=" << p + q << endl;
	cout << p << "x" << q << "=" << p * q << endl;
	cout << p << "-" << q << "=" << p - q << endl;
	cout << p << ":" << q << "=" << p / q << endl;
	cout << endl<< "---CAC PHEP TINH + - TRONG 1 BIEU THUC----" << endl;
	string s;
	cout << "Nhap bieu thuc: ";
	cin >> s;
	PhanSo kq= kq.tinhBieuThuc(s);
	cout <<"= "<< kq<<endl;
	system("pause");
	return 0;
}