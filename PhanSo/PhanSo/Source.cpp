#include <iostream>
#include "PhanSo.h"
#include "DSPhanSo.h"
using namespace std;

int main()
{
    DSPhanSo a;
    a.NhapDS();

    // Tong cac phan so
    cout << "Tong cac phan so la: ";
    PhanSo tongPS;
    tongPS = a.TongPS();
    tongPS.RutGon();
    tongPS.ChuanHoa();
    tongPS.Xuat();
    cout << endl;

    // Tim phan so lon nhat
    cout << "Phan so lon nhat la: ";
    PhanSo max;
    max = a.PSMax();
    max.Xuat();
    cout << endl;

    // Tim phan so nho nhat
    cout << "Phan so nho nhat la: ";
    PhanSo min;
    min = a.PSMin();
    min.Xuat();
    cout << endl;

    // Danh sach phan so tang dan
    cout << "Danh sach phan so tang dan la: ";
    a.DSTangDan();
    a.XuatDS();
    cout << endl;

    // Danh sach phan so giam dan
    cout << "Danh sach phan so giam dan la: ";
    a.DSGiamDan();
    a.XuatDS();
    cout << endl;
}