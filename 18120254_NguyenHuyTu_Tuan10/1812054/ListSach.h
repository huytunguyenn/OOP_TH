#ifndef _LISTSACH_H
#define _LISTSACH_H
#include "Sach.h"
#include <list>
#include <fstream>
using namespace std;
class ListSach{
public:
	list<Sach> listsach;

	ListSach();
	~ListSach();
	void Input(int);
	void Output();
	Sach TimSach();
	int baonhieuTEN(string);
	Sach SearchTEN(string);
	Sach SearchMA(string);
	void deleteName(string);
	void deleteNXB(string);
	void deleteTacGia(string);
};

#endif




