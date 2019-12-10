#include "Library.h"



Library::Library()
{
	
	this->USER.role = "Guest";
	this->ReadListBookFromFile("data/Book.txt");
	this->ReadListUserFromFile("data/User.txt");
	this->ReadListAdminFromFile("data/Admin.txt");
	this->ReadListAuthorFromFile("data/Author.txt");
	this->ReadListNXBFromFile("data/NXB.txt");
	this->ReadListMailFromFile("data/Mail.txt");
	this->ReadListBillFromFile("data/Bill.txt");
	this->ReadListHiddenBookFromFile("data/HiddenBook.txt");
	}


Library::~Library()
{
	this->WriteListBookToFile("data/Book.txt");
	this->WriteListUserToFile("data/User.txt");
	this->WriteListAdminToFile("data/Admin.txt");
	this->WriteListAuthorToFile("data/Author.txt");
	this->WriteListNXBToFile("data/NXB.txt");
	this->WriteListMailToFile("data/Mail.txt");
	this->WriteListBillToFile("data/Bill.txt");
	this->WriteListHiddenBookToFile("data/HiddenBook.txt");
}

void Library::run()
{
	while (this->USER.role != "") {
		if (this->USER.role == "Guest") {
			this->GuestFunction();
		}
		if (this->USER.role == "Author") {
			this->AuthorFunction();
		}
		if (this->USER.role == "Admin") {
			this->AdminFunction();
		}
		if (this->USER.role == "NXB") {
			this->NXBFunction();
		}
		if (this->USER.role == "User") {
			this->UserFunction();
		}
	}
}

void Library::Login()
{
	string username;
	string password;
	cout << "Username: ";
	cin >> username; 
	cout << "password: ";
	password = this->InputPassword();
	//check user
	for (int i = 0; i < this->List_User.size(); i++) {
		if (this->List_User[i].getName() == username && this->List_User[i].getPass() == password) {
			this->USER.role = "User";
			this->USER.username = username;
		}
	}
	//check Admin
	for (int i = 0; i < this->List_Admin.size(); i++) {
		if (this->List_Admin[i].getUsername() == username && this->List_Admin[i].getPassword() == password) {
			this->USER.role = "Admin";
			this->USER.username = username;
		}
	}
	//check NXB
	for (int i = 0; i < this->List_NXB.size(); i++) {
		if (this->List_NXB[i].getUsername() == username && this->List_NXB[i].getPassword() == password) {
			this->USER.role = "NXB";
			this->USER.username = username;
		}
	}
	//check Author
	for (int i = 0; i < this->List_Author.size(); i++) {
		if (this->List_Author[i].getUsername() == username && this->List_Author[i].getPassword() == password) {
			this->USER.role = "Author";
			this->USER.username = username;
		}
	}
	if (this->USER.role == "Guest") {
		cout << "Dang nhap that bai" << endl;
	}
}

void Library::MailBox()
{
	int Optional = -1;

	while (Optional!= 3) {
		system("cls");
		cout << "THis is " << this->USER.username << "'s MailBox" << endl;
		this->Menu.MailMenu();
		Optional = this->Optional();
		//Doc thu
		if (Optional == 1) {
			int k = 0;
			for (int i = 0; i < this->List_Mail.size(); i++) {
				if (this->USER.username == this->List_Mail[i].GetNguoiNhan()) {
					this->List_Mail[i].ReadMail();
					k++;
				}
			}
			if (k == 0) {
				cout << "ban khong co thu nao het !!" << endl;
			}
		}
		//gui thu
		if (Optional == 2) {
			this->WriteMail();
		}
		system("pause");
	}
}

