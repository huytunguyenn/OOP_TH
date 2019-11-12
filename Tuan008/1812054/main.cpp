#include "MangHoaDon.h"
#include "Khach.h"
#include "User.h"
#include "NXB.h"
int main() {
	ListSach l;	// nhập sách
	int n;
	cout << "Nhap so sach ban muon tao: ";
	cin >> n;
	cin.ignore(1);
	l.Input(n);
	cout << endl;
	cout << "----THONG TIN LIST SACH----" << endl;
	l.Output();
	system("pause");
	Khach h;	// sử dụng chức năng tìm sách 
	int lenh = 0;
	int check_login = 0;	//0= chua dang nhap, 1=dang nhap nguoi dung, 2=dang nhap nxb, 3=dang nhap tac gia
	User u;		// sử dụng chức năng mua sách
	MangHoaDon List_Bill;
	NXB nxb; // sử dụng chức năng thêm, xóa, sửa sách nxb
	string username, pass;
	while (lenh != 5) {
		system("cls");
		switch (check_login) {
		case 1:
			cout << "Ban da dang nhap NGUOI DUNG!" << endl;
			break;
		case 2:
			cout << "Ban da dang nhap NXB!" << endl;
			break;
		case 3:
			cout << "Ban da dang nhap TAC GIA!" << endl;
			break;
		default:
			cout << "Ban chua dang nhap!" << endl;
			break;
		}
		cout << "1. Tim sach" << endl;
		cout << "2. Mua sach" << endl;
		cout << "3. Cap nhat don hang" << endl;
		cout << "4. Dang nhap" << endl;
		cout << "5. Thoat" << endl;
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
			while (check_login == 0) {
				system("cls");
				cout << "== VUI LONG DANG NHAP NGUOI DUNG ==" << endl;
				cout << "Nhap username: ";
				cin >> username;
				cout << "Nhap pass: ";
				cin >> pass;
				check_login = u.Check(username, pass);
				if (check_login == 0) {
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
			if (check_login == 1) {
				system("cls");
				u.muaSach(l, List_Bill);
				system("pause");
			}
			else if (check_login != 1 && check_login != 0) { // chức năng này nxb và tác giả ko dc dùng
				system("cls");
				cout << "Chuc nang mua sach khong kha dung" << endl;
				system("pause");
			}
			break;
		case 3:
			while (check_login == 0) {
				system("cls");
				cout << "== VUI LONG DANG NHAP NGUOI DUNG ==" << endl;
				cout << "Nhap username: ";
				cin >> username;
				cout << "Nhap pass: ";
				cin >> pass;
				check_login = u.Check(username, pass);
				if (check_login == 0) {
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
			if (check_login == 1) {
				system("cls");
				u.updateBill(List_Bill);
				system("pause");
			}
			else if (check_login != 1 && check_login != 0) { // chức năng này nxb và tác giả ko dc dùng
				system("cls");
				cout << "Chuc nang dieu chinh don hang khong kha dung" << endl;
				system("pause");
			}
			break;
		case 4:
			int choice_login;
			do {
				system("cls");
				cout << "Chon loai tai khoan." << endl;
				cout << "1. NXB" << endl;
				cout << "2. Tac gia" << endl;
				cout << "3. Nguoi dung" << endl;
				cout << "Lua chon cua ban: ";
				cin >> choice_login;
				if (!(choice_login == 1 || choice_login == 2 || choice_login == 3)) {
					cout << "Vui long chon lai!" << endl;
					system("pause");
				}
			} while (!(choice_login == 1 || choice_login == 2 || choice_login == 3));
			if (choice_login == 1) { // DANG NHAP NXB
				int permit = check_login; // vì check_login sẽ bị thay đổi thành -1
				while (check_login != 2) { // khong la nxb
					system("cls");
					cout << "== VUI LONG DANG NHAP NXB ==" << endl;
					cout << "Nhap username: ";
					cin >> username;
					cout << "Nhap pass: ";
					cin >> pass;
					check_login = nxb.Check(username, pass); // check_login đúng thì =2, ko đúng thì =-1
					nxb.Init(l); // tạo list sách của nxb
					if (check_login == -1) {
						cout << "Dang nhap that bai!" << endl;
						char login;
						cout << "Dang nhap lai? (Y/N): ";
						cin.ignore(1);
						login = getchar();
						if (login == 'N' || login == 'n') {
							check_login = permit;  // trả lại giá trị ban đầu cho check_login
							break;
						}
					}
				}
				if (check_login == 2) {
					cout << endl << "----THONG TIN LIST SACH NXB " << username << " ----" << endl;
					nxb.sach_nxb.Output();
					system("pause");
					int lenh_login;
					system("cls");
					cout << "1. Them sach" << endl;
					cout << "2. Xoa sach" << endl;
					cout << "3. Sua sach" << endl;
					cout << "4. Quay lai" << endl;
					cout << "Lua chon cua ban: ";
					cin >> lenh_login;
					switch (lenh_login) {
					case 1:
						break;
					case 2:
						cin.ignore(1);
						nxb.Delete(l);
						cout << endl << "----THONG TIN LIST SACH NXB "<< username << " SAU KHI XOA ----" << endl;
						nxb.sach_nxb.Output();
						cout << endl << "----THONG TIN LIST SACH SAU KHI XOA ----" << endl;
						l.Output();
						system("pause");
						break;
					case 3:
						break;
					case 4:
						break;
					}
				}

			}
			else if (choice_login == 2) { // DANG NHAP TAC GIA
				
			}
			else if (choice_login == 3) { // DANG NHAP NGUOI DUNG
				int permit = check_login;
				while (check_login != 1) {
					system("cls");
					cout << "== VUI LONG DANG NHAP NGUOI DUNG ==" << endl;
					cout << "Nhap username: ";
					cin >> username;
					cout << "Nhap pass: ";
					cin >> pass;
					check_login = u.Check(username, pass);
					if (check_login == 0) {
						cout << "Dang nhap that bai!" << endl;
						char login;
						cout << "Dang nhap lai? (Y/N): ";
						cin.ignore(1);
						login = getchar();
						if (login == 'N' || login == 'n') {
							check_login = permit; // trả lại giá trị ban đầu cho check_login
							break;
						}
					}
				}
				if (check_login == 1) {
					cout << endl << "----THONG TIN DON HANG CUA NGUOI DUNG ----" << endl;
					List_Bill.Output();
					system("pause");
				}
			}
			break;
		case 5:
			break;
		}
	}
	system("pause");
	return 0;
}