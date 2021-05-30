#include "Date.h"
Date::Date()
{
	ngay = 0;
	thang = 0;
	nam = 0;
    ch = 0;
}

Date::Date(int ngay, int thang, int nam)
{
	this->ngay = ngay;	
	this->nam = nam;
	this->thang = thang;
    ch = 0;
}

Date::Date(const Date& t)
{
	this->ngay = t.ngay;
	this->thang = t.thang;
	this->nam = t.nam;
}

istream& operator>>(istream& is, Date& t)
{
	cout << "\nngay: ";
	is >> t.ngay;

	cout << "\nthang: ";
	is >> t.thang;

	cout << "\nnam: ";
	is >> t.nam;

	return is;
}

ostream& operator << (ostream& os, Date t)
{
	os << t.ngay << " " << t.thang << " " << t.nam << " ";
	return os;
}


int Date::TimNamNhuan(int nam)
{
    // Neu nam % 4 == 0 va nam % 400 == 0 thi la nam nhuan
    if (nam % 4 == 0 && nam % 400 == 0)
    {
        return 1;
    }

    else
    {
        if (nam % 100 == 0)
        {
            return 0;
        }

        if (nam % 4 == 0)
        {
            return 1;
        }
    }

    // neu khong thi se khong phai nam nhuan
    return 0;
}

void Date::TangNam()
{
    // Tang thoi gian them 1 nam
    if (thang > 12)
    {
        nam++;
        thang = thang - 12;
    }
}

void Date::TangThang()
{
    // Tang them 1 thang
    if (ngay > 31 && (thang == 1 || thang == 3 || thang == 5 || thang == 7
        || thang == 8 || thang == 10 || thang == 12))
    {
        thang++;
        ngay = ngay - 31;
    }

    if (ngay > 30 && (thang == 4 || thang == 6 || thang == 9 || thang == 11))
    {
        thang++;
        ngay = ngay - 30;
    }

    if (thang == 2 && ngay > 29 && TimNamNhuan(nam) == 1)
    {
        thang++;
        ngay = ngay - 29;
    }

    if (thang == 2 && ngay > 28 && TimNamNhuan(nam) == 0)
    {
        thang++;
        ngay = ngay - 28;
    }
}

void Date::GiamNam()
{
    if (thang <= 0)
    {
        nam--;
        thang = abs(12 - thang);
    }
}



void Date::GiamThang()
{
    if (ngay <= 0 && (thang == 2 || thang == 4 || thang == 6 || thang == 9
        || thang == 11 || thang == 1))
    {
        thang--;
        ngay = abs(31 - ngay);
    }

    if (ngay <= 0 && ( thang == 5 || thang == 7 || thang == 8 && thang == 10
       || thang == 12))
    {
        thang--;
        ngay = abs(30 - ngay);
    }

    if (thang == 3 && ngay <= 0 && TimNamNhuan(nam) == 1)
    {
        thang--;
        ngay = abs(29 - ngay);
    }

    if (thang == 3 && ngay <= 0 && TimNamNhuan(nam) == 0)
    {
        thang--;
        ngay = abs(28 - ngay);
    }
}

void Date::ChuanHoaCong()
{
    TangThang();
    TangNam();
}

void Date::ChuanHoaTru()
{
    GiamThang();
    GiamNam();
}

Date Date::operator+(int a)
{
    Date T(ngay, thang, nam);
    T.ngay = T.ngay + a;
    T.ChuanHoaCong();
    return T;
}

Date Date::operator-(int a)
{
    Date T(ngay, thang, nam);
    T.ngay = T.ngay + (-a);
    T.ChuanHoaTru();
    return T;
}

Date Date::operator++(int)
{
    Date T(ngay, thang, nam);
    T.ngay = T.ngay + 1;
    T.ChuanHoaCong();
    return T;
}

Date Date::operator--(int)
{
    Date T(ngay, thang, nam);
    T.ngay = T.ngay + (-1);
    T.ChuanHoaTru();
    return T;
}

int Date::rdn(int y, int m, int d) {
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}

int Date::operator-(Date A)
{
 
    return rdn(this->nam, this->thang, this->ngay) - rdn(A.nam, A.thang, A.ngay);
}