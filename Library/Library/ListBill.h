#pragma once
#include"Bill.h"
#include<vector>
class ListBill
{
private:
	vector <Bill> List_Bill;
	string username;
	int tongtien;
public:
	ListBill();
	~ListBill();
	void updateBill_Soluong();
	void addBill(Bill Bill);
	void inputListBill(ListBook& ListBook);
	void outputListBill();
	void tinhtongtien();
	void setUsername(string);
	void deleteBillPosition_I(int i);
	void UpdateAmountBillPosition_I(int i);
	Bill getBillPosition_i(int i);
	int getSoluong();
	string getUsername();
};
void printTableHoaDon(HANDLE hConsoleOutput, COORD arr_cursor_pos[]);
