#include "Header.h"

int printMenu()
{
	int lenh;
	cout << "WELCOME TO MY SYSTEM" << endl;
	cout << "1. Xem sach" << endl;
	cout << "2. Mua sach" << endl;
	cout << "3. Thoat." << endl;
	cin >> lenh;
	return lenh;
}

void getAccount(string& ten, string& pass)
{
	cin.ignore();
	cout << "Enter your name: "; getline(cin , ten);
	cout << "Enter your password: "; getline(cin , pass);
}
