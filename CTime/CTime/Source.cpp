#include<iostream>
#include"Time.h"
using namespace std;

int main()
{
	int n;
	Time A;
	cin >> A;

	cout << "\nTang thoi gian 1s: " << A++;
	cout << "\nGiam thoi gian 1s: " << A--;
	
	cout << "\nNhap so giay can tang: ";
	cin >> n;
	cout << A + n;

	cout << "\nNhap so giay can giam: ";
	cin >> n;
	cout << A - n;

	return 0;
}