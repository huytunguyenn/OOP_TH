#include "ListSach.h"
#include "Sach.h"
int main()
{
	ListSach l;
	int n;
	cout << "Nhap so sach ban muon tao: ";
	cin >> n;
	l.Input(l, n);
	cout << endl;
	l.Output(l);
	system("pause");
	return 0;
}