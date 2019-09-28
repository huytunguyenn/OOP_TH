#ifndef _SACH_H_
#define _SACH_H_
#include <iostream>
#include <string>
using namespace std;
class Sach
{
private:
	string TEN;
	string MA;
	int GIA;
public:
	Sach();
	string getTEN();
	string getMA();
	int getGIA();
	void setTEN(string);
	void setMA(string);
	void setGIA(int);
	friend ostream& operator<<(ostream& , Sach);
	friend istream& operator>>(istream& , Sach&);
};
#endif

