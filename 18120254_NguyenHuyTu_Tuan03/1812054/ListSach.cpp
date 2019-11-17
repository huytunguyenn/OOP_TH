#include "ListSach.h"
ListSach::ListSach() {
	pHead = pTail = NULL;
	n = 0;
}
ListSach::~ListSach() {
	for (Node* p; !isEmpty();) {
		p = pHead->pNext;
		delete pHead;
		pHead = p;
	}
	n = 0;
}
Node* ListSach::getNode(Sach x) {
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void ListSach::AddHead(Node * p) {
	if (pHead == NULL) {
		pHead = pTail = p;
		p->pNext = NULL;
	}
	else {
		p->pNext = pHead;
		pHead = p;
	}
}
void ListSach::AddTail(Node * p) {
	if (pHead == NULL) {
		pHead = pTail = p;
		p->pNext = NULL;
	}
	else {
		pTail->pNext = p;
		pTail = p;
	}
}
void ListSach::Input(int n) {
	Sach x;
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin cho cuon sach thu " << i + 1 << endl;
		cin >> x;
		Node* p = getNode(x);
		AddTail(p);
	}
}
void ListSach::Output() {
	int i = 1;
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		cout << "Thong tin cuon sach thu " << i++ << endl << p->data << endl;
	}
}
int ListSach::SearchViTriMA(string ma) {
	int position = 0;
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (p->data.MA == ma)
			return position;
		++position;
	}
	return -1;
}
int ListSach::SearchViTriTEN(string ten) {
	int position = 0;
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (p->data.TEN == ten)
			return position;
		++position;
	}
	return -1;
}
void ListSach::DelHead() {
	if (pHead == NULL) {
		cout << "Danh sach rong" << endl;
	}
	else {
		pHead = pHead->pNext;
	}
}
void ListSach::DelTail() {
	Node* p = pHead;
	while (p->pNext->pNext != NULL) {
		p = p->pNext;
	}
	p->pNext = NULL;
}
void ListSach::DelByViTri(int position) {
	if (position == 0 || pHead == NULL) {
		DelHead(); // vi tri =0 thi xoa dau
	}
	else {
		int k = 1;
		Node* p = pHead;
		while (p->pNext->pNext != NULL && k != position) {
			p = p->pNext;
			++k;
		}
		if (k != position)
			cout << "Vi tri xoa vuot qua vi tri cuoi cung" << endl;
		else
			p->pNext = p->pNext->pNext;
	}
}
void ListSach::DelByMA(string ma) {
	int position = SearchViTriMA(ma);
	while (position != -1) {
		DelByViTri(position);
		position = SearchViTriMA(ma);
	}
}
void ListSach::DelByTEN(string ten) {
	int position = SearchViTriTEN(ten);
	while (position != -1) {
		DelByViTri(position);
		position = SearchViTriTEN(ten);
	}
}
void ListSach::OutputTEN(string ten) {
	int dem = 0;// dem so sach bi trung ten
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (p->data.TEN == ten) {
			cout << endl << p->data << endl;
			dem++;
		}
	}
}
int ListSach::baonhieuTEN(string ten) {
	int dem = 0;// dem so sach bi trung ten
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (p->data.TEN == ten) {
			dem++;
		}
	}
	return dem;
}
void ListSach::changePriceByMA(string ma, int giamoi) {
	if (pHead == NULL)
		return;
	Node * p = pHead;
	while (p != NULL) {
		if (p->data.MA == ma) {
			p->data.GIA = giamoi;
			return;
		}
		p = p->pNext;
	}
}
void ListSach::changePriceByTEN(string ten, int giamoi) {
	if (pHead == NULL)
		return;
	Node * p = pHead;
	while (p != NULL) {
		if (p->data.TEN == ten) {
			p->data.GIA = giamoi;
			return;
		}
		p = p->pNext;
	}
}
// tuan 003
Sach ListSach::SearchTEN(string ten) {
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (p->data.TEN == ten) {
			return p->data;
		}
	}
}
Sach ListSach::SearchMA(string ma) {
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (p->data.MA == ma) {
			return p->data;
		}
	}
}