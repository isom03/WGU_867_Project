#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
	// Have to define functions in header file before I can implement in .cpp
	Student();
	Student(string aStudentId, string fName, string lName, string eMail, int aAge, int course1, int course2, int course3, DegreeProgram aMajor);
	void print();

	//Defining setters
	void SetStudentId(string aStudentId);
	void SetStudentFirstName(string fName);
	void SetStudentLastName(string lName);
	void SetStudentEmail(string eMail);
	void SetStudentAge(int aAge);
	void SetDaysToCompCourse1(int course1);
	void SetDaysToCompCourse2(int course2);
	void SetDaysToCompCourse3(int course3);
	void SetDegreeProgram(DegreeProgram aMajor);

	//Defining getters
	string GetStudentId();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetStudentAge();
	int GetDaysToCompCourse1();
	int GetDaysToCompCourse2();
	int GetDaysToCompCourse3();
	DegreeProgram GetDegreeProgram();

private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToCompleteCourse[3];
	DegreeProgram major;
};