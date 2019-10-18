#include "MangHoaDon.h"

int main() {
	//nhap sach
	ListSach l;
	int n;
	cout << "Nhap so sach ban muon tao: ";
	cin >> n;
	l.Input(n);
	cout << endl;
	cout << "----THONG TIN LIST SACH----" << endl;
	l.Output();
	//mua nhieu loai sach
	MangHoaDon mhd;
	int n1;
	cout << "Nhap so hoa don ban muon mua: ";
	cin >> n1;
	for (int i = 0; i < n1;i++) {
		string tempTEN;
		cout << endl << "Nhap ten sach muon mua: ";
		cin >> tempTEN;
		int tempSL;
		cout << "Nhap so luong: ";
		cin >> tempSL;
		HoaDon hd;
		if (l.baonhieuTEN(tempTEN) > 1)
		{
			cout << "Sach bi trung ten" << endl;
			string tempMA;
			cout << "Nhap ma sach: ";
			cin >> tempMA;
			Sach mua = l.SearchMA(tempMA);
			hd.addSach(mua, tempSL);
			mhd.addHoaDon(hd);
		}
		else if (l.baonhieuTEN(tempTEN)==0) {
			cout << "Sach khong ton tai!" << endl;
			return 1;
		}
		else
		{
			Sach mua = l.SearchTEN(tempTEN);
			hd.addSach(mua, tempSL);
			mhd.addHoaDon(hd);
		}
	}
	mhd.Output();

	system("pause");

	return 0;
}