#include "PhanSo.h"
PhanSo::PhanSo()
{
	tu = 0;
	mau = 0;
}

int PhanSo::UCLN(int a, int b)
{
	int tmp;
	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

float PhanSo::GiaTri()
{
	return tu / mau;
}

PhanSo::PhanSo(int tu)
{
	this->tu = tu;
}

PhanSo::PhanSo(int tu, int mau)
{
	this->tu = tu;
	this->mau = mau;
}

PhanSo::PhanSo(PhanSo const& phanSo)
{
	this->tu = phanSo.tu;
	this->mau = phanSo.mau;
}

PhanSo PhanSo::operator+(const PhanSo& a)
{
	PhanSo c;
	c.mau = (a.mau * this->mau) / this->UCLN(a.mau, this->mau);
	c.tu = (c.mau / a.tu) + (c.mau / this->tu);
	return c;
}

PhanSo PhanSo::operator-(const PhanSo& a)
{
	PhanSo c;
	c.mau = (a.mau * this->mau) / this->UCLN(a.mau, this->mau);
	c.tu = (c.mau / a.tu) - (c.mau / this->tu);
	return c;
}

PhanSo PhanSo::operator*(const PhanSo& a)
{
	PhanSo c;
	c.tu = a.tu * this->tu;
	c.mau = a.mau * this->mau;
	return c;
}

PhanSo PhanSo :: operator/(const PhanSo& a)
{
	PhanSo c;
	c.tu = a.tu * this->mau;
	c.mau = a.mau * this->tu;
	return c;
}

istream& operator>>(istream& is, PhanSo& a)
{
	cout << "\ntu : ";
	is >> a.tu;
	cout << "\nmau: ";
	is >> a.mau;
	return is;
}

ostream& operator <<(ostream& os, PhanSo a)
{
	os << endl << a.tu << " / " << a.mau << endl;
	return os;
}

bool PhanSo::operator==(PhanSo& a)
{
	if (this->GiaTri() == a.GiaTri()) return 1;
	else return 0;
}

bool PhanSo::operator!=(PhanSo& a)
{
	if (this->GiaTri() != a.GiaTri()) return 1;
	else return 0;
}

PhanSo PhanSo::Cong(PhanSo a)
{
	PhanSo c;
	c.mau = (a.mau * this->mau) / this->UCLN(a.mau, this->mau);
	c.tu = (c.mau / a.tu) + (c.mau / this->tu);
	return c;
}

void PhanSo::SetTu(int tu)
{
	this->tu = tu;
}

void PhanSo::SetMau(int mau)
{
	this->mau = mau;
}

int PhanSo::GetTu()
{
	return this->tu;
}

int PhanSo::GetMau()
{
	return this->mau;
}