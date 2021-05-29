#include "Time.h"
Time::Time()
{
	gio = 0;
	phut = 0;
	giay = 0;
}

Time::Time(int gio, int phut, int giay)
{
	this->gio = gio;
	this->phut = phut;
	this->giay = giay;
}

Time::Time(const Time& t)
{
	this->gio = t.gio;
	this->phut = t.phut;
	this->giay = t.giay;
}

istream& operator>>(istream& is, Time& t)
{
	cout << "\ngio: ";
	is >> t.gio;

	cout << "\nphut: ";
	is >> t.phut;

	cout << "\ngiay: ";
	is >> t.giay;

	return is;
}

ostream& operator << (ostream& os, Time t)
{
	os << t.gio << " " << t.phut << " " << t.giay << " ";
	return os;
}

Time Time::operator+(int a)
{
	Time result(this->gio, this->phut, this->giay);

	result.giay = this->giay + a;
	if (result.giay >= 60)
	{
		result.giay = result.giay - 60;
		result.phut = this->phut + 1;
		if (result.phut >= 60)
		{
			result.phut = result.phut - 60;
			result.gio = this->gio + 1;
			if (result.gio >= 24)
			{
				result.gio = result.gio - 24;
			}
		}
	}
	return result;
}

Time Time::operator-(int a)
{
	Time result(this->gio, this->phut, this->giay);

	result.giay = this->giay - a;
	if (result.giay <= 0)
	{
		result.giay = 60 - abs(result.giay);
		result.phut = this->phut - 1;
		if (result.phut <= 0)
		{
			result.phut = 60 - abs(result.phut);
			result.gio = this->gio - 1;
			if (result.gio >= 24)
			{
				result.gio = 24 - abs(result.gio);
			}
		}
	}
	return result;
}