void Library::GuestFunction()
{
	int Optional = -1;
	while(Optional!=4){
		system("cls");
		cout << "Your account " << this->USER.role << endl;
		this->Menu.GuestMenu();
		Optional = this->Optional();
		if (Optional == 1) {
			//List_Book.findFunction();
			this->Findbook();
		}
		if (Optional == 2) {
			this->Login();
		}
		if (Optional == 3) {
			this->RegisterUser();
		}
		if (this->USER.role != "Guest") {
			return;
		}
		system("pause");
	}
	this->USER.role = "";
}
void Library::Findbook()
{
	int Vitri = this->List_Book.findFuntionReturnVitri();
	//TH ko tim thay
	if (Vitri == -1) {
		cout << "Khong tim thay";
	}
	//TH tim thay
	if (Vitri != -1) {
		Hide tempHide = this->List_HiddenBook[Vitri];
		//TH guest va user
		if (this->USER.role == "Guest" || this->USER.role == "User") {
			if (tempHide.Admin == false && tempHide.Author == false && tempHide.NXB == false) {
				Book tempBook = this->List_Book.GetBookPosition_i(Vitri);
				tempBook.outputSach();
			}
			else {
				cout << "Cuon sach nay tam thoi bi khoa" << endl;
			}
		}
		//TH NXB
		if (this->USER.role == "NXB" ) {
			if (tempHide.Admin == false ) {
				Book tempBook = this->List_Book.GetBookPosition_i(Vitri);
				tempBook.outputSach();
			}
			else {
				cout << "Cuon sach nay tam thoi bi khoa" << endl;
			}
		}
		//TH Author
		if (this->USER.role == "Author") {
			if (tempHide.Admin == false) {
				Book tempBook = this->List_Book.GetBookPosition_i(Vitri);
				tempBook.outputSach();
			}
			else {
				cout << "Cuon sach nay tam thoi bi khoa" << endl;
			}
		}
		//TH admin
		if (this->USER.role == "Admin") {
				Book tempBook = this->List_Book.GetBookPosition_i(Vitri);
				tempBook.outputSach();
		}
	}
}

void Library::Lockbook()
{
	int Vitri = this->List_Book.findFuntionReturnVitri();
	//TH ko tim thay
	if (Vitri == -1) {
		cout << "Khong tim thay";
	}
	//TH tim thay
	if (Vitri != -1) {
		Hide tempHide = this->List_HiddenBook[Vitri];
		//TH NXB
		if (this->USER.role == "NXB") {
			if (tempHide.NXB == true) {
				system("cls");
				cout << "Cuon sach nay da bi khoa !!!" << endl;
				cout << "Ban co muon mo khoa: " << endl;
				cout << "1-Co " << endl;
				cout << "2-Khong" << endl;
				int lenh = this->Optional();
				if (lenh == 1) {
					tempHide.NXB = false;
				}
			}
			else {
				tempHide.NXB = true;
			}
		}
		//TH Author
		if (this->USER.role == "Author") {
			if (tempHide.Author == true) {
				system("cls");
				cout << "Cuon sach nay da bi khoa !!!" << endl;
				cout << "Ban co muon mo khoa: " << endl;
				cout << "1-Co " << endl;
				cout << "2-Khong" << endl;
				int lenh = this->Optional();
				if (lenh == 1) {
					tempHide.Author = false;
				}
			}
			else {
				tempHide.Author = true;
			}
		}
		//TH admin
		if (this->USER.role == "Admin") {
			if (tempHide.Admin == true) {
				system("cls");
				cout << "Cuon sach nay da bi khoa !!!" << endl;
				cout << "Ban co muon mo khoa: " << endl;
				cout << "1-Co " << endl;
				cout << "2-Khong" << endl;
				int lenh = this->Optional();
				if (lenh == 1) {
					tempHide.Admin = false;
				}
			}
			else {
				tempHide.Admin = true;
			}
		}
		this->List_HiddenBook[Vitri] = tempHide;
	}
}

void Library::RegisterUser()
{
	string username;
	string password;
	string repeatPassword;
	int tuoi;
	bool checkUsername = false;
	bool checkPasswordIsSame = false;
	int n = this->List_User.size();
	//nhap username va kiem tra 
	while (checkUsername == false) {
		system("cls");
		cout << "--- Dien vao don dang ky ---" << endl;
		cout << "Vui long nhap username : ";
		cin >> username;
		for (int i = 0; i <n ; i++) {
			if (this->List_User[i].getName() == username) {
				break;
			}
			if (i == n - 1) {
				checkUsername = true;
			}
		}
		if (checkUsername == false) {
			cout << "Ten dang nhap da bi trung !!!" << endl;
			system("pause");
		}
	}
	//nhap password
	while (checkPasswordIsSame == false) {
		cout << "Vui long nhap password: ";
		password = this->InputPassword();
		cout << "Nhap lai password: " ;
		repeatPassword = this->InputPassword();
		if (password == repeatPassword) {
			checkPasswordIsSame = true;
		}
		else
		{
			cout << "password khong trun vui long nhap lai!!!" << endl;
		}
	}
	
	//nhap tuoi
	cout << "Vui long nhap tuoi: ";
	cin >> tuoi;
	//them user vao user list
	user tempUser(username,password,tuoi);
	this->List_User.push_back(tempUser);
}

