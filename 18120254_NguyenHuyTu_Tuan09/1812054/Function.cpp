#include "Function.h"
void Menu(ADMIN& admin, ListSach& l) {
	User u;		// sử dụng chức năng mua sách
	MangHoaDon List_Bill;
	TacGia tg; 
	NXB nxb; // sử dụng chức năng xóa sách nxb
	string username, pass;
	int lenh = 0;
	int check_login = -1;// -1= chua dang nhap(ko bat dang nhap user), 1=dang nhap nguoi dung, 2=dang nhap nxb, 3=dang nhap tac gia, 4=admin
	while (lenh != 6) {
		system("cls");
		do {
			system("cls");
			switch (check_login) {
			case 1: {
				cout << "Ban da dang nhap USER!" << endl;
				break; }
			case 2: {
				cout << "Ban da dang nhap NXB!" << endl;
				break; }
			case 3: {
				cout << "Ban da dang nhap TAC GIA!" << endl;
				break; }
			case 4: {
				cout << "Ban da dang nhap ADMIN!" << endl;
				break; }
			default: {
				cout << "Ban chua dang nhap!" << endl;
				break; }
			}
			cout << "1. Tim sach" << endl;
			cout << "2. Mua sach" << endl;
			cout << "3. Cap nhat don hang" << endl;
			cout << "4. Dang nhap/ Su dung chuc nang" << endl;
			cout << "5. Dang xuat" << endl;
			cout << "6. Thoat" << endl;
			cout << "Lua chon cua ban: ";
			cin >> lenh;
			if (!(lenh > 0 && lenh < 7)) {
				cout << "Vui long chon lai" << endl;
				system("pause");
			}
		} while (!(lenh > 0 && lenh < 7));
		switch (lenh)
		{
		case 1: {
			system("cls");
			cout << "==== TIM SACH ====" << endl;
			if (l.pHead == NULL)
				cout << endl << "Danh sach sach rong!" << endl << "Khong the tim sach" << endl;
			else
				l.TimSach();
			system("pause");
			break; }
		case 2: {
			if (check_login == 1) {
				system("cls");
				if (l.pHead == NULL)
					cout << endl << "Danh sach sach rong!" << endl << "Khong mua sach duoc!" << endl;
				else {
					// user mua sach, tao list_bill cho user
					u.muaSach(l, List_Bill);
				}
				system("pause");
			}
			else { // chức năng này ngoài user thì ko ai được dùng
				system("cls");
				cout << "Chuc nang mua sach khong kha dung" << endl << "Vui long dang nhap user" << endl;
				system("pause");
			}
			break; }
		case 3: {
			if (check_login == 1) {
				system("cls");
				if (l.pHead == NULL)
					cout << endl << "Danh sach sach rong!" << endl << "Khong the cap nhat don hang!" << endl;
				else
					u.updateBill(List_Bill);
				system("pause");
			}
			else {  // chức năng này ngoài user thì ko ai được dùng
				system("cls");
				cout << "Chuc nang dieu chinh don hang khong kha dung" << endl << "Vui long dang nhap user" << endl;
				system("pause");
			}
			break; }
		case 4: {
			if (check_login == -1) {	// chưa đăng nhập/ đã đăng xuất
				int choice_login;
				do {
					system("cls");
					cout << "Chon loai tai khoan." << endl;
					cout << "1. NXB" << endl;
					cout << "2. Tac gia" << endl;
					cout << "3. User" << endl;
					cout << "4. Admin" << endl;
					cout << "Lua chon cua ban: ";
					cin >> choice_login;
					if (!(choice_login > 0 && choice_login < 5)) {
						cout << "Vui long chon lai!" << endl;
						system("pause");
					}
				} while (!(choice_login > 0 && choice_login < 5));
				if (choice_login == 1) { // MUỐN ĐĂNG NHẬP NXB
					int permit = check_login; // vì check_login sẽ bị thay đổi thành -1
					while (check_login != 2) { // khong la nxb
						system("cls");
						cout << "== VUI LONG DANG NHAP NXB ==" << endl;
						cout << "Nhap username: ";
						cin >> username;
						cout << "Nhap pass: ";
						cin >> pass;
						check_login = admin.CheckNXB(username, pass,nxb); // check_login đúng thì =2, ko đúng thì =-1
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
				}
				else if (choice_login == 2) { // MUỐN ĐĂNG NHẬP TÁC GIẢ
					int permit = check_login;	// vì check_login sẽ bị thay đổi 
					while (check_login != 3) {
						system("cls");
						cout << "== VUI LONG DANG NHAP TAC GIA ==" << endl;
						cout << "Nhap username: ";
						cin >> username;
						cout << "Nhap pass: ";
						cin >> pass;
						check_login = admin.CheckTacGia(username, pass, tg);  // check_login đúng thì =3, ko đúng thì =-1
						tg.Init(l); // tạo list sách của tg
						if (check_login == -1) {
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
				}
				else if (choice_login == 3) { // MUỐN ĐĂNG NHẬP USER
					int permit = check_login;	// vì check_login sẽ bị thay đổi 
					while (check_login != 1) {
						system("cls");
						cout << "== VUI LONG DANG NHAP USER ==" << endl;
						cout << "Nhap username: ";
						cin >> username;
						cout << "Nhap pass: ";
						cin >> pass;
						check_login = admin.CheckUser(username, pass,u);  // check_login đúng thì =1, ko đúng thì =-1
						if (check_login == -1) {
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
				}
				else if (choice_login == 4) {   // MUỐN ĐĂNG NHẬP ADMIN
					int permit = check_login; // vì check_login sẽ bị thay đổi 
					while (check_login != 4) {
						system("cls");
						cout << "== VUI LONG DANG NHAP ADMIN ==" << endl;
						cout << "Nhap username: ";
						cin >> username;
						cout << "Nhap pass: ";
						cin >> pass;
						check_login = admin.Check(username, pass); // check_login đúng thì =4, ko đúng thì =-1
						if (check_login == -1) {
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
				}
			}
			if (check_login == 1) { // ĐÃ ĐĂNG NHẬP USER
				cout << endl << "----THONG TIN DON HANG CUA USER ----" << endl;
				List_Bill.Output();
				system("pause");
			}
			else if (check_login == 2) { // ĐÃ ĐĂNG NHẬP NXB
				cout << endl << "----THONG TIN LIST SACH NXB " << username << " ----" << endl;
				nxb.sach_nxb.Output();
				system("pause");
				int lenh_login;
				do {
					system("cls");
					cout << "1. Xoa sach" << endl;
					cout << "2. Them sach" << endl;
					cout << "3. Sua sach" << endl;
					cout << "4. Quay lai" << endl;
					cout << "Lua chon cua ban: ";
					cin >> lenh_login;
				} while (!(lenh_login > 0 && lenh_login < 5));
				switch (lenh_login) {
				case 1: {
					cin.ignore(1);
					nxb.Delete(l);
					cout << endl << "----THONG TIN LIST SACH NXB " << username << " SAU KHI XOA ----" << endl;
					nxb.sach_nxb.Output();
					cout << endl << "----THONG TIN LIST SACH SAU KHI XOA ----" << endl;
					l.Output();
					system("pause");
					break; }
				case 2: {
					break; }
				case 3: {
					break; }
				case 4: {
					break; }
				}
			}
			else if (check_login == 3) {	// ĐÃ ĐĂNG NHẬP TÁC GIẢ
				cout << endl << "----THONG TIN LIST SACH TAC GIA " << username << " ----" << endl;
				tg.sach_tacgia.Output();
				system("pause");
				int lenh_login;
				do {
					system("cls");
					cout << "1. Xoa sach" << endl;
					cout << "2. Them sach" << endl;
					cout << "3. Sua sach" << endl;
					cout << "4. Quay lai" << endl;
					cout << "Lua chon cua ban: ";
					cin >> lenh_login;
				} while (!(lenh_login > 0 && lenh_login < 5));
				switch (lenh_login) {
				case 1: {
					cin.ignore(1);
					tg.Delete(l);
					cout << endl << "----THONG TIN LIST SACH TAC GiA " << username << " SAU KHI XOA ----" << endl;
					tg.sach_tacgia.Output();
					cout << endl << "----THONG TIN LIST SACH SAU KHI XOA ----" << endl;
					l.Output();
					system("pause");
					break; }
				case 2: {
					break; }
				case 3: {
					break; }
				case 4: {
					break; }
				}
			}
			else if (check_login == 4) {	// ĐÃ ĐĂNG NHẬP ADMIN
				int lenh_login;
				do {
					system("cls");
					cout << "1. Them tai khoan." << endl;
					cout << "2. Them sach" << endl;
					cout << "3. Xem danh sach sach" << endl;
					cout << "4. Xem danh sach tai khoan" << endl;
					cout << "5. Dat khoa (an)" << endl;
					cout << "6. Quay lai" << endl;
					cout << "Lua chon cua ban: ";
					cin >> lenh_login;
				} while (!(lenh_login > 0 && lenh_login < 7));
				switch (lenh_login) {
				case 1: {
					system("cls");
					admin.AddMember();
					cout << "Them tai khoan thanh cong" << endl;
					system("pause");
					break; }
				case 2: {
					system("cls");
					int n;
					cout << "Nhap so sach ban muon tao: ";
					cin >> n;
					cin.ignore(1);
					l.Input(n);
					break; }
				case 3: {
					cout << endl << "---- THONG TIN LIST SACH ----" << endl;
					l.Output();
					system("pause");
					break; }
				case 4: {
					cout << endl<< "---- THONG TIN TAI KHOAN ----" << endl;
					admin.OutputMember();
					system("pause");
					break; }
				case 5: {
					cin.ignore(1);
					admin.DatKhoa(l);
					break; }
				case 6: {
					break; }
				}
			}
			break; }
		case 5: {
			check_login = -1;
			break; }
		case 6: {
			break; }
		}
	}
}
