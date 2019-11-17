#ifndef _SACH_H_
#define _SACH_H_
#include <iostream>
#include <string>
using namespace std;
class Sach
{
public:
	string TEN;
	string MA;
	string TACGIA;
	string NXB;
	double GIA;
	Sach();
	void setTEN(string);
	void setMA(string);
	void setGIA(int);
	friend ostream& operator<<(ostream&, Sach);
	friend istream& operator>>(istream&, Sach&);
	friend class ListSach;
};
#endif

