#include "ListSach.h"



ListSach::ListSach()
{
	pHead = pTail = NULL;
	n = 0;
}

void ListSach::Init(ListSach& l)
{
	l.pHead = l.pTail = NULL;
}

Node* ListSach::getNode(Sach x)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void ListSach::AddHead(ListSach& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
		p->pNext = NULL;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void ListSach::AddTail(ListSach& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
		p->pNext = NULL;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}


void ListSach::Input(ListSach& l, int n)
{
	Sach x;
	Init(l);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin cho cuon sach thu " << i + 1 << endl;
		cin >> x;
		Node* p = getNode(x);
		AddTail(l, p);
	}
}

void ListSach::Output(ListSach l)
{
	int i = 1;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << "Thong tin cuon sach thu " << i++ << endl << p->data << endl;
	}
}


ListSach::~ListSach()
{
	delete[]this->pHead;
	delete[]this->pTail;
}
