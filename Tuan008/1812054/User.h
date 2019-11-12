#include"Khach.h"
#include "MangHoaDon.h"
class User :public Khach
{
	string pass;
	string name;
	int tuoi;
public:
	void muaSach(ListSach& List_Book, MangHoaDon& List_Bill);
	void updateBill(MangHoaDon& List_Bill);
	User();
	bool Check(string, string);
};


