#pragma once
#include<iostream>
#include"PhanSo.h"
using namespace std;

class DanhSach
{
private :
	int n;
	PhanSo ps[100];

public :
	DanhSach();

	void NhapDanhSach();
	void XuatDanhSach();

	PhanSo TinhTong();
};

