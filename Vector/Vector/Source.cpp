#include<iostream>
#include"Matrix.h"
#include"Vector.h"
using namespace std;

int main()
{
	Matrix A,B, NhanMaTran;
	Vector V, NhanVector;
	cout << "Nhap vao Ma tran A: ";
	cin >> A;

	cout << "\nNhap vao Ma tran B: ";
	cin >> B;
	
	NhanMaTran = A * B;
	cout << "\nNhan hai ma tran A va B: \n";
	cout << NhanMaTran;
	
	cout << "\nNhap vao vector: ";
	cin >> V;

	NhanVector = V * A;
	cout << "\nNhan ma tran A va vector: ";
	cout << NhanVector;
	
	return 0;
}