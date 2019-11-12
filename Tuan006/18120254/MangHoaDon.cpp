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
	int tongtien = 0;
	int i = 1;
	for (HdNode* p = pHead; p != NULL; p = p->pNext) {
		tongtien += p->data.Tien;
		cout << endl << "-Thong tin hoa don thu " << i++ << "	:";
		cout << "Ten: " << p->data.s.TEN << "	" << p->data.s.GIA << "*" << p->data.Soluong << "=" << p->data.Tien << endl;
	}
	cout << endl << "-Tong tien: " << tongtien << endl;
}


void MangHoaDon::inputListBill(ListSach &l)
{
	int n1;
	cout << "Nhap so hoa don ban muon mua: ";
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		string tempTEN;
		cout << endl << "Nhap ten sach muon mua: ";
		cin >> tempTEN;
		int tempSL;
		cout << "Nhap so luong: ";
		cin >> tempSL;
		HoaDon hd;
		if (l.baonhieuTEN(tempTEN) > 1)
		{
			cout << "Sach bi trung ten" << endl;
			string tempMA;
			cout << "Nhap ma sach: ";
			cin >> tempMA;
			Sach mua = l.SearchMA(tempMA);
			hd.addSach(mua, tempSL);
			addHoaDon(hd);
		}
		else if (l.baonhieuTEN(tempTEN) == 0) {
			cout << "Sach khong ton tai!" << endl;
		}
		else
		{
			Sach mua = l.SearchTEN(tempTEN);
			hd.addSach(mua, tempSL);
			addHoaDon(hd);
		}
	}
}
void MangHoaDon::updateBill_Soluong()
{
	string masach;
	cin.ignore(1);
	cout << "Nhap ma sach co trong don hang muon thay doi: ";
	cin >> masach;
	HdNode* p;
	for (p = pHead; p->pNext != NULL; p = p->pNext) {
		if(masach==p->data.s.TEN)
			p->data.changeSoluong();
	}
}
