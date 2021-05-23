#pragma once
class PhanSo
{
private:
	int tu;
	int mau;
public:
	// Constructor
	PhanSo();
	PhanSo(int);
	PhanSo(int, int);

	void SetPhanSo(int, int);
	void SetTu(int);
	void SetMau(int);
	int GetTu();
	int GetMau();

	int UCLN(int, int);
	void ChuanHoa();
	void RutGon();
	float KetQua();

	void Nhap();
	void Xuat();
};