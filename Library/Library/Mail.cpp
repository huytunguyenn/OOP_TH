#include "Mail.h"

Mail::Mail(string NguoiGui, string NguoiNhan, string NgayGui, string Tieude,string Noidung)
{
	this->NguoiGui= NguoiGui;
	this->NguoiNhan = NguoiNhan;
	this->NgayGui = "22/02/2019";
	this->Noidung = Noidung;
	this->Tieude = Tieude;
}

void Mail::ReadMail()
{
	cout << endl;
	cout << "+++++++++++++++++++++++++++" << endl;
	cout << "Nguoi Gui : " << this->NguoiGui << endl;
	cout << "Ngay Gui : " << this->NgayGui << endl;
	cout << "Tieu de : " << this->Tieude << endl;
	cout << "Noi dung : " << this->Noidung << endl;
	cout << "+++++++++++++++++++++++++++" << endl;
	cout << endl;
}

string Mail::GetNguoiNhan()
{
	return this->NguoiNhan;
}

string Mail::getNguoiGui()
{
	return this->NguoiGui;
}

string Mail::getNgayGui()
{
	return this->NgayGui;
}

string Mail::getTieude()
{
	return this->Tieude;
}

string Mail::getNoidung()
{
	return this->Noidung;
}


