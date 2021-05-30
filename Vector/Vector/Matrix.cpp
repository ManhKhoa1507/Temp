#include "Matrix.h"

#include <iostream>
#include <iomanip>

using namespace std;

Matrix::Matrix()
{
	m = 0;
	n = 0;
	elements = NULL;
}

Matrix::Matrix(const Matrix& a)
{
	m = a.m;
	n = a.n;
	elements = new double* [m];
	for (int i = 0; i < m; i++)
		elements[i] = new double[n];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			elements[i][j] = a.elements[i][j];
		}
	}
}

istream& operator>>(istream& is, Matrix& M)
{
	cout << "\nNhap m: ";
	is >> M.m;
	cout << "\nNhap n: ";
	is >> M.n;
	M.elements = new double* [M.m];
	for (int i = 0; i < M.m; i++)
		M.elements[i] = new double[M.n];

	for (int i = 0; i < M.m; i++)
	{
		for (int j = 0; j < M.n; j++)
		{
			cout << "Nhap phan tu thu (" << i << ", " << j << "): ";
			is >> M.elements[i][j];
		}
		cout << endl;
	}
	return is;
}

ostream& operator<<(ostream& os, Matrix M)
{
	for (int i = 0; i < M.m; i++)
	{
		for (int j = 0; j < M.m; j++)
			os << setw(10) << M.elements[i][j];

		os << endl;
	}
	return os;
}
Matrix Matrix::operator*(const Matrix& a)
{
	//	Ham nhan 2 ma tran voi nhau
	//	return 0 neu khong nhan duoc
	//	return 1 neu nhan duoc 2 ma tran voi nhau 

	//	Dieu kien nhan ma tra A*B : so cot cua A bang so dong cua B

	if (this->n != a.m)
	{
		cout << "Khong nhan duoc\n";
	}

	//	Tao mot mang 2 chieu NewMatrix 

	double** NewMatrix;
	NewMatrix = new double* [m];

	for (int i = 0; i < m; i++)
	{
		NewMatrix[i] = new double[n];
	}

	//	Nhan 2 Ma tran voi nhau 

	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			NewMatrix[i][j] = 0;
			for (int k = 0; k < this->n; k++)
			{
				NewMatrix[i][j] += this->elements[i][k] * a.elements[k][j];
			}
		}
	}

	//	Xoa Ma tran hien tai trong lop CMatrix

	for (int i = 0; i < m; i++)
	{
		delete[] this->elements[i];
	}

	delete[] elements;

	//	Tao Ma tran moi bang NewMaTrix
	Matrix Result;

	Result.m = a.m;
	Result.n = a.n;
	Result.elements = NewMatrix;

	return Result;
}

int Matrix::GetN()
{
	return n;
}

int Matrix::GetM()
{
	return m;
}

int Matrix::GetElement(int i,int j)
{
	return elements[i][j];
}