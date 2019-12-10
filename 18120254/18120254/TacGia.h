#ifndef _TACGIA_H_
#define _TACGIA_H_
#include "Khach.h"
#include "ListSach.h"
class TacGia :public Khach{
public:
	ListSach sach_tacgia;
	TacGia();
	TacGia(string, string);
	TacGia(TacGia&);
	int Check(string, string);
	void Init(ListSach&);
	void Delete(ListSach&);
	virtual string ClassName();
};
#endif

