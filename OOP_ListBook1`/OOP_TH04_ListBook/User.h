#ifndef _USER_H_
#define _USER_H_
#include"Guest.h"
#include"Account.h"

class User:public Guest,public Account
{
private:
	int mTuoi;
	DS_HoaDon hd_user;

public:
	User();
	~User();
	
	void setTuoiUser(int t);
	int getTuoiUser();
	DS_HoaDon muaSach(ListBook& l);
	void upDateHoaDon(DS_HoaDon& a);
};


#endif // !_USER_H_


