#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector()
{
	n = 0;
	coords = NULL;
}

Vector::Vector(int N, double x)
{
	n = N;
	coords = new double[n];
	for (int i = 0; i < n; i++)
	{
		coords[i] = x;
	}
}

Vector::Vector(const Vector& a)
{
	n = a.n;
	coords = new double[n];
	for (int i = 0; i < n; i++)
	{
		coords[i] = a.coords[i];
	}
}

istream& operator>>(istream& is, Vector& V)
{
	cout << "Nhap n: ";
	is >> V.n;
	V.coords = new double[V.n];
	for (int i = 0; i < V.n; i++)
	{
		cout << "Nhap phan tu thu " << i << ": ";
		is >> V.coords[i];
	}
	return is;
}


ostream& operator<<(ostream& os, Vector M)
{
	os << "(";
	for (int i = 0; i < M.n; i++)
	{
		os << M.coords[i];
		if (i != M.n - 1)
			os << ", ";
	}
	os << ")";
	return os;
}


Vector Vector::operator*(Matrix a)
{
	if (a.GetN() != n)
		return Vector();

	Vector mul(a.GetM(), n);

	for (int i = 0; i < a.GetM(); i++)
	{
		double elm = 0;
		for (int j = 0; j < a.GetN(); j++)
		{
			elm += a.GetElement(i,j) * coords[j];
		}
		mul.coords[i] = elm;
	}

	return mul;
}