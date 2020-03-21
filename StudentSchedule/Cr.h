//#pragma once

#include <iostream>
#include<string>
#include<iomanip>
#ifndef CR_H
#define CR_H   
#include <string>
#include <vector>
#include "Course.h"
using namespace std;

class Cr : public Course
{
private:

    //int studentID;
    string room;
    vector<Cr> crs;
public:
    Cr (string studentCourse, string room);
    string GetRoom() const;
    string toString() const;
    friend std::ostream& operator<< (ostream& os, const Cr& myclass)
    {
        os << myclass.toString();
        return os;
    }

};

#endif