#pragma once

#include <iostream>
#include<string>
#include<iomanip>
#ifndef STUDENT_H
#define STUDENT_H 
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

class Student
{
private:
   // int studentID;
protected:
    string studentID;
public:
    string GetStudentID() const;
    void toString() const;




};
#endif