#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <string>
using namespace std;

class CvatNuoi {
private:
	float CAN;
	string TINHtrang; 
public:
	string MAso;
	string LOAI;
	CvatNuoi()
	{
		this->CAN = 0;
	}
	float getCAN();
	string getTINHtrang();
	void setCAN(float);
	void setTINHtrang(string);
	friend ostream& operator<<(ostream&, CvatNuoi);
	friend istream& operator>>(istream&, CvatNuoi&);
	friend class List;
};


class Node{
	CvatNuoi data;
	struct Node* pNext;
	friend class List;
};
class List {
	Node *pHead;
	Node *pTail;
	int n;
public:
	List()
	{
		pHead = pTail = NULL;
		n = 0;
	}
	void Init(List& l);
	Node* getNode(CvatNuoi);
	void AddHead(List& , Node*);
	void AddTail(List&, Node*);
	void Input(List& ,int );
	void Output(List);
	void DelHead();
	void DelTail();
	void DelNode(int);
	int SearchMAso(string);
	void DelByMAso(string);
	void OutputLOAI(string);
	void DatHang(string,float);
};

#endif
