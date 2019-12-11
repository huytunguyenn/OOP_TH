#ifndef _SACH_H_
#define _SACH_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Sach {
public:
	string TEN;
	string MA;
	string TACGIA;
	string NXB;
	unsigned int GIA;
	vector<string> LOCK;

	Sach();
	friend ostream& operator<<(ostream&, Sach);
	friend istream& operator>>(istream&, Sach&);
	friend class ListSach;
};
#endif

