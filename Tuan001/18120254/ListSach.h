#ifndef _LISTSACH_H
#define _LISTSACH_H
#include "Sach.h"
#include <iostream>
#include <string>
using namespace std;
class Node {
	Sach data;
	struct Node* pNext;
	friend class ListSach;
};
class ListSach 
{
private:
	Node* pHead;
	Node* pTail;
	int n;
public:
	ListSach();
	~ListSach();
	void Init(ListSach& l);
	Node* getNode(Sach);
	void AddHead(ListSach&, Node*);
	void AddTail(ListSach&, Node*);
	void Input(ListSach&, int);
	void Output(ListSach);
};

#endif




