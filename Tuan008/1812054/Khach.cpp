#include "Khach.h"
Khach::Khach() {

}
void Khach::TimSach(ListSach &l) {
	string BookName;
	cout << endl<<"Vui long nhap ten sach muon tim: ";
	cin >> BookName;
	Sach temp= l.SearchTEN(BookName);
	cout << temp <<endl;
}