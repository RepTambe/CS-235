#pragma once


#include <iostream>
#include<string>
#include<iomanip>
#ifndef SNAP_H
#define SNAP_H   
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

class Snap : public Student {
private:

    //int studentID;
    string studentName;
    string studentAddress;
    string studentPhone;
    vector<Snap> snap;
public:
    Snap ( string studentID, string name, string address, string phone);
    string GetName() const;
    string GetAddress() const;
    string GetPhone() const;
    string toString() const;
    friend std::ostream& operator<< (ostream& os, const Snap& myclass)
    {
        os << myclass.toString();
        return os;
    }
};
#endif