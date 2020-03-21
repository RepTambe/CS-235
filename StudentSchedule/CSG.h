//#pragma once
#include <iostream>
#include<string>
#include<iomanip>
#ifndef CSG_H
#define CSG_H  
#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"
using namespace std;

class Csg : public Student, public Course {
private:

    //int studentID;
    string studentGrade;
    vector<Csg> CSG;
public:
    Csg (string studentCourse, string studentID, string studentGrade);
    string GetGrade() const;
    string toString() const;
    friend std::ostream& operator<< (ostream& os, const Csg& myclass)
    {
        os << myclass.toString();
        return os;
    }
};
#endif