//#pragma once
#include <iostream>
#include<string>
#include<iomanip>
#ifndef CDH_H
#define CDH_H  
#include <string>
#include <vector>
#include "Course.h"
using namespace std;

class Cdh : public Course {
private:

    //int studentID;
    string day;
    string hour;
    vector<Cdh> cdh;
public:
    Cdh(string studentCourse, string day, string hour);
    string GetDay() const;
    string GetHour() const;
    string toString() const;
    friend std::ostream& operator<< (ostream& os, const Cdh& myclass)
    {
        os << myclass.toString();
        return os;
    }
};
#endif