void Library::NXBFunction()
{
	int Optional = -1;
	while (Optional != 4) {
		system("cls");
		cout << "Your account " << this->USER.role << endl;
		this->Menu.NXBMenu();
		Optional = this->Optional();
		if (Optional == 1) {
			this->Findbook();
		}
		if (Optional == 2) {
			this->List_Book.inputList();
			this->addHiddenBook();
		}
		if (Optional == 3) {
			this->Lockbook();
		}
		system("pause");
	}
	this->USER.role = "Guest";
	this->GuestFunction();
}

void Library::AuthorFunction()
{
	int Optional = -1;
	while (Optional != 4) {
		system("cls");
		cout << "Your account " << this->USER.role << endl;
		this->Menu.AuthorMenu();
		Optional = this->Optional();
		if (Optional == 1) {
			this->Findbook();
		}
		if (Optional == 2) {
			this->List_Book.inputList();
			this->addHiddenBook();
		}
		//khoa sach
		if (Optional == 3) {
			this->Lockbook();
		}
		system("pause");
	}
	this->USER.role = "Guest";
	this->GuestFunction();
}

void Library::UserFunction()
{
	int Optional = -1;
	while (Optional != 6) {
		system("cls");
		cout << "Your account " << this->USER.role << endl;
		this->Menu.UserMenu();
		Optional = this->Optional();
		//timsach
		if (Optional == 1) {
			this->Findbook();
		}
		//mua sach
		if (Optional == 2) {
			ListBill tempListBill;
			int n = this->Listof_ListBill.size();
			//tim listbill cua user nao do;
			for (int i = 0; i < n; i++) {
				if (this->Listof_ListBill[i].getUsername() == this->USER.username) {
					tempListBill = this->Listof_ListBill[i];
				}
			}
			//th chua co trong listof_ListBill
			if (tempListBill.getUsername() != this->USER.username) {
				tempListBill.setUsername(this->USER.username);
			}
			//mua sach
			tempListBill.inputListBill(this->List_Book);
			//gan vao listof_ListBill
			bool checkAdd = true;
			for (int i = 0; i < n; i++) {
				if (this->Listof_ListBill[i].getUsername() == this->USER.username) {
					this->Listof_ListBill[i] = tempListBill;
					checkAdd = false;
				}
				if (checkAdd == true && i == n - 1) {
					this->Listof_ListBill.push_back(tempListBill);
				}
			}
		}

		//cap nhap bill
		if (Optional == 3) {
			ListBill tempListBill;
			int n = this->Listof_ListBill.size();
			//tim listbill cua user nao do;
			for (int i = 0; i < n; i++) {
				if (this->Listof_ListBill[i].getUsername() == this->USER.username) {
					tempListBill = this->Listof_ListBill[i];
				}
			}
			//neu ko co bill nao thi ko cap nhap
			if (tempListBill.getSoluong() == 0) {
				cout << "khong co bill nao de cap nhap" << endl;
			}
			//cap nhap
			else {
				int positionBill;
				int lenh=0;
				//Thuc hien cap nhap
				while (lenh != 3) {
					system("cls");
					tempListBill.outputListBill();
					//chon loai update 1-xoa hoadon/ 2-thay doi so luong
					this->Menu.UpdateBillMenu();
					lenh = this->Optional();
					if (lenh != 3) {
						cout << "Vui long nhap hoa don ban muon cap nhap : ";
						cin >> positionBill;
					}
					//xoa hoa don
					if (lenh == 1) {
						tempListBill.deleteBillPosition_I(positionBill-1);
					}
					//thay doi so luong sach mua
					if (lenh == 2) {
						tempListBill.UpdateAmountBillPosition_I(positionBill - 1);
					}
				}
			}
			//gan lai vao listof_ListBill
			for (int i = 0; i < n; i++) {
				if (this->Listof_ListBill[i].getUsername() == this->USER.username) {
					this->Listof_ListBill[i] = tempListBill;
				}
			}
			//xong
		}
		if (Optional == 4) {
			ListBill tempListBill;
			int n = this->Listof_ListBill.size();
			//tim listbill cua user nao do;
			for (int i = 0; i < n; i++) {
				if (this->Listof_ListBill[i].getUsername() == this->USER.username) {
					tempListBill = this->Listof_ListBill[i];
				}
			}
			tempListBill.outputListBill();
		}
		
		//hop thu
		if (Optional == 5) {
			this->MailBox();
		}
		system("pause");
	}
	this->USER.role = "Guest";
	this->GuestFunction();
}

