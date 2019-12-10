#ifndef _FILE_H_
#define _FILE_H_
#include <fstream>
#include "HoaDon.h"
#include "ADMIN.h"

void ReadListSach(string filein, list<Sach> &listsach);
void WriteListSach(string fileout, list<Sach> &listsach, Sach x);
void WriteDeletedListSach(string fileout, list<Sach> listsach);
void ReadListHoaDon(string filein, list<HoaDon> &listhoadon);
void WriteListHoaDon(string fileout, list<HoaDon> listhoadon);
void WriteUpdatedListHoaDon(string fileout, list<HoaDon> listhoadon);
void ReadListUser(string filein, list<Khach*> &member);
void WriteListUser(string fileout, Khach* temp);

#endif

