#ifndef _NXB_H_
#define _NXB_H_
#include "Khach.h"
#include "ListSach.h"
class NXB:public Khach
{
public:
	ListSach sach_nxb;
	NXB();
	NXB(string, string);
	NXB(NXB&);
	int Check(string, string);
	void Init(ListSach&);
	void Delete(ListSach&);
	virtual string ClassName();
	virtual Khach* Clone();
};
#endif

