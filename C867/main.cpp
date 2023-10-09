#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

int main() {

	cout << "Scripting and Programming Applications - C867, Programming Language: C++, WGU StudentID: #004478495, Isom Brown" << endl << endl;

	const string studentData[] = {
		"A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Isom,Brown,isom_brown@yahoo.com,26,4,30,45,SOFTWARE"
	};

	// testing out program
	Roster classRoster;

	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}

	classRoster.printAll();

	cout << endl;

	classRoster.printInvalidEmails();

	cout << endl;

	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.getStudentID(i));
	}

	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);

	cout << endl;

	classRoster.remove("A3");

	cout << endl;

	classRoster.printAll();

	cout << endl;

	classRoster.remove("A3");

	return 0;

}