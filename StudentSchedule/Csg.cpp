#include <iostream>
#include<string>
#include<iomanip>
#include<sstream>

using namespace std;


#include "CSG.h"

Csg:: Csg(string studentCourse, string studentID, string studentGrade)
{
	this->studentCourse = studentCourse;
	this->studentID = studentID;
	this->studentGrade = studentGrade;
}
string Csg::GetGrade() const
{
	return studentGrade;
}
string Csg::toString() const
{
	stringstream out;
	out << "(" << GetStudentCourse() << "," << GetStudentID()  << "," << GetGrade() << ")";
	return out.str();
}