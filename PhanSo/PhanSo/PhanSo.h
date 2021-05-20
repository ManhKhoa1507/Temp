#pragma once
#include<iostream>
using namespace std;

class PhanSo
{
private :
	int tu;
	int mau;

public:
	PhanSo();
	PhanSo(int);
	PhanSo(int, int);

	PhanSo(const PhanSo&);

	int UCLN(int, int);
	float GiaTri();

	PhanSo operator+(const PhanSo&);
	PhanSo operator-(const PhanSo&);
	PhanSo operator*(const PhanSo&);
	PhanSo operator/(const PhanSo&);

	bool operator == (PhanSo&);
	bool operator != (PhanSo&);

	friend  istream& operator >> (istream& is, PhanSo& phanSo);
	friend  ostream& operator << (ostream& os, PhanSo phanSo);

	PhanSo Cong(PhanSo);

	void SetTu(int);
	void SetMau(int);

	int GetTu();
	int GetMau();
};

