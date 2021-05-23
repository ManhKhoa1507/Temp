#pragma once
class DaThuc
{
private :
	float* hs;
	int n;

public :
	DaThuc();
	DaThuc(int);
	DaThuc(const DaThuc&);

	void Nhap();
	void Xuat();

	DaThuc Cong(DaThuc);
	DaThuc Tru(DaThuc);

	int FindMax(int a, int b);
	int FindMin(int a, int b);

	float Tinh(int);
};

