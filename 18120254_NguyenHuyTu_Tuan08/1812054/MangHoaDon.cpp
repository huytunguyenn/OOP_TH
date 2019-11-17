#include "MangHoaDon.h"

MangHoaDon::MangHoaDon() {
	pHead = pTail = NULL;
	n = 0;
}
MangHoaDon::~MangHoaDon() {
	for (HdNode* p; !isEmpty();) {
		p = pHead->pNext;
		delete pHead;
		pHead = p;
	}
	n = 0;
}
HdNode* MangHoaDon::getNode(HoaDon x) {
	HdNode* p = new HdNode;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void MangHoaDon::addHead(HdNode * p) {
	if (pHead == NULL) {
		pHead = pTail = p;
		p->pNext = NULL;
	}
	else {
		p->pNext = pHead;
		pHead = p;
	}
}
void MangHoaDon::addTail(HdNode * p) {
	if (pHead == NULL) {
		pHead = pTail = p;
		p->pNext = NULL;
	}
	else {
		pTail->pNext = p;
		pTail = p;
	}
}
void MangHoaDon::addHoaDon(HoaDon x) {
	HdNode* p = getNode(x);
	addTail(p);
}
void MangHoaDon::Output() {
	if (pHead == NULL)
		cout <<endl<< "Chua co don hang nao!" << endl;
	else {
		int tongtien = 0;
		int i = 1; //stt don hang
		int k = 8;
		gotoxy(0, k - 1); cout << "==============================================================";
		gotoxy(0, k); cout << "STT";
		gotoxy(5, k); cout << "Ten sach";
		gotoxy(28, k); cout << "Gia*SL";
		gotoxy(47, k); cout << "Tien";
		for (HdNode* p = pHead; p != NULL; p = p->pNext) {
			tongtien += p->data.Tien;
			k++;
			gotoxy(0, k); cout << i;
			gotoxy(5, k); cout << p->data.s.TEN;
			gotoxy(28, k); cout << p->data.s.GIA << "*" << p->data.Soluong;
			gotoxy(47, k); cout << p->data.Tien;
			i++;
		}
		cout << endl << "==============================================================";
		cout << endl << "Tong tien: " << tongtien << endl;
	}
}
void MangHoaDon::inputListBill(ListSach &l) {
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
			if (l.baonhieuTEN(tempTEN) > 1){
				cout << "Sach bi trung ten" << endl;
				string tempMA;
				cout << "Nhap ma sach: ";
				cin >> tempMA;
				Sach mua = l.SearchMA(tempMA);
				hd.addSach(mua, tempSL);
				addHoaDon(hd);
				check = true;
			}
			else if (l.baonhieuTEN(tempTEN) == 0) {
				cout << "Sach khong ton tai!" << endl;
			}
			else{
				Sach mua = l.SearchTEN(tempTEN);
				hd.addSach(mua, tempSL);
				addHoaDon(hd);
				check = true;
			}
			if (check == false) {
				cout << "Vui long nhap lai!" << endl;
				system("pause");
			}
		} while (check==false);
	}
}
bool MangHoaDon::updateBill_Soluong(){
	int n;
	cout << "Nhap so thu tu don hang muon thay doi: ";
	cin >> n;
	int i = 0;
	HdNode* p=pHead;
	if (p == NULL) {
		cout << "Ban chua co don hang nao" << endl;
		return false;
	}
	else {
		for (p; p!= NULL; p = p->pNext) {
			i++;
			if (i == n) {
				p->data.changeSoluong();
				return true;
			}
		}
	}
}
