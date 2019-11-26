#include "Guest.h"



void Guest::TimSach(ListSach& l){
	Sach temp = l.TimSach();
	cout << temp << endl;
}

void Guest::Signup(ADMIN& admin) {
	int choice;
	do {
		system("cls");
		cout << "== CAC LOAI TAI KHOAN ==" << endl;
		cout << "1. NXB" << endl;
		cout << "2. Tac gia" << endl;
		cout << "3. User" << endl;
		cout << "4. Admin" << endl;
		cout << "5. Quay lai" << endl;
		cout << "Chon loai tai khoan muon them: ";
		cin >> choice;
	} while (!(choice > 0 && choice < 6));
	string username, password;
	int age;
	if (choice == 1) {
		cout << "== TAO TAI KHOAN NXB == " << endl;
		cout << "Tao username: ";
		cin >> username;
		cout << "Tao password: ";
		cin >> password;
		Khach* temp = new NXB(username, password);
		admin.member.push_back(temp);
	}
	else if (choice == 2) {
		cout << "== TAO TAI KHOAN TAC GIA == " << endl;
		cout << "Tao username: ";
		cin >> username;
		cout << "Tao password: ";
		cin >> password;
		Khach* temp = new TacGia(username, password);
		admin.member.push_back(temp);
	}
	else if (choice == 3) {
		cout << "== TAO TAI KHOAN USER == " << endl;
		cout << "Tao username: ";
		cin >> username;
		cout << "Tao password: ";
		cin >> password;
		cout << "Tuoi: ";
		cin >> age;
		Khach* temp = new User(username, password, age);
		admin.member.push_back(temp);
	}
	else if (choice == 4) {
		cout << "== TAO TAI KHOAN ADMIN == " << endl;
		cout << "Tao username: ";
		cin >> username;
		cout << "Tao password: ";
		cin >> password;
		//vo file admin.txt ghi admin
	}
	system("pause");
}
