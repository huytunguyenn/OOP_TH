#ifndef _MANGHOADON_H_
#define _MANGHOADON_H_
#include "HoaDon.h"
#include "DoHoa.h"
#include "ListSach.h"

class MangHoaDon{
public:
	list<HoaDon> listhoadon;

	MangHoaDon();
	~MangHoaDon();
	void Output();
	bool updateBill_Soluong();
	void inputListBill(ListSach);
};
#endif

