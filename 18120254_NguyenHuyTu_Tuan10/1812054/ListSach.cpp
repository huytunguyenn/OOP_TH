#include "ListSach.h"
ListSach::ListSach() {
	pHead = pTail = NULL;
}
ListSach::~ListSach() {
	for (Node* p; !isEmpty();) {
		p = pHead->pNext;
		delete pHead;
		pHead = p;
	}
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
	if (pHead == NULL) {
		cout << endl<< "DANH SACH RONG!" << endl;
		system("pause");
		return;
	}
	int i = 1;
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		cout <<i++<<"."<< endl << p->data << endl;
	}
}
Sach ListSach::TimSach() {
	string BookName;
	cout << endl << "Vui long nhap ten sach muon tim: ";
	cin >> BookName;
	Sach temp = SearchTEN(BookName);
	return temp;
}
//int ListSach::SearchViTriMA(string ma) {
//	int position = 0;
//	for (Node* p = pHead; p != NULL; p = p->pNext) {
//		if (p->data.MA == ma)
//			return position;
//		++position;
//	}
//	return -1;
//}
//int ListSach::SearchViTriTEN(string ten) {
//	int position = 0;
//	for (Node* p = pHead; p != NULL; p = p->pNext) {
//		if (p->data.TEN == ten)
//			return position;
//		++position;
//	}
//	return -1;
//}
int ListSach::baonhieuTEN(string ten) {
	int dem = 0;// dem so sach bi trung ten
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (p->data.TEN == ten) {
			dem++;
		}
	}
	return dem;
}
//void ListSach::changePriceByMA(string ma, int giamoi) {
//	if (pHead == NULL)
//		return;
//	Node * p = pHead;
//	while (p != NULL) {
//		if (p->data.MA == ma) {
//			p->data.GIA = giamoi;
//			return;
//		}
//		p = p->pNext;
//	}
//}
//void ListSach::changePriceByTEN(string ten, int giamoi) {
//	if (pHead == NULL)
//		return;
//	Node * p = pHead;
//	while (p != NULL) {
//		if (p->data.TEN == ten) {
//			p->data.GIA = giamoi;
//			return;
//		}
//		p = p->pNext;
//	}
//}
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
//tuan007
void ListSach::deleteName(string name) {
	if (pHead != NULL) { // khi ds không rỗng
		if (pHead == pTail && pHead->data.TEN == name) { // ds có 1 phần tử
			delete pHead;
			pHead = pTail = NULL;
		}
		else if (pHead->data.TEN==name) { // xóa đầu
			Node* temp = pHead;
			pHead = pHead->pNext;
			delete temp; // xóa head cũ
		}
		else {
			Node* pred, *temp;
			for (pred = pHead, temp = pHead->pNext; temp != NULL ; pred = pred->pNext, temp = temp->pNext) {
				if (temp->data.TEN == name) {
					pred->pNext = temp->pNext;
					if (temp == pTail) { // xóa cuối
						delete pTail;
						pTail = new Node;
						pTail = pred;
					}
					else
						delete temp;
				}
			}
		}
	}
}
void ListSach::deleteNXB(string tensach) {
	for (Node* p=pHead;p!=NULL;p=p->pNext) {
		if (p->data.TEN == tensach)
			p->data.NXB = "";
	}
}
void ListSach::deleteTacGia(string tensach) {
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (p->data.TEN == tensach)
			p->data.TACGIA = "";
	}
}