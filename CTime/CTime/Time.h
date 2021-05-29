#pragma once
#include<iostream>
using namespace std;

class Time
{
private :
	int gio;
	int phut;
	int giay;
public :
	Time();
	Time(int, int ,int);
	Time(const Time&);

	friend istream& operator>>(istream&, Time&);
	friend ostream& operator<<(ostream&, Time);

	Time operator+(int);
	Time operator-(int);

	Time operator++(int);
	Time operator--(int);
};

