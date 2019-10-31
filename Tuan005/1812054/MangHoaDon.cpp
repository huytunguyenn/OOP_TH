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
	int tongtien=0;
	int i = 1;
	for (HdNode* p = pHead; p != NULL; p = p->pNext) {
		tongtien += p->data.Tien;
		cout << endl << "-Thong tin hoa don thu " << i++<<"	:"; 
		cout<< "Ten: "<<p->data.s.TEN <<"	"<<p->data.s.GIA<<"*"<<p->data.Soluong<<"="<<p->data.Tien<< endl;
	}
	cout << endl<< "-Tong tien: " << tongtien << endl;
}
