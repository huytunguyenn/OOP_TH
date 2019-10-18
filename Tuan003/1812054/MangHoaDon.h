#ifndef _MANGHOADON_H_
#define _MANGHOADON_H_
#include "HoaDon.h"

class HdNode {
	HoaDon data;
	HdNode* pNext;
	friend class MangHoaDon;
};
class MangHoaDon
{
private:
	HdNode* pHead;
	HdNode* pTail;
	int n;
public:
	MangHoaDon();
	int isEmpty() {
		return pHead == NULL;
	}
	~MangHoaDon();
	HdNode* getNode(HoaDon);
	void addHead(HdNode*);
	void addTail(HdNode* );
	void addHoaDon(HoaDon a);
	void Output();
};
#endif

