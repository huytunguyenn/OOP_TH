#pragma once
#include<iostream>
using namespace std;
class Mail
{

	string NguoiGui;
	string NguoiNhan;
	string NgayGui;
	string Tieude;
	string Noidung;
public:
	Mail(string, string, string, string,string);
	void ReadMail();
	string GetNguoiNhan();
	string getNguoiGui();
	string getNgayGui();
	string getTieude();
	string getNoidung();
};

