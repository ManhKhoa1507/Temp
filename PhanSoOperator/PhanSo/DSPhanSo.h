#pragma once
#include "PhanSo.h"
class DSPhanSo
{
private:
	int n;
	PhanSo ps[100];
public:
	// Constructor
	DSPhanSo();
	// Destructor
	~DSPhanSo();

	void NhapDS();
	void XuatDS();

	// Ham xu li
	PhanSo TongPS();
	PhanSo PSMax();
	PhanSo PSMin();
	void DSTangDan();
	void DSGiamDan();
};