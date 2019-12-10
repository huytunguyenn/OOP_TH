#include "File.h"


void ReadListSach(string filein, list<Sach> &listsach) {
	fstream fin(filein, ios_base::in);
	if (fin.fail()) {
		return;
	}
	else {
		Sach temp;
		string tempgia;
		while (fin) {
			getline(fin, temp.TEN);
			getline(fin, temp.MA);
			getline(fin, temp.TACGIA);
			getline(fin, temp.NXB);
			getline(fin, tempgia);
			temp.GIA = stoi(tempgia);
			listsach.push_back(temp);
		}
	}
	fin.close();
}
void WriteListSach(string fileout, list<Sach> &listsach, Sach x) {
	fstream fout(fileout, ios_base::app);
	listsach.push_back(x);
	fout << x.TEN << endl;
	fout << x.MA << endl;
	fout << x.TACGIA << endl;
	fout << x.NXB << endl;
	fout << x.GIA << endl;
	fout.close();
}
void WriteDeletedListSach(string fileout, list<Sach> listsach) {
	fstream fout(fileout, ios_base::out);
	if (fout.fail()) {
		return;
	}
	else {
		list<Sach>::iterator it;
		for (it = listsach.begin(); it != listsach.end(); it++) {
			fout << it->TEN << endl;
			fout << it->MA << endl;
			fout << it->TACGIA << endl;
			fout << it->NXB << endl;
			fout << it->GIA << endl;
		}
	}
	fout.close();
}
void ReadListHoaDon(string filein, list<HoaDon> &listhoadon) {
	fstream fin(filein, ios_base::in);
	if (fin.fail()) {
		return;
	}
	else {
		HoaDon temp;
		string tempgia, temptien, tempsl;
		while (fin) {
			getline(fin, temp.s.TEN);
			getline(fin, temp.s.MA);
			getline(fin, temp.s.TACGIA);
			getline(fin, temp.s.NXB);
			getline(fin, tempgia);
			temp.s.GIA = stoi(tempgia);
			getline(fin, temptien);
			temp.Tien = stoi(temptien);
			getline(fin, tempsl);
			temp.Soluong = stoi(tempsl);
			listhoadon.push_back(temp);
		}
	}
	fin.close();
}
void WriteListHoaDon(string fileout, list<HoaDon> listhoadon) {
	fstream fout(fileout, ios_base::app);
	if (fout.fail()) {
		return;
	}
	else {
		list<HoaDon>::iterator it;
		for (it = listhoadon.begin(); it != listhoadon.end(); it++) {
			fout << it->s.TEN << endl;
			fout << it->s.MA << endl;
			fout << it->s.TACGIA << endl;
			fout << it->s.NXB << endl;
			fout << it->s.GIA << endl;
			fout << it->Tien << endl;
			fout << it->Soluong << endl;
		}
	}
	fout.close();
}
void WriteUpdatedListHoaDon(string fileout, list<HoaDon> listhoadon) {
	fstream fout(fileout, ios_base::out);
	if (fout.fail()) {
		return;
	}
	else {
		list<HoaDon>::iterator it;
		for (it = listhoadon.begin(); it != listhoadon.end(); it++) {
			fout << it->s.TEN << endl;
			fout << it->s.MA << endl;
			fout << it->s.TACGIA << endl;
			fout << it->s.NXB << endl;
			fout << it->s.GIA << endl;
			fout << it->Tien << endl;
			fout << it->Soluong << endl;
		}
	}
	fout.close();
}
void ReadListUser(string filein, list<Khach*> &member) {
	fstream fin(filein, ios_base::in);
	if (fin.fail()) {
		return;
	}
	else {
		string type, ten, pass, temptuoi;
		int tuoi;
		while (fin) {
			getline(fin, type);
			if (type == "NXB") {
				getline(fin, ten);
				getline(fin, pass);
				Khach* temp = new NXB(ten, pass);
				member.push_back(temp);
			}
			else if (type == "TacGia") {
				getline(fin, ten);
				getline(fin, pass);
				Khach* temp = new TacGia(ten, pass);
				member.push_back(temp);
			}
			else if (type == "User") {
				getline(fin, ten);
				getline(fin, pass);
				getline(fin, temptuoi);
				tuoi = stoi(temptuoi);
				Khach* temp = new User(ten, pass, tuoi);
				member.push_back(temp);
			}
		}
	}
	fin.close();
}
void WriteListUser(string fileout, Khach* temp) {
	fstream fout(fileout, ios_base::app);
	if (fout.fail()) {
		return;
	}
	else {
		if (temp->ClassName() == "NXB") {
			fout << "NXB" << endl;
			fout << temp->ten << endl;
			fout << temp->pass << endl;
		}
		else if (temp->ClassName() == "TacGia") {
			fout << "TacGia" << endl;
			fout << temp->ten << endl;
			fout << temp->pass << endl;
		}
		else if (temp->ClassName() == "User") {
			fout << "User" << endl;
			fout << temp->ten << endl;
			fout << temp->pass << endl;
			fout << temp->age << endl;
		}
	}
	fout.close();
}