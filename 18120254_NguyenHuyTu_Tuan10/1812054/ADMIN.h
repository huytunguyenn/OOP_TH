#ifndef _ADMIN_H_
#define _ADMIN_H_
#include "NXB.h"
#include "TacGia.h"
#include "User.h"
#include "ListSach.h"
#include <list>
class ADMIN
{
public:
	string name;
	string pass;
	list<Khach*> member;
	ADMIN();
	~ADMIN();
	int Check(string, string);
	void AddMember();
	void OutputMember();
	int CheckUser(string,string,User&);
	int CheckNXB(string, string,NXB&);	
	int CheckTacGia(string, string,TacGia&);
	void DatKhoa(ListSach&);
};
#endif