void Library::AdminFunction()
{
	int Optional = -1;
	while (Optional != 4) {
		system("cls");
		cout << "Your account " << this->USER.role << endl;
		this->Menu.AdminMenu();
		Optional = this->Optional();
		if (Optional == 1) {
			this->Findbook();
		}
		if (Optional == 2) {
			this->List_Book.inputList();
			this->addHiddenBook();
		}
		//khoa sach
		if (Optional == 3) {
			this->Lockbook();
		}
	}
	this->USER.role = "Guest";
	this->GuestFunction();
}

string Library::InputPassword()
{
	printf("_______________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	char c = '.', password[16];
	int i = 0;
	while (c != 13) {
		if (_kbhit())
		{
			c = _getch();
			if (c != 13) {
				if (c != 8 && i<16)
				{
					printf("*");
					password[i] = c;
					i++;
				}
				if(c==8 && i>0)
				{
					if (i != 0) {
						printf("\b_\b");
						i--;
						password[i] = '\0';
					}
				}
			}
		}
	}
	password[i] = '\0';
	string s="";
	for (int k = 0; k < i; k++) {
		s = s + password[k];
	}
	cout << endl;
	return s;
}

void Library::addHiddenBook()
{
	int nListBook = this->List_Book.get_soluong();
	int nListHiddenBook = this->List_HiddenBook.size();
	
	int k = nListBook - nListHiddenBook;
	cout << k;
	Hide tempHiddenBook;
	//set
	tempHiddenBook.Author = false;
	tempHiddenBook.Admin = false;
	tempHiddenBook.NXB = false;
	for (int i = 0; i < k; i++) {
		this->List_HiddenBook.push_back(tempHiddenBook);
	}
}

void Library::ReadListBookFromFile(string link)
{
	ifstream fileInput(link);
	if (fileInput.fail())
	{
		std::cout << "Failed to open this file!" << endl;
		return;
	}
	string Tensach;
	string Masach;
	string NXB;
	string Author;
	int giatien;
	char temp[255];
	while (!fileInput.eof())
	{
		fileInput.getline(temp, 255);
		Tensach = temp;
		fileInput.getline(temp, 255);
		Masach = temp;
		fileInput.getline(temp, 255);
		NXB = temp;
		fileInput.getline(temp, 255);
		Author = temp;
		fileInput.getline(temp, 255);
		giatien = this->ChangeStringisNumber(temp);
		Book tempBook;
		tempBook.set_Tensach(Tensach);
		tempBook.set_Masach(Masach);
		tempBook.set_Giatien(giatien);
		tempBook.set_Author(Author);
		tempBook.set_NXB(NXB);
		this->List_Book.pushBack(tempBook);
	}
	/*for (int i = 0; i < this->List_Book.get_soluong(); i++) {
		Book tempbook;
		tempbook = this->List_Book.GetBookPosition_i(i);
		cout << tempbook.get_Tensach() << endl;
		cout << tempbook.get_Masach() << endl;
		cout << tempbook.get_Giatien() << endl;
		cout << tempbook.get_Author() << endl;
		cout << tempbook.get_NXB() << endl;
		system("pause");
	}*/
	fileInput.close();
}

void Library::ReadListUserFromFile(string link)
{
	ifstream fileInput(link);
	if (fileInput.fail())
	{
		std::cout << "Failed to open this file!" << endl;
		return;
	}
	string name;
	string pass;
	int tuoi;
	char temp[255];
	while (!fileInput.eof())
	{
		fileInput.getline(temp, 255);
		name = temp;
		fileInput.getline(temp, 255);
		pass = temp;
		fileInput >> tuoi;
		fileInput.getline(temp, 255);
		user tempUser(name,pass,tuoi);
		this->List_User.push_back(tempUser);
	}
	fileInput.close();
}

void Library::ReadListAdminFromFile(string link)
{
	ifstream fileInput(link);
	if (fileInput.fail())
	{
		std::cout << "Failed to open this file!" << endl;
		return;
	}
	string username;
	string password;
	char temp[255];
	while (!fileInput.eof())
	{
		fileInput.getline(temp, 255);
		username = temp;
		fileInput.getline(temp, 255);
		password = temp;
		Admin tempAdmin(username, password);
		this->List_Admin.push_back(tempAdmin);
	}
	fileInput.close();
}

void Library::ReadListBillFromFile(string link)
{
	ifstream fileInput(link);
	if (fileInput.fail())
	{
		std::cout << "Failed to open this file!" << endl;
		return;
	}
	string masach;
	string username;
	int soluongSach;
	int tien;
	char temp[255];
	string soluongBill;
	while (!fileInput.eof())
	{
		//doc soluong bill cua user
		fileInput.getline(temp, 255);
		soluongBill = temp;
		//doc ten user
		fileInput.getline(temp, 255);
		username = temp;
		//gan n = so luong bill
		int n = this->ChangeStringisNumber(soluongBill);
		//tao danh sach bill tam thoi
		ListBill tempListBill;
		//gan username cua bill do 
		tempListBill.setUsername(username);
		//doc lan luot cac bill
		for (int i = 0; i < n; i++) {
				//doc ma sach
				fileInput.getline(temp, 255);
				masach = temp;
				//timsach
				Book tempBook;
				int vitriSach = this->List_Book.findBookbyMasach(masach);
				if (vitriSach != -1) {
					tempBook = this->List_Book.GetBookPosition_i(vitriSach);
				}
				//doc so luong sach cua bill
				fileInput.getline(temp, 255);
				soluongSach = this->ChangeStringisNumber(temp);
				//doc tong tien cua bill
				fileInput.getline(temp, 255);
				tien = this->ChangeStringisNumber(temp);
				//tao 1 tempBill
				Bill tempBill(tempBook, soluongSach, tien);
				//add vao danh sach tam thoi
				tempListBill.addBill(tempBill);
		}
		tempListBill.tinhtongtien();
			//add danh sach tam thoi vao danh sach chinh
			this->Listof_ListBill.push_back(tempListBill);
	}
	fileInput.close();
}

void Library::ReadListMailFromFile(string link)
{
	ifstream fileInput(link);
	if (fileInput.fail())
	{
		std::cout << "Failed to open this file!" << endl;
		return;
	}
	string NguoiGui;
	string NguoiNhan;
	string NgayGui;
	string Tieude;
	string Noidung;
	char temp[255];
	while (!fileInput.eof())
	{
		fileInput.getline(temp, 255);
		NguoiGui = temp;
		fileInput.getline(temp, 255);
		NguoiNhan = temp;
		fileInput.getline(temp, 255);
		NgayGui = temp;
		fileInput.getline(temp, 255);
		Tieude = temp;
		fileInput.getline(temp, 255);
		Noidung = temp;
		Mail tempMail(NguoiGui, NguoiNhan, NgayGui, Tieude, Noidung);
		this->List_Mail.push_back(tempMail);
	}
	fileInput.close();
}

void Library::ReadListAuthorFromFile(string link)
{
	ifstream fileInput(link);
	if (fileInput.fail())
	{
		std::cout << "Failed to open this file!" << endl;
		return;
	}
	string username;
	string password;
	string AuthorName;
	char temp[255];
	while (!fileInput.eof())
	{
		fileInput.getline(temp, 255);
		username = temp;
		fileInput.getline(temp, 255);
		password = temp;
		fileInput.getline(temp, 255);
		AuthorName = temp;
		Author tempAuthor(username, password, AuthorName);
		this->List_Author.push_back(tempAuthor);
	}
	fileInput.close();
}

void Library::ReadListNXBFromFile(string link)
{
	ifstream fileInput(link);
	if (fileInput.fail())
	{
		std::cout << "Failed to open this file!" << endl;
		return;
	}
	string username;
	string password;
	string NXBName;
	char temp[255];
	while (!fileInput.eof())
	{
		fileInput.getline(temp, 255);
		username = temp;
		fileInput.getline(temp, 255);
		password = temp;
		fileInput.getline(temp, 255);
		NXBName = temp;
		NXB tempNXB(username, password, NXBName);
		this->List_NXB.push_back(tempNXB);
	}
	fileInput.close();
}

void Library::ReadListHiddenBookFromFile(string link)
{
	ifstream fileInput(link);
	if (fileInput.fail())
	{
		std::cout << "Failed to open this file!" << endl;
		return;
	}

	Hide tempHiddenBook;
	char temp[255];
	int n;
	while (!fileInput.eof())
	{
		//doc admin
		fileInput.getline(temp, 255);
		n = this->ChangeStringisNumber(temp);
		if (n == 0) {
			tempHiddenBook.Admin = false;
		}
		else {
			tempHiddenBook.Admin = true;
		}
		//doc NXB
		fileInput.getline(temp, 255);
		n = this->ChangeStringisNumber(temp);
		if (n == 0) {
			tempHiddenBook.NXB = false;
		}
		else {
			tempHiddenBook.NXB = true;
		}
		//doc Author
		fileInput.getline(temp, 255);
		n = this->ChangeStringisNumber(temp);
		if (n == 0) {
			tempHiddenBook.Author = false;
		}
		else {
			tempHiddenBook.Author = true;
		}
		// gan lai vao cai hiddenbook tam
		this->List_HiddenBook.push_back(tempHiddenBook);
	}
	fileInput.close();
}

void Library::WriteListBookToFile(string link)
{
	fstream outfile;
	outfile.open(link, ios::out);
	int n = this->List_Book.get_soluong();
	for (int i = 0; i < n; i++) {
		Book tempBook;
		tempBook = this->List_Book.GetBookPosition_i(i);
		outfile << tempBook.get_Tensach() << endl;
		outfile << tempBook.get_Masach() << endl;
		outfile << tempBook.get_NXB() << endl;
		outfile << tempBook.get_Author() << endl;
		if (i != n - 1) {
			outfile << tempBook.get_Giatien() << endl;
		}
		else {
			outfile << tempBook.get_Giatien() ;
		}
	}
	outfile.close();
}

void Library::WriteListUserToFile(string link)
{
	fstream outfile;
	outfile.open(link, ios::out);
	int n = this->List_User.size();
	for (int i = 0; i < n; i++) {
		outfile << List_User[i].getName() << endl;
		outfile << List_User[i].getPass() << endl;
		if (i != n - 1) {
			outfile << List_User[i].getTuoi() << endl;
		}
		else {
			outfile << List_User[i].getTuoi();
		}
	}
	outfile.close();
}

void Library::WriteListAdminToFile(string link)
{
	fstream outfile;
	outfile.open(link, ios::out);
	int n = this->List_Admin.size();
	for (int i = 0; i < n; i++) {
		outfile << List_Admin[i].getUsername() << endl;
		if (i != n - 1) {
			outfile << List_Admin[i].getPassword() << endl;
		}
		else {
			outfile << List_Admin[i].getPassword();
		}
	}
	outfile.close();
}

void Library::WriteListBillToFile(string link)
{

	fstream outfile;
	outfile.open(link,ios::out);
	int n = this->Listof_ListBill.size();

	for (int i = 0; i < n; i++) {
		//gan tam listbill
		ListBill tempListBill = this->Listof_ListBill[i];
		//viet so luong bill cua user nao do
		int m = tempListBill.getSoluong();
		//chi viet nhung bill cua user co soluong >0
		if (m != 0) {
			outfile << m << endl;
			//viet username cua bill
			outfile << tempListBill.getUsername() << endl;
			for (int j = 0; j < m; j++) {
				//gan tam bill
				Bill tempBill = tempListBill.getBillPosition_i(j);
				//viet ma sach
				outfile << tempBill.getBook().get_Masach() << endl;
				outfile << tempBill.getSoluong() << endl;
				//TH nam dong cuoi thi ko xuong dong
				if (i == n - 1 && j == m - 1) {
					outfile << tempBill.getTien();
				}
				else {
					outfile << tempBill.getTien() << endl;
				}
			}
		}
	}
	outfile.close();
}

void Library::WriteListMailToFile(string link)
{
	fstream outfile;
	outfile.open(link, ios::out);
	int n = this->List_Mail.size();
	for (int i = 0; i < n; i++) {
		outfile << List_Mail[i].getNguoiGui() << endl;
		outfile << List_Mail[i].GetNguoiNhan() << endl;
		outfile << List_Mail[i].getNgayGui() << endl;
		outfile << List_Mail[i].getTieude() << endl;
		if (i != n - 1) {
			outfile << List_Mail[i].getNoidung() << endl;
		}
		else {
			outfile << List_Mail[i].getNoidung();
		}
	}
	outfile.close();
}

void Library::WriteListAuthorToFile(string link)
{
	fstream outfile;
	outfile.open(link, ios::out);
	int n = this->List_Author.size();
	for (int i = 0; i < n; i++) {
		outfile << List_Author[i].getUsername() << endl;
		outfile << List_Author[i].getPassword() << endl;
		if (i != n - 1) {
			outfile << List_Author[i].getAuthorName() << endl;
		}
		else {
			outfile << List_Author[i].getAuthorName();
		}
	}
	outfile.close();
}

void Library::WriteListNXBToFile(string link)
{
	fstream outfile;
	outfile.open(link, ios::out);
	int n = this->List_NXB.size();
	for (int i = 0; i < n; i++) {
		outfile << List_NXB[i].getUsername() << endl;
		outfile << List_NXB[i].getPassword() << endl;
		if (i != n - 1) {
			outfile << List_NXB[i].getNXBname() << endl;
		}
		else {
			outfile << List_NXB[i].getNXBname();
		}
	}
	outfile.close();
}

void Library::WriteListHiddenBookToFile(string link)
{
	fstream outfile;
	outfile.open(link, ios::out);
	int n = this->List_HiddenBook.size();
	for (int i = 0; i < n; i++) {
		outfile << List_HiddenBook[i].Author << endl;
		outfile << List_HiddenBook[i].NXB << endl;
		if (i != n - 1) {
			outfile << List_HiddenBook[i].Admin << endl;
		}
		else {
			outfile << List_HiddenBook[i].Admin;
		}
	}
	outfile.close();
}

int Library::ChangeStringisNumber(string s)
{
	int kq = 0;
	for (int i = 0; i<s.length(); i++) {
		int k = int(s[i]) - 48;
		kq = kq * 10 + k;
	}
	return kq;
}

Profile Library::findProfile(string username)
{
	Profile tempProfile;
	tempProfile.name = "";
	tempProfile.role = "";
	tempProfile.username = "";
	//check user
	for (int i = 0; i < this->List_User.size(); i++) {
		if (this->List_User[i].getName() == username ) {
			tempProfile.role = "User";
			tempProfile.username = username;
		}
	}
	//check Admin
	for (int i = 0; i < this->List_Admin.size(); i++) {
		if (this->List_Admin[i].getUsername() == username) {
			tempProfile.role = "Admin";
			tempProfile.username = username;
		}
	}
	//check NXB
	for (int i = 0; i < this->List_NXB.size(); i++) {
		if (this->List_NXB[i].getUsername() == username) {
			tempProfile.role = "NXB";
			tempProfile.username = username;
		}
	}
	//check Author
	for (int i = 0; i < this->List_Author.size(); i++) {
		if (this->List_Author[i].getUsername() == username ) {
			tempProfile.role = "Author";
			tempProfile.username = username;
		}
	}
	return tempProfile;
}

void Library::WriteMail()
{
	string NguoiNhan;
	string NgayGui;
	string Tieude;
	string Noidung;
	cout << "Vui long nhap nguoi nhan" << endl;
	cin.ignore();
	getline(cin, NguoiNhan);
	//check nguoi nhan
	while (this->findProfile(NguoiNhan).username != NguoiNhan) {
			cout << "Khong tim thay nguoi nhan trong he thong" << endl;
			cout << "Vui long nhap lai" << endl;
			cin.ignore();
			getline(cin, NguoiNhan);
	}
	cout << "Vui long nhap Tieu de" << endl;
	getline(cin, Tieude);
	cout << "Vui long nhap noi dung" << endl;
	getline(cin, Noidung);
	Mail tempMail(this->USER.username, NguoiNhan, NgayGui, Tieude, Noidung);
	this->List_Mail.push_back(tempMail);
}

int Library::Optional()
{
	int x;
	cout << "Vui long nhap lua chon cua ban " << endl;
	cin >> x;
	return x;
}
