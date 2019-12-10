#pragma once
#include <string>
#include<iostream>
#include <Windows.h>
using namespace std;
class Book
{
private:
	string Tensach;
	string Masach;
	string NXB;
	string Author;
	int Giatien;
public:
	Book(string Tensach, string Masach, int Giatien);
	Book(const Book&);
	Book();
	void set(Book a);
	void set_Tensach(string s);
	void set_Masach(string s);
	void set_Giatien(int n);
	void set_NXB(string s);
	void set_Author(string s);
	void input_sach(HANDLE, COORD arr[]);
	void output_sach(HANDLE, COORD arr[]);
	void outputSach();
	string get_Tensach();
	string get_Masach();
	string get_Author();
	int get_Giatien();
	string get_NXB();
};

COORD GetConsoleCursorPosition();