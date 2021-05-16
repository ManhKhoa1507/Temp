#pragma once
#include<iostream>
using namespace std;

class SoPhuc
{
private :
	int thuc;
	int ao;

public :
	SoPhuc();
	SoPhuc(int);
	SoPhuc(int, int);

	SoPhuc(const SoPhuc&);

	float DoDai();
	
	SoPhuc operator+(const SoPhuc&);
	SoPhuc operator-(const SoPhuc&);
	SoPhuc operator*(const SoPhuc&);
	SoPhuc operator/(const SoPhuc&);

	bool operator == (SoPhuc&);
	bool operator != (SoPhuc&);

	friend  istream& operator >> (istream& is, SoPhuc& soPhuc);
	friend  ostream& operator << (ostream& is, SoPhuc& soPhuc);
};

