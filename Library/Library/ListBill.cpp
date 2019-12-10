#include "ListBill.h"

ListBill::ListBill()
{
	tongtien = 0;
}


void ListBill::inputListBill(ListBook& ListBook)
{
	int soluong;
	cout << "Nhap so luong hoa don ";
	cin >> soluong;
	Bill temp_Hoadon;
	for (int i = 0; i < soluong; i++) {
		cout << "Hoa don thu i " << i + 1 << endl;
		temp_Hoadon.CreateBill(ListBook);
		if (temp_Hoadon.getSoluong() > 0) {
			List_Bill.push_back(temp_Hoadon);
		}
	}
}

void ListBill::outputListBill()
{
	cout << " Danh sach hoa don " << endl;;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD arr_cursor_pos[6];
	printTableHoaDon(hConsoleOutput, arr_cursor_pos);

	tinhtongtien();
	for (int i = 0; i < List_Bill.size(); i++) {
		arr_cursor_pos[0].Y += 1;
		arr_cursor_pos[1].Y += 1;
		arr_cursor_pos[2].Y += 1;
		arr_cursor_pos[3].Y += 1;
		arr_cursor_pos[4].Y += 1;
		arr_cursor_pos[5].Y += 1;
		cout << i + 1;
		List_Bill[i].OutputBill(hConsoleOutput, arr_cursor_pos);
		cout << endl;
	}
	cout << "Tong tien";
	arr_cursor_pos[5].Y += 1;
	SetConsoleCursorPosition(hConsoleOutput, arr_cursor_pos[5]);
	cout << tongtien;
	cout << endl;
}

void ListBill::tinhtongtien()
{
	tongtien = 0;
	for (int i = 0; i < List_Bill.size(); i++) {
		tongtien = tongtien + List_Bill[i].getTien();
	}
	this->tongtien = tongtien;
}

void ListBill::setUsername(string username)
{
	this->username = username;
}

void ListBill::deleteBillPosition_I(int i)
{
	//cout << this->List_Bill.size() << endl;
	this->List_Bill.erase(this->List_Bill.begin() + i);
}

void ListBill::UpdateAmountBillPosition_I(int i)
{
	this->List_Bill[i].changeSoluong();
}

Bill ListBill::getBillPosition_i(int i)
{
	return this->List_Bill[i];
}

int ListBill::getSoluong()
{
	return this->List_Bill.size();
}

string ListBill::getUsername()
{
	return this->username;
}

ListBill::~ListBill()
{
}

void ListBill::updateBill_Soluong()
{
	int n;
	system("cls");
	this->outputListBill();
	if (List_Bill.size() == 0) {
		cout << "!!!ko co bill nao de thay doi";
		return;
	}
	cout << "Nhap STT bill muon thay doi : ";
	cin >> n;
	n = n - 1;
	this->List_Bill[n].changeSoluong();
}

void ListBill::addBill(Bill Bill)
{
	this->List_Bill.push_back(Bill);
}

void printTableHoaDon(HANDLE hConsoleOutput, COORD arr_cursor_pos[])
{
	COORD cursor_pos = GetConsoleCursorPosition();
	arr_cursor_pos[0] = cursor_pos;
	cout << "STT";
	cursor_pos.X += 5;
	arr_cursor_pos[1] = cursor_pos;
	SetConsoleCursorPosition(hConsoleOutput, cursor_pos);
	cout << "Ten sach";
	cursor_pos = GetConsoleCursorPosition();
	cursor_pos.X += 5;
	arr_cursor_pos[2] = cursor_pos;
	SetConsoleCursorPosition(hConsoleOutput, cursor_pos);
	cout << "Ma sach";
	cursor_pos = GetConsoleCursorPosition();
	cursor_pos.X += 5;
	arr_cursor_pos[3] = cursor_pos;
	SetConsoleCursorPosition(hConsoleOutput, cursor_pos);
	cout << "So luong";
	cursor_pos = GetConsoleCursorPosition();
	cursor_pos.X += 5;
	arr_cursor_pos[4] = cursor_pos;
	SetConsoleCursorPosition(hConsoleOutput, cursor_pos);
	cout << "Don gia";
	cursor_pos = GetConsoleCursorPosition();
	cursor_pos.X += 5;
	arr_cursor_pos[5] = cursor_pos;
	SetConsoleCursorPosition(hConsoleOutput, cursor_pos);
	cout << "Gia" << endl;
}
