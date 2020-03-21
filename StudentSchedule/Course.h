//#pragma once
#include <iostream>
#include<string>
#include<iomanip>
#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

class Course
{
private:
   // string studentCourse;
protected:
    string studentCourse;
    string room;
public:
    string GetStudentCourse() const;
    void toString() const;




};
#endif