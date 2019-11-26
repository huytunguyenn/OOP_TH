#ifndef _LISTSACH_H
#define _LISTSACH_H
#include "Sach.h"
class Node {
public:
	Sach data;
	Node* pNext;
	friend class ListSach;
};
class ListSach
{
public:
	Node* pHead;
	Node* pTail;
	ListSach();
	int isEmpty() {
		return pHead == NULL;
	}
	~ListSach();
	Node* getNode(Sach);
	void AddHead(Node*);
	void AddTail(Node*);
	void Input(int);
	void Output();
	void TimSach();
	//int SearchViTriMA(string);
	//int SearchViTriTEN(string);
	int baonhieuTEN(string);
	//void changePriceByMA(string, int);
	//void changePriceByTEN(string, int);
	Sach SearchTEN(string);
	Sach SearchMA(string);
	void deleteName(string);
	void deleteNXB(string);
	void deleteTacGia(string);
};

#endif




