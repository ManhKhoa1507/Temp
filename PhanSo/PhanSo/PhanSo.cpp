#include "PhanSo.h"
#include <iostream>
using namespace std;

void PhanSo::SetPhanSo(int tu, int mau)
{
	this->tu = tu;
	this->mau = mau;
}

void PhanSo::SetTu(int tu)
{
	this->tu = tu;
}

void PhanSo::SetMau(int mau)
{
	this->mau = mau;
}

PhanSo::PhanSo()
{
	SetPhanSo(0, 1);
}

PhanSo::PhanSo(int tu)
{
	SetPhanSo(tu, 1);
}

PhanSo::PhanSo(int tu, int mau)
{
	SetPhanSo(tu, mau);
}

int PhanSo::GetTu()
{
	return tu;
}

int PhanSo::GetMau()
{
	return mau;
}

void PhanSo::Nhap()
{
	cout << "Nhap tu so: ";
	cin >> tu;

	cout << "Nhap mau so: ";
	cin >> mau;
	cout << endl;
}

void PhanSo::Xuat()
{
	cout << tu << "/" << mau;
}

int PhanSo::UCLN(int tu, int mau)
{
	int r;
	while (tu % mau != 0)
	{
		r = tu % mau;
		tu = mau;
		mau = r;
	}
	return mau;
}

void PhanSo::RutGon()
{
	float temp = UCLN(tu, mau);
	return SetPhanSo(tu / temp, mau / temp);
}

void PhanSo::ChuanHoa()
{
	if (tu < 0 && mau < 0)
	{
		SetPhanSo(abs(tu), abs(mau));
	}

	if (tu > 0 && mau < 0)
	{
		SetPhanSo(-tu, abs(mau));
	}
}

float PhanSo::KetQua()
{
	return (float)GetTu() / GetMau();
}