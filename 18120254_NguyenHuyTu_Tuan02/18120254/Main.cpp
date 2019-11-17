#include "ListSach.h"
#include "Sach.h"
int main()
{
	//nhap sach
	ListSach l;
	int n;
	cout << "Nhap so sach ban muon tao: ";
	cin >> n;
	l.Input(n);
	cout << endl;
	cout << "----THONG TIN LIST SACH----" << endl;
	l.Output();
	//tim sach
	string tempTEN;
	cout <<endl<< "Nhap ten sach muon tim: ";
	cin >> tempTEN;
	cout << "----THONG TIN SACH CAN TIM----" << endl;
	l.OutputTEN(tempTEN);
	//xoa sach
	string delTEN;
	cout<<endl << "Nhap ten sach muon xoa: ";
	cin >> delTEN;
	if (l.baonhieuTEN(delTEN) > 1)
	{
		cout << "Sach bi trung ten" << endl;
		string tempMA;
		cout << "Nhap ma sach: ";
		cin >> tempMA;
		l.DelByMA(tempMA);
		cout << "Xoa sach thanh cong" << endl;
	}
	else
	{
		l.DelByTEN(delTEN);
		cout << "Xoa sach thanh cong" << endl;
	}
	cout << "----THONG TIN LIST SACH SAU KHI XOA----" << endl;
	l.Output();
	//cap nhat gia
	string tempTEN2;
	cout << endl << "Nhap ten sach muon doi gia: ";
	cin >> tempTEN2;
	if (l.baonhieuTEN(tempTEN2) > 1)
	{
		cout << "Sach bi trung ten" << endl;
		string tempMA2;
		cout << "Nhap ma sach: ";
		cin >> tempMA2;
		int giamoi;
		cout << "Nhap gia moi: ";
		cin >> giamoi;
		l.changePriceByMA(tempMA2,giamoi);
		cout << "Cap nhat gia thanh cong" << endl;
	}
	else
	{
		int giamoi;
		cout << "Nhap gia moi: ";
		cin >> giamoi;
		l.changePriceByTEN(tempTEN2,giamoi);
		cout << "Cap nhat gia thanh cong" << endl;
	}
	cout << "----THONG TIN LIST SACH SAU KHI CAP NHAT GIA----" << endl;
	l.Output();
	system("pause");
	return 0;
}