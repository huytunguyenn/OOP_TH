#include "MangHoaDon.h"
#include "Khach.h"
#include "User.h"
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
	system("pause");
	Khach h;
	int lenh = 0;
	bool check = false;
	User u;
	MangHoaDon List_Bill;
	string username, pass;
	while (lenh != 4) {
		system("cls");
		if (check == true)
			cout << "Ban da dang nhap!" << endl;
		cout << "1. Tim Sach" << endl;
		cout << "2. Mua Sach" << endl;
		cout << "3. Cap nhat don hang" << endl;
		cout << "4. Thoat" << endl;
		cout << "Lua chon cua ban: ";
		cin >> lenh;
		switch (lenh)
		{
		case 1:
			system("cls");
			cout << "==== TIM SACH ====" << endl;
			h.TimSach(l);
			system("pause");
			break;
		case 2:
		{
			while (check == false) {
				system("cls");
				cout << "== VUI LONG DANG NHAP ==" << endl;
				cout << "Nhap username: ";
				cin >> username;
				cout << "Nhap pass: ";
				cin >> pass;
				check = u.Check(username, pass);
				if (check == false) {
					cout << "Dang nhap that bai!" << endl;
					char login;
					cout << "Dang nhap lai? (Y/N): ";
					cin.ignore(1);
					login = getchar();
					if (login == 'N'||login=='n') {
						break;
					}
				}
			}
			if (check == true) {
				system("cls");
				u.muaSach(l, List_Bill);
				system("pause");
			}
			break;
		}
		case 3: {
			while(check==false) {
				system("cls");
				cout << "== VUI LONG DANG NHAP ==" << endl;
				cout << "Nhap username: ";
				cin >> username;
				cout << "Nhap pass: ";
				cin >> pass;
				check = u.Check(username, pass);
				if (check == false) {
					cout << "Dang nhap that bai!" << endl;
					char login;
					cout << "Dang nhap lai? (Y/N): ";
					cin.ignore(1);
					login = getchar();
					if (login == 'N' || login == 'n') {
						break;
					}
				}
			} 
			if (check == true) {
				system("cls");
				u.updateBill(List_Bill);
				system("pause");
			}
			break;
		}
		case 4:
			break;
		}
	}
	system("pause");
	return 0;
}