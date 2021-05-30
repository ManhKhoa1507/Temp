#include"Date.h"
#include<iostream>
using namespace std;

int main()
{
	Date a,b;
	cin >> a;
	
	int n;

	cout << "\nTang thoi gian them 1 ngay: " << a++;
	cout << "\nGiam thoi gian 1 ngay: " << a--;

	cout << "\nNhap vao so ngay(it hon 31 ngay): ";
	cin >> n;
	cout << "\nNgay thang nam sau khi tang : " << a + n;

	cout << "\nNhap vao so ngay (it hon 31 ngay): ";
	cin >> n;
	cout << "\n Ngay thang nam sau khi giam:" << a - n;

	cin >> b;
	cout << "\nNgay thu nhat cach ngay thu hai so ngay: " << a - b;
}