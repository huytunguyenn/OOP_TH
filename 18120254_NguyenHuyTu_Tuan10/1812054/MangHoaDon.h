#ifndef _MANGHOADON_H_
#define _MANGHOADON_H_
#include "HoaDon.h"
#include "DoHoa.h"
#include "ListSach.h"

class HdNode {
	HoaDon data;
	HdNode* pNext;
	friend class MangHoaDon;
};
class MangHoaDon
{
public:
	HdNode* pHead;
	HdNode* pTail;
	int n;
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
	bool updateBill_Soluong();
	void inputListBill(ListSach);
};
#endif

