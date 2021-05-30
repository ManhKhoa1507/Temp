#include<iostream>
#include"DaThuc.h"
using namespace std;

int main()
{
	DaThuc a, b;

	cin >> a;
	
	cout << "\nNhap da thuc thu hai : ";
	cin >> b;

	cout << "\nCong 2 da thuc: ";
	cout << a + b;

	cout << "\nTru 2 da thuc: ";
	cout << a - b;

	return 0;
}