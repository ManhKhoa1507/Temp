#include"DaThuc.h"
#include<iostream>
using namespace std;

int main()
{
	DaThuc a, b, cong, tru;
	
	a.Nhap();
	a.Xuat();
	
	b.Nhap();
	b.Xuat();

	cong = a.Cong(b);
	cong.Xuat();

	tru = a.Tru(b);
	tru.Xuat();

	int ketQua,x;
	cout << endl << "Nhap vao gia tri x: ";
	cin >> x;
	ketQua = a.Tinh(x);
	cout << ketQua;
}