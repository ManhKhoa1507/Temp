#include "SoPhuc.h"
SoPhuc::SoPhuc()
{
	thuc = 0;
	ao = 0;
}

SoPhuc::SoPhuc(int thuc)
{
	this->thuc = thuc;
}

SoPhuc::SoPhuc(int  thuc, int ao)
{
	this->thuc = thuc;
	this->ao = ao;
}

SoPhuc::SoPhuc(const SoPhuc &soPhuc)
{
	this->thuc = soPhuc.thuc;
	this->ao = soPhuc.ao;
}

float SoPhuc::DoDai()
{
	// Ham tinh do dai cua so phuc
	return sqrt(this->thuc + this->ao);
}

SoPhuc SoPhuc::operator+(const SoPhuc& a)
{
	// Cong hai so phuc 
	SoPhuc ketQua;
	ketQua.thuc = a.thuc + this->thuc;
	ketQua.ao = a.ao + this->ao;

	return ketQua;
}

SoPhuc SoPhuc::operator-(const SoPhuc& a)
{
	// Tru hai so phuc
	SoPhuc ketQua;
	ketQua.thuc = a.thuc - this->thuc;
	ketQua.ao = a.ao - this->ao;

	return ketQua;
}

SoPhuc SoPhuc :: operator*(const SoPhuc& a)
{
	// Nhan hai so phuc 
	SoPhuc ketQua;

	ketQua.thuc = (this->thuc * a.thuc - a.ao * this->ao);
	ketQua.ao = (this->thuc * a.thuc + a.ao * this->ao);
	
	return ketQua;
}

SoPhuc SoPhuc :: operator/(const SoPhuc& a)
{
	// Chia 2 so phuc
	SoPhuc ketQua;

	ketQua.thuc = (this->thuc * a.thuc + this->ao + a.ao) / (a.thuc * a.thuc + a.ao * a.ao);
	ketQua.ao = (a.thuc * this->ao - this->thuc * a.ao) / (a.thuc * a.thuc + a.ao * a.ao);

	return ketQua;
}

bool SoPhuc::operator==(SoPhuc& a)
{
	// Kiem tra 2 so phuc bang nhau 
	if (DoDai() == a.DoDai()) return 1;
	else return 0;
}

bool SoPhuc::operator!=(SoPhuc& a)
{
	// Kiem tra 2 so phuc khac nhau
	if (DoDai() != a.DoDai()) return 1;
	else return 0;
}

istream& operator >> (istream& is,SoPhuc& soPhuc)
{
	// Nhap so phuc
	cout << "\nthuc: ";
	is >> soPhuc.thuc;
	cout << "\nao: ";
	is >> soPhuc.ao;
	cout << endl;

	return is;
}

ostream& operator << (ostream& os, SoPhuc& soPhuc)
{
	// Xuat so phuc 
	os << soPhuc.thuc << " " << soPhuc.ao << endl;
	return os;
}
