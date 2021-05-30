#pragma once
#include<iostream>
using namespace std;

class Date
{
private :
	int ngay;
	int thang;
	int nam;
	int ch;

public :
	Date();
	Date(int, int, int);
	Date(const Date&);


	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, Date);

	Date operator+(int);
	Date operator-(int);
	Date operator++(int);
	Date operator--(int);
	int operator-(Date);

	int rdn(int, int, int);


	int TimNamNhuan(int);
	void TangThang();
	void TangNam();
	void GiamThang();
	void GiamNam();

	void ChuanHoaCong();
	void ChuanHoaTru();
};

