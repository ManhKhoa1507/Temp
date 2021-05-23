#include "DSPhanSo.h"
#include <iostream>
using namespace std;

DSPhanSo::DSPhanSo()
{
	n = 0;
}

DSPhanSo::~DSPhanSo()
{
}

void DSPhanSo::NhapDS()
{
	cout << "Nhap so luong phan so: ";
	while (n <= 0 || n > 100)
	{
		cin >> n;
		if(n <= 0 || n > 100) cout << "Nhap sai. Moi nhap lai: ";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		ps[i].Nhap();
	}
}

void DSPhanSo::XuatDS()
{
	for (int i = 0; i < n; i++)
	{
		ps[i].Xuat();
		cout << " ";
	}
}

PhanSo DSPhanSo::TongPS()
{
	PhanSo c;
	c.SetTu(ps[0].GetTu());
	c.SetMau(ps[0].GetMau());

	for (int i = 1; i < n; i++)
	{
		int bcnn = ps[i].GetMau() * c.GetMau() / c.UCLN(ps[i].GetMau(), c.GetMau());

		c.SetTu((bcnn / c.GetMau() * c.GetTu()) + (bcnn / ps[i].GetMau()) * ps[i].GetTu());
		c.SetMau(bcnn);
	}

	return c;
}

PhanSo DSPhanSo::PSMax()
{
	float max = ps[0].KetQua();
	int index = 0;

	for (int i = 1; i < n; i++)
	{
		float result = ps[i].KetQua();
		if (max < result)
		{
			max = result;
			index = i;
		}
	}
	return ps[index];
}

PhanSo DSPhanSo::PSMin()
{
	float min = ps[0].KetQua();
	int index = 0;

	for (int i = 1; i < n; i++)
	{
		float result = ps[i].KetQua();
		if (min > result)
		{
			min = result;
			index = i;
		}
	}
	return ps[index];
}

void DSPhanSo::DSTangDan()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (ps[i].KetQua() > ps[j].KetQua())
			{
				swap(ps[i], ps[j]);
			}
		}
	}
}

void DSPhanSo::DSGiamDan()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (ps[i].KetQua() < ps[j].KetQua())
			{
				swap(ps[i], ps[j]);
			}
		}
	}
}
