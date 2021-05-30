#pragma once
#include<iostream>
#include"Matrix.h"
using namespace std;
class Matrix;

class Vector
{
private:
	double* coords;
	int n;

public:
	Vector();
	Vector(int N, double x); 
	Vector(const Vector& a);

	friend istream& operator>>(istream& is, Vector& M);
	friend ostream& operator<<(ostream& os, Vector M);

	Vector operator*(Matrix a);
};

