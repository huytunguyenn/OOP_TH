#ifndef _LISTSACH_H
#define _LISTSACH_H
#include "Sach.h"
#include "Khach.h"
class Node {
public:
	Sach data;
	Node* pNext;
	friend class ListSach;
};
class ListSach
{
private:
	
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
	int SearchViTriMA(string);
	int SearchViTriTEN(string);
	int baonhieuTEN(string);
	//void changePriceByMA(string, int);
	//void changePriceByTEN(string, int);
	Sach SearchTEN(string);
	Sach SearchMA(string);
	void deleteName(string);
	void deleteNXB(string);
};

#endif




