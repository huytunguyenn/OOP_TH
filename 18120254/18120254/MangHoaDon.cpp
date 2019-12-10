#include "MangHoaDon.h"
#include "File.h"
MangHoaDon::MangHoaDon() {
	ReadListHoaDon("listhoadon.txt", this->listhoadon);
}
MangHoaDon::~MangHoaDon() {
	this->listhoadon.clear();
}

void MangHoaDon::Output() {
	if (this->listhoadon.empty())
		cout << endl << "Chua co don hang nao!" << endl;
	else {
		list<HoaDon>::iterator it;
		int tongtien = 0;
		int i = 1; //stt don hang
		int k = 15;
		gotoxy(0, k - 1); cout << "==============================================================";
		gotoxy(0, k); cout << "STT";
		gotoxy(5, k); cout << "Ten sach";
		gotoxy(28, k); cout << "Gia*SL";
		gotoxy(47, k); cout << "Tien";
		for (it = this->listhoadon.begin(); it != this->listhoadon.end();it++) {
			tongtien += it->Tien;
			k++;
			gotoxy(0, k); cout << i;
			gotoxy(5, k); cout << it->s.TEN;
			gotoxy(28, k); cout << it->s.GIA << "*" << it->Soluong;
			gotoxy(47, k); cout << it->Tien;
			i++;
		}
		cout << endl << "==============================================================";
		cout << endl << "Tong tien: " << tongtien << endl;
	}
}
void MangHoaDon::inputListBill(ListSach l) {
	int n1;
	cout << "Nhap so hoa don ban muon mua: ";
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		system("cls");
		string tempTEN;
		bool check = false;
		do {
			system("cls");
			cout << endl << "Nhap ten sach muon mua: ";
			cin >> tempTEN;
			int tempSL;
			cout << "Nhap so luong: ";
			cin >> tempSL;
			HoaDon hd;
			if (l.baonhieuTEN(tempTEN) > 1) {
				cout << "Sach bi trung ten" << endl;
				string tempMA;
				cout << "Nhap ma sach: ";
				cin >> tempMA;
				Sach mua = l.SearchMA(tempMA);
				hd.addSach(mua, tempSL);
				this->listhoadon.push_back(hd);
				check = true;
			}
			else if (l.baonhieuTEN(tempTEN) == 0) {
				cout << "Sach khong ton tai!" << endl;
			}
			else {
				Sach mua = l.SearchTEN(tempTEN);
				hd.addSach(mua, tempSL);
				this->listhoadon.push_back(hd);
				check = true;
			}
			if (check == false) {
				cout << "Vui long nhap lai!" << endl;
				system("pause");
			}
		} while (check == false);
		WriteListHoaDon("listhoadon.txt",this->listhoadon);
	}
}
bool MangHoaDon::updateBill_Soluong() {
	int n;
	cout << "Nhap so thu tu don hang muon thay doi: ";
	cin >> n;
	int i = 0;
	list<HoaDon>::iterator it;
	if (this->listhoadon.empty()) {
		cout << "Ban chua co don hang nao" << endl;
		return false;
	}
	else {
		for (it=this->listhoadon.begin(); it != this->listhoadon.end(); it++) {
			i++;
			if (i == n) {
				it->changeSoluong();
				WriteUpdatedListHoaDon("listhoadon.txt", this->listhoadon);
				return true;
			}
		}
	}
}
