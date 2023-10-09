#pragma once
#include <iostream>
#include "degree.h"
#include "student.h"

using namespace std;

class Roster {
public:
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void parse(string studentData);
	void printByDegreeProgram(DegreeProgram);
	string getStudentID(int spotOnRoster);
	~Roster();

private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];
};