#include<iostream>
#include"PhanSo.h"

using namespace std;

int main()
{
	PhanSo a, b, tong, hieu, nhan, chia;
	cin >> a;
	cin >> b;

	tong = a + b;
	cout << tong;

	hieu = a - b;
	cout << hieu;

	nhan = a * b;
	cout << nhan;

	chia = a / b;
	cout << chia;

	if (a == b) cout << 1 << endl;
	else cout << 0 << endl;

	if (a != b) cout << 1 << endl;
	else cout << 0;
}