#include <iostream>
#include<string>
#include<iomanip>
#include<sstream>

using namespace std;


#include "SNAP.h"

Snap::Snap(string studentID, string name, string address, string phone)
{
	this->studentID = studentID;
	studentName = name;
	studentAddress = address;
	studentPhone = phone;

}
string Snap::GetName() const
{
	return studentName;
}

string Snap::GetAddress() const
{
	return studentAddress;
}

string Snap::GetPhone() const
{
	return studentPhone;
}
string Snap::toString() const
{
	stringstream out;
	out << "(" << GetStudentID() << "," << GetName() << "," << GetAddress() << ","  << GetPhone() << ")";
	return out.str();
}

