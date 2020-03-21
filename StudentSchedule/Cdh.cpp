#include <iostream>
#include<string>
#include<iomanip>
#include<sstream>

using namespace std;


#include "Cdh.h"

Cdh::Cdh(string studentCourse, string day, string hour)
{
	this->studentCourse = studentCourse;
	this->day = day;
	this->hour = hour;

}

string Cdh::GetDay() const
{
	return day;
}

string Cdh::GetHour() const
{
	return hour;
}

string Cdh::toString() const
{
	stringstream out;
	out << "(" << GetStudentCourse() << "," << GetDay() << "," << GetHour() << ")";
	return out.str();
}


