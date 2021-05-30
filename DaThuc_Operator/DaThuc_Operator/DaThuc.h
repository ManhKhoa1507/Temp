#pragma once
#include<iostream>
using namespace std;

class DaThuc
{
private:
	float* hs;
	int n;

public:
	DaThuc();
	DaThuc(int);
	DaThuc(const DaThuc&);

	friend istream& operator>>(istream& is, DaThuc &dt);
	friend ostream& operator<<(ostream& os, DaThuc dt);

	DaThuc operator+(DaThuc);
	DaThuc operator-(DaThuc);

	int FindMax(int a, int b);
	int FindMin(int a, int b);

};