#include "ListBook.h"
#include"Book.h"




ListBook::ListBook()
{
}





Book ListBook::GetBookPosition_i(int i)
{
	return this->List_Book[i];
}

int ListBook::findBookbyName(string BookName)
{
	int count = 0;
	int vitri;
	for (int i = 0; i < List_Book.size(); i++) {
		if (List_Book[i].get_Tensach() == BookName) {
			count++;
			vitri = i;
		}
	}
	if (count == 1) {
		return vitri;
	}
	//TH ko tim thay quyen nao
	if (count == 0) {
		return -1;
	}
	//TH tim thay nhieu hon 1 quyen
	if (count > 1) {
		return -2;
	}
}



Book ListBook::addBooktoBill()
{
	string tensach, masach;
	Book temp_Book;
	int Vitri;
	cout << "Nhap ten sach" << endl;
	cin >> tensach;
	Vitri = findBookbyName(tensach);
	//th ko tim thay
	if (Vitri ==-1) {
		cout << "ko tim thay ten sach" << endl;
		temp_Book.set_Tensach("");
		temp_Book.set_Masach("");
		temp_Book.set_Giatien(0);
		return temp_Book;
	}
	//TH tim thay 1 quyen
	if (Vitri != -1 && Vitri != -2) {
		temp_Book = List_Book[Vitri];
		return temp_Book;
	}
	//th tim thay 2 quyen
	if (Vitri == -2) {
		cout << "Vui long nhap ma sach" << endl;;
		cin >> masach;
		//tim bang ma sach
		Vitri = this->findBookbyMasach(masach);
		if (Vitri != -1) {
			temp_Book = List_Book[findBookbyMasach(masach)];
			return temp_Book;
		}
		//ko tim thay bang ma sach
		else {
			temp_Book.set_Tensach("");
			temp_Book.set_Masach("");
			temp_Book.set_Giatien(0);
			return temp_Book;
		}
	}
}
void ListBook::deleteBook(int Vitri)
{
	List_Book.erase(List_Book.begin() + Vitri);
}
void ListBook::updatePrice(int Vitri)
{
	int giatien;
	cout << "nhap gia tien muon thay doi";
	cin >> giatien;
	List_Book[Vitri].set_Giatien(giatien);
}
void ListBook::inputList()
{
	int soluong;
	cout << "Nhap so luong sach muon nhap ";
	cin >> soluong;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD arr_cursor_pos[6];
	printTable(hConsoleOutput, arr_cursor_pos);
	for (int i = 0; i < soluong; i++)
	{
		arr_cursor_pos[0].Y += 1;
		arr_cursor_pos[1].Y += 1;
		arr_cursor_pos[2].Y += 1;
		arr_cursor_pos[3].Y += 1;
		arr_cursor_pos[4].Y += 1;
		arr_cursor_pos[5].Y += 1;
		cout << i + 1;
		Book tempSach;
		tempSach.input_sach(hConsoleOutput, arr_cursor_pos);
		List_Book.push_back(tempSach);
	}
}
void ListBook::outputList()
{
	cout << "Danh sach Sach" << endl;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD arr_cursor_pos[6];
	printTable(hConsoleOutput, arr_cursor_pos);
	for (int i = 0; i < List_Book.size(); i++)
	{
		arr_cursor_pos[0].Y += 1;
		arr_cursor_pos[1].Y += 1;
		arr_cursor_pos[2].Y += 1;
		arr_cursor_pos[3].Y += 1;
		arr_cursor_pos[4].Y += 1;
		arr_cursor_pos[5].Y += 1;
		cout << i + 1;
		List_Book[i].output_sach(hConsoleOutput, arr_cursor_pos);
		cout << endl;
	}
}

int ListBook::get_soluong()
{
	return List_Book.size();
}

int ListBook::Optional()
{
	int Optional;
	cout << "1-Xoa" << endl;
	cout << "2-Cap nhap gia" << endl;
	cin >> Optional;
	return Optional;
}

void ListBook::findFunction()
{
	string tensach, masach;
	int Vitri;
	cout << "Nhap ten sach" << endl;
	cin >> tensach;
	Vitri = findBookbyName(tensach);
	//TH ko tim thay
	if (Vitri == -1) {
		cout << "ko tim thay" << endl;;
	}
	//TH tim nhieu hon 1 quyen
	if (Vitri == -2) {
		cout << "Vui long nhap ma sach" << endl;;
		cin >> masach;
		//Tim by ma sach
		Vitri = this->findBookbyMasach(masach);
		if (Vitri != -1) {
			this->List_Book[Vitri].outputSach();
		}
		else {
			cout << "ko tim thay" << endl;;
		}

	}
	//TH tim thay 1 quyen
	if (Vitri != -1 && Vitri!=-2) {
		this->List_Book[Vitri].outputSach();
	}
}

int ListBook::findFuntionReturnVitri()
{
	string tensach, masach;
	int Vitri;
	cout << "Nhap ten sach" << endl;
	cin >> tensach;
	Vitri = findBookbyName(tensach);
	//TH ko tim thay
	if (Vitri == -1) {
		//cout << "ko tim thay" << endl;
		return -1;
	}
	//TH tim nhieu hon 1 quyen
	if (Vitri == -2) {
		cout << "Vui long nhap ma sach" << endl;;
		cin >> masach;
		//Tim by ma sach
		Vitri = this->findBookbyMasach(masach);
		if (Vitri != -1) {
			return Vitri;
		}
		else {
			return -1;
		}

	}
	//TH tim thay 1 quyen bang ten sach
	if (Vitri != -1 && Vitri != -2) {
		return Vitri;
	}
}

void ListBook::pushBack(Book s)
{
	this->List_Book.push_back(s);
}

int ListBook::findBookbyMasach(string Masach)
{
	for (int i = 0; i < List_Book.size(); i++) {
		if (List_Book[i].get_Masach() == Masach) {
			return i;
		}
	}
	return -1;
}
void printTable(HANDLE hConsoleOutput, COORD arr_cursor_pos[])
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
	cout << "Gia" ;

	cursor_pos = GetConsoleCursorPosition();
	cursor_pos.X += 5;
	arr_cursor_pos[4] = cursor_pos;
	SetConsoleCursorPosition(hConsoleOutput, cursor_pos);
	cout << "Tac Gia" ;

	cursor_pos = GetConsoleCursorPosition();
	cursor_pos.X += 10;
	arr_cursor_pos[5] = cursor_pos;
	SetConsoleCursorPosition(hConsoleOutput, cursor_pos);
	cout << "NXB" << endl;
}





