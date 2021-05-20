#include "DanhSach.h"
DanhSach::DanhSach()
{
	n = 0;
}

void DanhSach::NhapDanhSach()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ps[i];
	}
}

void DanhSach::XuatDanhSach()
{
	for (int i = 0; i < n; i++)
	{
		cout << ps[i];
	}
}

PhanSo DanhSach::TinhTong()
{
	PhanSo c;
	c.SetTu(ps[0].GetTu());
	c.SetMau(ps[0].GetMau());

	for (int i = 1; i < n; i++)
	{
		int bcln = ps[i].GetMau() * c.GetMau() / c.UCLN(ps[i].GetMau(), c.GetMau());

		c.SetTu((bcln / c.GetMau()*c.GetTu()) + (bcln / ps[i].GetMau())*ps[i].GetTu());
		c.SetMau(bcln);
	}

	return c;
}