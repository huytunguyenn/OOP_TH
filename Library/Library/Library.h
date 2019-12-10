#pragma once
#include"ListBook.h"
#include"Menu.h"
#include"Admin.h"
#include"User.h"
#include <fstream>
#include"NXB.h"
#include"Author.h"
#include"Mail.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Profile {
	string username;
	string role;
	string name;
};
class Library
{
	ListBook List_Book;
	Menu Menu;
	Profile USER;
	vector<ListBill> Listof_ListBill;
	vector<Admin> List_Admin;
	vector<NXB>List_NXB;
	vector<Author>List_Author;
	vector<user> List_User;
	vector<Hide> List_HiddenBook;
	vector<Mail>List_Mail;
public:
	Library();
	~Library();
	void run();
	void Login();
	void MailBox();
	//tim sach
	void Findbook();
	//khoa sach
	void Lockbook();
	void RegisterUser();
	// function of Guest,user,Nxb
	void GuestFunction();
	void NXBFunction();
	void AuthorFunction();
	void UserFunction();
	void AdminFunction();
	string InputPassword();
	void addHiddenBook();
	//readFromFile
	void ReadListBookFromFile(string link);
	void ReadListUserFromFile(string link);
	void ReadListAdminFromFile(string link);
	void ReadListBillFromFile(string link);
	void ReadListMailFromFile(string link);
	void ReadListAuthorFromFile(string link);
	void ReadListNXBFromFile(string link);
	void ReadListHiddenBookFromFile(string link);
	//writeToFile
	void WriteListBookToFile(string link);
	void WriteListUserToFile(string link);
	void WriteListAdminToFile(string link);
	void WriteListBillToFile(string link);
	void WriteListMailToFile(string link);
	void WriteListAuthorToFile(string link);
	void WriteListNXBToFile(string link);
	void WriteListHiddenBookToFile(string link);

	int ChangeStringisNumber(string);
	Profile findProfile(string username);
	void WriteMail();
	int Optional();
};

