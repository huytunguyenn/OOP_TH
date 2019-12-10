#include "Guest.h"



Book guest::Timsach(ListBook& Listbook)
{
	string BookName;
	cout << "Vui long nhap ten sach" << endl;
	cin >> BookName;

	return Listbook.GetBookPosition_i(Listbook.findBookbyName(BookName));
}



guest::guest()
{
}


guest::~guest()
{
}
