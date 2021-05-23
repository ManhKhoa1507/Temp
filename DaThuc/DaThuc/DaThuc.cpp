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

void DaThuc::Nhap()
{
	cout << "Nhap vao bac cua da thuc: ";
	cin >> n;

	hs = new float[n + 1];
	
	for (int i = 0; i <= n + 1; i++)
	{
		hs[i] = 0;
	}

	for (int i = 0; i <= n; i++)
	{
		cout << endl << "Nhap he so bac " << i << ": ";
		cin >> this->hs[i];
	}
}

void DaThuc::Xuat()
{
	for (int i = n; i >0; i--)
	{
		cout << hs[i] << "*x^" << i<<" ";
		if (hs[i - 1] >= 0) cout << "+";
	}
	cout << hs[0];
	cout << endl;
}

DaThuc DaThuc::Cong(DaThuc a)
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

DaThuc DaThuc::Tru(DaThuc a)
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

float DaThuc::Tinh(int x)
{
	float tam = hs[n];
	for (int i = n; i > 0; i--)
	{
		tam = tam * x + hs[i - 1];
	}
	return tam;
}
