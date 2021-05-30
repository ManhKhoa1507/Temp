#pragma once
#include<iostream>

using namespace std;

class Vector;

class Matrix
{
private:
	int m; // dòng
	int n; // cột
	double** elements;
public:
	Matrix();

	Matrix(const Matrix& a);

	friend istream& operator>>(istream& is, Matrix& M);
	friend ostream& operator<<(ostream& os, Matrix M);

	Matrix operator*(const Matrix& a);
	//friend Vector operator*(const Matrix& a, const Vector& b);
	int GetM();
	int GetN();
	int GetElement(int, int);
};
