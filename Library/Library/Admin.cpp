#include "Admin.h"



string Admin::getObjName()
{
	return "Admin";
}

void Admin::AddBook(ListBook& List_Book)
{
	List_Book.inputList();
}

string Admin::getUsername()
{
	return this->username;
}

string Admin::getPassword()
{
	return this->password;
}

void Admin::DeleteBook(ListBook& List_Book, vector<Hide>& HiddenBook)
{
	string tensach, masach;
	int Vitri;
	cout << "Nhap ten sach" << endl;
	cin >> tensach;
	Vitri = List_Book.findBookbyName(tensach);
	//TH ko tim thay
	if (Vitri == -1) {
		cout << "ko tim thay" << endl;;
	}
	//TH tim nhieu hon 1 quyen
	if (Vitri == -2) {
		cout << "Vui long nhap ma sach" << endl;;
		cin >> masach;
		//Tim by ma sach
		Vitri = List_Book.findBookbyMasach(masach);
		if (Vitri != -1) {
			if (this->getObjName() == "Author") {
				HiddenBook[Vitri].Author = false;
				return;
			}
			if (this->getObjName() == "NXB") {
				HiddenBook[Vitri].NXB = false;
				return;
			}
			if (this->getObjName() == "Admin") {
				List_Book.deleteBook(Vitri);
			}
			}
		else {
			cout << "ko tim thay" << endl;;
		}
	}
	//TH tim thay 1 quyen
		if (this->getObjName() == "Author") {
			HiddenBook[Vitri].Author = false;
			return;
		}
		if (this->getObjName() == "NXB") {
			HiddenBook[Vitri].NXB = false;
			return;
		}
		if (this->getObjName() == "Admin") {
			List_Book.deleteBook(Vitri);
		}
}

Admin::Admin(string username, string password)
{
	this->username = username;
	this->password = password;
}

Admin::Admin()
{
}


Admin::~Admin()
{
}
