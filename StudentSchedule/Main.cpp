#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <iomanip>
#include <vector>
#include "Cdh.h"
#include "Cr.h"
#include "CSG.h"
#include "SNAP.h"
#include "Student.h"
#include "Course.h"

using namespace std;
 






int main(int argc, char* argv[]) {
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

    VS_MEM_CHECK               // enable memory leak check



    //Take in input file and create output file
        if (argc < 3)
        {
            cerr << "Please provide name of input and output files";
            return 1;
        }
    //cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    //cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }

    //Define Vectors
    vector<Cr> crs;
    vector<Snap> snap;
    vector<Csg> csg;
    vector<Cdh> cdh;
    //Get Input
    out << "Input Strings: " << endl;
    for (string line; getline(in, line);)	// Read until EOF 
    {
        
        

        //output input strings
       // out << line << endl;
        //Populate Cr Vector
        try {


            if ("cr(" == line.substr(0, 3))
            {
                out << line << endl;
                string courseName = line.substr(3, line.find(',') - 3);
                line = line.substr(line.find(',') + 1);
                string room = line.substr(0, line.find(')'));
                crs.push_back(Cr(courseName, room));


            }

            else if ("csg(" == line.substr(0, 4))
            {
                
                out << line << endl;
                string courseName1 = line.substr(4, line.find(',') - 4);
                line = line.substr(line.find(',') + 1);
                string studentNumber = line.substr(0, line.find(','));
                line = line.substr(line.find(',') + 1);
                string studentGrade = line.substr(0, line.find(')'));
                csg.push_back(Csg(courseName1, studentNumber, studentGrade));



            }



              else if ("snap(" == line.substr(0, 5))
            {
                //Populate Snap Vector
                out << line << endl;
                line = line.substr(line.find('('));
                string studentNum = line.substr(1, line.find(',') - 1);
                line = line.substr(line.find(',') + 1);
                string studentName = line.substr(0, line.find(','));
                line = line.substr(line.find(',') + 1);
                string studentAddy = line.substr(0, line.find(','));
                line = line.substr(line.find(',') + 1);
                string studentPhone = line.substr(0, line.find(')'));
                snap.push_back(Snap(studentNum, studentName, studentAddy, studentPhone));



            }



            else if ("cdh(" == line.substr(0, 4))
            {
                //Populate into CDH vector
                out << line << endl;
                line = line.substr(line.find('(') + 1);
                string courseName3 = line.substr(0, line.find(','));
                line = line.substr(line.find(',') + 1);
                string day = line.substr(0, line.find(','));
                line = line.substr(line.find(',') + 1);
                string hour = line.substr(0, line.find(')'));
                cdh.push_back(Cdh(courseName3, day, hour));


            }
            else
            {
                throw line;
            }

        }
        catch (string exception)
        {
            out << "**Error: " << exception << endl;
        }

        

    }

    // /* 
    out << endl << "Vectors:" << endl;
    for (unsigned int i = 0; i < snap.size(); i++)
    {
        out << "snap";
        out << snap[i] << endl;

    }
    for (unsigned int i = 0; i < csg.size(); i++)
    {
        out << "csg";
        out << csg[i] << endl;
    }
    for (unsigned int i = 0; i < cdh.size(); i++)
    {
        out << "cdh";
        out << cdh[i] << endl;
    }
    for (unsigned int i = 0; i < crs.size(); i++)
    {
        out << "cr";
        out << crs[i] << endl;

    }

    // Course Grades

    out << "\n" << "Course Grades:" << endl;
    for (unsigned int i = 0; i < csg.size(); ++i)
    {
        out << csg.at(i).GetStudentCourse() << ", ";
        for (int j = 0; j < snap.size(); ++j)
        {
            if (csg.at(i).GetStudentID() == snap.at(j).GetStudentID())
            {
                
                out << snap.at(j).GetName() << ", ";

                break;

            }
            
        }
        out << csg.at(i).GetGrade() << endl;
    }

    // Student Schedules
 
    string days;
    out << "\n" << "Student Schedules: " << endl;
    for (unsigned int i = 0; i < snap.size(); ++i)
    {
        out << snap.at(i).GetName() << ", " << snap.at(i).GetStudentID() << ", " << snap.at(i).GetAddress() << ", "
            << snap.at(i).GetPhone() << endl;

        string courseName;
        for (int j = 0; j < csg.size(); ++j)
        {
            if (snap.at(i).GetStudentID() == csg.at(j).GetStudentID())
            {
                courseName = csg.at(j).GetStudentCourse();
               
                out << courseName << " ";
                string time;
                bool timeWasChanged = false;

                for (int k = 0; k < cdh.size(); ++k)
                {

                    timeWasChanged = false;
                    if (cdh.at(k).GetStudentCourse() == courseName)
                    {
                        if (time != cdh.at(k).GetHour())
                        {
                            time = cdh.at(k).GetHour();
                            timeWasChanged = true;

                        }
                        out << cdh.at(k).GetDay();
                        
                        
                    }
                    if (timeWasChanged)
                    {
                        time = cdh.at(k).GetHour();
                        
                    }
                    
                }
                out << " " << time << ", ";
                for (int k = 0; k < crs.size(); k++) {
                    if (crs.at(k).GetStudentCourse() == csg.at(j).GetStudentCourse()) {
                        out << crs.at(k).GetRoom() << endl;
                    }
                }
               
                
               
                days = "";
                

            }

        }
       
        out << endl;
    }
   // */
   
    return 0;
}