#include<iostream>
#include"PhanSo.h"
#include "DanhSach.h"

using namespace std;

int main()
{
	DanhSach ds;
	
	ds.NhapDanhSach();

	cout << ds.TinhTong();

	ds.XuatDanhSach();

	return 0;
}