#ifndef _USER_H_
#define _USER_H_
#include"Khach.h"
#include "MangHoaDon.h"
class User :public Khach
{
public:
	int age;
	User();
	User(string,string,int);
	User(User&);
	void muaSach(ListSach&, MangHoaDon&);
	void updateBill(MangHoaDon&);
	bool Check(string, string);
	virtual string ClassName();
	virtual Khach* Clone();
};
#endif


