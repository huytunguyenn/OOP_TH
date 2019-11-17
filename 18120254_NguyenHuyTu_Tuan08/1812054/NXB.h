#ifndef _NXB_H_
#define _NXB_H_
#include "ListSach.h"
class NXB
{
public:
	string ten;
	string pass;
	ListSach sach_nxb;
	NXB();
	~NXB();
	int Check(string, string);
	void Init(ListSach&);
	void Delete(ListSach&);
};
#endif

