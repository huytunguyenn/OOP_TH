#include "ListSach.h"
#include "File.h"
ListSach::ListSach() {
	ReadListSach("listsach.txt", this->listsach);
}
ListSach::~ListSach() {
	listsach.clear();
}
void ListSach::Input(int n) {
	Sach x;
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin cho cuon sach thu " << i + 1 << endl;
		cin >> x;
		WriteListSach("listsach.txt", listsach, x);
	}
}
void ListSach::Output() {
	if (this->listsach.empty()) {
		cout << endl << "DANH SACH RONG!" << endl;
		system("pause");
		return;
	}
	list<Sach>::iterator it;
	int i = 1;
	for (it = this->listsach.begin(); it != this->listsach.end(); it++) {
		cout << i++ << ". " << *it;
	}
}
Sach ListSach::TimSach() {
	string BookName;
	cout << endl << "Vui long nhap ten sach muon tim: ";
	getline(cin, BookName);
	Sach temp = SearchTEN(BookName);
	return temp;
}
int ListSach::baonhieuTEN(string ten) {
	int dem = 0;// dem so sach bi trung ten
	list<Sach>::iterator it;
	for (it = this->listsach.begin(); it != this->listsach.end(); it++) {
		if (it->TEN == ten) {
			dem++;
		}
	}
	return dem;
}
Sach ListSach::SearchTEN(string ten) {
	Sach temp;
	list<Sach>::iterator it;
	for (it = this->listsach.begin(); it != this->listsach.end(); it++) {
		if (it->TEN == ten) {
			temp = *it;
		}
	}
	return temp;
}
Sach ListSach::SearchMA(string ma) {
	Sach temp;
	list<Sach>::iterator it;
	for (it = this->listsach.begin(); it != this->listsach.end(); it++) {
		if (it->MA == ma) {
			temp = *it;
		}
	}
	return temp;
}
void ListSach::deleteName(string name) {
	if (this->listsach.empty()) {
		return;
	}
	else {
		list<Sach>::iterator it;
		for (it = this->listsach.begin(); it != this->listsach.end(); it++) {
			if (it->TEN == name) {
				this->listsach.erase(it);
			}
		}
		WriteDeletedListSach("listsach.txt", this->listsach);
	}
}
void ListSach::deleteNXB(string tensach) {
	if (this->listsach.empty()) {
		return;
	}
	else {
		list<Sach>::iterator it;
		for (it = this->listsach.begin(); it != this->listsach.end(); it++) {
			if (it->TEN == tensach) {
				it->NXB = "";
			}
		}
		WriteDeletedListSach("listsach.txt", this->listsach);
	}
}
void ListSach::deleteTacGia(string tensach) {
	if (this->listsach.empty()) {
		return;
	}
	else {
		list<Sach>::iterator it;
		for (it = this->listsach.begin(); it != this->listsach.end(); it++) {
			if (it->TEN == tensach) {
				it->TACGIA = "";
			}
		}
		WriteDeletedListSach("listsach.txt", this->listsach);
	}
}