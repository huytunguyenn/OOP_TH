#ifndef _KHACH_H_
#define _KHACH_H_
#include <string>
using namespace std;
class Khach{
public:
	string ten;
	string pass;
	Khach();
	virtual string ClassName() = 0;
};
#endif
