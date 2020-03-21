#include <iostream>
#include<string>
#include<iomanip>
#include<sstream>

using namespace std;

#include"Course.h"
#include "Cr.h"


Cr::Cr(string studentCourse, string room)
{
	this->room = room;
	this->studentCourse = studentCourse;
}
string Cr::GetRoom() const
{
	return room;

}
string Cr::toString() const 
{
	stringstream out;
	out << "(" << GetStudentCourse() << "," << GetRoom() << ")";
	return out.str();
}
