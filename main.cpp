#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <iomanip>

using namespace std;

string assign_grade(double score, double average)
{

	if (score <= (average - 15)) return "E";
	if (score >= (average + 15)) return "A";

	if (score < (average - 5)) return "D";
	if (score > (average + 5)) return "B";
	return "C";
}
  /*void count_grades(double scores, double averages)
{
	//int countA = 0;
	//int countB = 0;
	//int countC = 0;
	//int countD = 0;
	//int countE = 0;
	if (scores <= (averages - 15)) ++countE;
	if (scores >= (averages + 15)) ++countA;

	if (scores < (averages - 5)) ++countD;
	if (scores > (averages + 5))++countB;
	++countC;
}
*/
int main(int argc, char* argv[])
{
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
	VS_MEM_CHECK               // enable memory leak che
//Readand output student scores from the input file.
//The first line of the input file has the number of students and exams.
		string file1, file2;
		int numStudents;
		int numExams;
		int numLines;
		int a = 0;
		int scores;
		string firstName;
		string lastName;
		


		

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

		//Input Array Sizes
		in >> numStudents;
		in >> numExams;
		
		
		double averageScore;
		double currentAverage;
		string* nameArray = new string[numStudents];
		int** scoreArray = new int* [numStudents];
		double* avgArray = new double[numExams];
		
		//Populate Arrays
		for (int i = 0; i < numStudents; ++i)
		{
			scoreArray[i] = new int[numExams];
			
		}
		for (int i = 0; i < numStudents; i++)
		{
			in >> firstName >> lastName;
			nameArray[i] = firstName + " " + lastName;
			for (int j = 0; j < numExams; ++j)
			{
				in >> scores;
				scoreArray[i][j] = scores;
				
			}
		}
		//Output Student Names and Scores
		out << "Student Scores: " << endl;
		for (int i = 0; i < numStudents; ++i)
		{
			out << std::setw(20) << nameArray[i] << " ";
			for (int j = 0; j < numExams; ++j)
			{
			//out << std::setw(20) <<  << " ";
				out << std::fixed << std::setprecision(0) << std::setw(6) << scoreArray[i][j];
			}
			out << endl;
		}
		//Compute exam Averages
		out << "Exam Averages: " << endl;
		for (int i = 0; i < numExams; ++i)
		{
			currentAverage = 0.0;
			for (int j = 0; j < numStudents; ++j)
			{
				currentAverage += scoreArray[j][i];
				
				
			}
			averageScore = currentAverage / numStudents;
			avgArray[i] = currentAverage / numStudents;
			out << std::fixed << setprecision(1) << setw(6) << "Exam " << i + 1 << " Average = " << avgArray[i] << endl;
		}

		// Output Student Grades
		out << "Student Exam Grades: " << endl;
		for (int i = 0; i < numStudents; ++i)
		{
			out << std::setw(20) << nameArray[i] << " ";
			for (int j = 0; j < numExams; ++j)
			{
				//out << std::setw(20) <<  << " ";
				out << std::fixed << std::setprecision(0) << std::setw(6) << scoreArray[i][j] << "(";
				out << assign_grade(scoreArray[i][j], avgArray[j]) << ")";
				

			}
			out << endl;
		}
		
		// Exam Grades
		
		//int* countArray = new int[5];
		out << "Exam Grades:" << endl << endl;
		for (int i = 0; i < numExams; ++i)
		{
			int countA = 0;
			int countB = 0;
			int countC = 0;
			int countD = 0;
			int countE = 0;
			
			for (int j = 0; j < numStudents; ++j)
			{
				if (assign_grade(scoreArray[j][i], avgArray[i]) == "A")
				{
					++countA;
				}
				if (assign_grade(scoreArray[j][i], avgArray[i]) == "B")
				{
					++countB;
				}
				if (assign_grade(scoreArray[j][i], avgArray[i]) == "C")
				{
					++countC;
				}
				if (assign_grade(scoreArray[j][i], avgArray[i]) == "D")
				{
					++countD;
				}
				if (assign_grade(scoreArray[j][i], avgArray[i]) == "E")
				{
					++countE;
				}
				//out << std::fixed << std::setprecision(0) << std::setw(6) << countA;
			


			}
			//Output Total Number of Each Grade
			out << std::fixed << std::setprecision(0) << std::setw(6) << "Exam " << i+1 << " " << countA << "(A)";
			out << std::fixed << std::setprecision(0) << std::setw(6)  << countB << "(B)";
			out << std::fixed << std::setprecision(0) << std::setw(6) << countC << "(C)";
			out << std::fixed << std::setprecision(0) << std::setw(6)  << countD << "(D)";
			out << std::fixed << std::setprecision(0) << std::setw(6)  << countE << "(E)";
			out << endl;
		}
		/*
		for (int i = 0; i < numExams; ++i)
		{
			currentAverage = 0.0;
			for (int j = 0; j < numStudents; ++j)
			{
				currentAverage += scoreArray[i][j];


			}
			averageScore = currentAverage / numStudents;
			avgArray[i] = currentAverage / numStudents;
			out << std::fixed << setprecision(1) << setw(6) << "Exam " << i << " Average = " << avgArray[i] << endl;
		}
		*/
		for (int i = 0; i < numStudents; ++i)
		{
			//scoreArray[i] = NULL;
			delete [] scoreArray[i];


			//delete [] scoreArray;
		}
		delete [] scoreArray;
		delete[] nameArray;
		delete[] avgArray;

	
		
		
		
		
		
		
		// read input file lines and send to output file
		//for (string line; getline(in, line);)
		//{
		//	out << line << endl;
		//}
		/*cout << "Output File: " << argv[2] << endl;
		ofstream outFile(argv[2]);
		if (!outFile)
		{
			inFile.close(); 
			cerr << "Unable to open: " << argv[2] << endl;
			return 3;
		}*/
		//inFile >> numStudents >> numExams;
		//cout << numStudents;
	
	
	
	}
	


//Read and output student scores from the input file.
//The first line of the input file has the number of students and exams.





//Subsequent lines contain the student name followed by scores for each exam.
//All students have the same number of exam scores.

//Store the student names in a dynamic string array(no vectors).

//Store the exam scores in a two - dimensional dynamic double array(one row for each student, one column for each exam score, ie. # students x # of exams.) Again, use arrays and not vectors to store exam scores!

//Output the average score for each exam(rounded to one decimal place.)

//Output each student's exam grade in evenly spaced columns - the student score followed by their grade in parentheses.

/*If the student's score is within + or - 5 points of the average, give a grade of C.
If the grade is more than 5 points but less than 15 points above(or below) the average, give a grade of B(D).
If the grade is 15 points or more above(or below) the average, give a grade of A(E).
Output for each exam the number of student grades for A's, B's, C's, D's, and E's. (List the letter grade in parentheses after the number of grades.)
Extra Credit : Calculate average score of all exams and output each students final score followed by letter grade in parentheses(average student exam scores and grade according to class final average score.)
Test forand eliminate all memory leaks.
*/


