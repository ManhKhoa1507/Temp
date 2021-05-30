#include "DaThuc.h"
#include<iostream>
using namespace std;

DaThuc::DaThuc()
{
	hs = NULL;
	n = -1;
}

DaThuc::DaThuc(int n)
{
	this->n = n;
	hs = new float[n + 1];

	for (int i = 0; i <= n + 1; i++)
	{
		hs[i] = 0;
	}
}

DaThuc::DaThuc(const DaThuc& a)
{
	this->n = a.n;
	hs = new float[n + 1];

	for (int i = 0; i <= n; i++)
	{
		hs[i] = a.hs[i];
	}
}

int DaThuc::FindMax(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int DaThuc::FindMin(int a, int b)
{
	if (a < b) return a;
	else return b;
}

istream& operator>>(istream &is, DaThuc &dt)
{
	cout << "Nhap vao bac cua da thuc: ";
	is >> dt.n;

	dt.hs = new float[dt.n + 1];

	for (int i = 0; i <= dt.n + 1; i++)
	{
		dt.hs[i] = 0;
	}

	for (int i = 0; i <= dt.n; i++)
	{
		cout << endl << "Nhap he so bac " << i << ": ";
		is >> dt.hs[i];
	}
	return is;
}

ostream& operator<<(ostream&os, DaThuc dt)
{
	for (int i = dt.n; i > 0; i--)
	{
		os << dt.hs[i] << "*x^" << i << " ";
		if (dt.hs[i - 1] >= 0) os << "+";
	}
	os << dt.hs[0] << endl;
	return os;
}

DaThuc DaThuc::operator+(DaThuc a)
{
	int max, min;

	max = FindMax(n, a.n);
	min = FindMin(n, a.n);

	DaThuc ketQua(max);

	for (int i = 0; i <= min; i++)
	{
		ketQua.hs[i] = hs[i] + a.hs[i];
	}

	if (max == n)
	{
		for (int i = min + 1; i <= max; i++)
		{
			ketQua.hs[i] = hs[i];
		}
	}

	else
	{
		for (int i = min + 1; i <= max; i++)
		{
			ketQua.hs[i] = a.hs[i];
		}
	}
	return ketQua;
}

DaThuc DaThuc::operator-(DaThuc a)
{
	int max, min;

	max = FindMax(n, a.n);
	min = FindMin(n, a.n);

	DaThuc ketQua(max);

	for (int i = 0; i <= min; i++)
	{
		ketQua.hs[i] = hs[i] - a.hs[i];
	}

	if (max == n)
	{
		for (int i = min + 1; i <= max; i++)
		{
			ketQua.hs[i] = hs[i];
		}
	}

	else
	{
		for (int i = min + 1; i <= max; i++)
		{
			ketQua.hs[i] = a.hs[i];
		}
	}
	return ketQua;
}
