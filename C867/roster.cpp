#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

//Function parses through string array student table and calls "add()" to add students to array.
void Roster::parse(string studentData) {

	int firstComma = studentData.find(','); //.find() returns count for the the number of chars it took to get to character you were looking for
	string sID = studentData.substr(0, firstComma); //substr() takes starting point as first parameter and number of characters (including starting point) you'd like to inlcude in substring

	int startOfNextPieceOfData = firstComma + 1; // moves me to the start of next piece of data I need to record.
	int nextComma = studentData.find(',', startOfNextPieceOfData);// first parameter is what you're looking for. The second is where you start from
	string fName = studentData.substr(startOfNextPieceOfData, nextComma - startOfNextPieceOfData); //subracticing startOfNextPieceOfData from nextComma to get value for # of characters I need to inlucde

	startOfNextPieceOfData = nextComma + 1; //next few blocks of code repeat previous steps only placing substrings in new variables to use later in creation of Student object
	nextComma = studentData.find(',', startOfNextPieceOfData);
	string lName = studentData.substr(startOfNextPieceOfData, nextComma - startOfNextPieceOfData);

	startOfNextPieceOfData = nextComma + 1;
	nextComma = studentData.find(',', startOfNextPieceOfData);
	string eMail = studentData.substr(startOfNextPieceOfData, nextComma - startOfNextPieceOfData);

	startOfNextPieceOfData = nextComma + 1;
	nextComma = studentData.find(',', startOfNextPieceOfData);
	string strAge = studentData.substr(startOfNextPieceOfData, nextComma - startOfNextPieceOfData);
	int intAge = stoi(strAge); //stoi() takes a string and converts it to an integer

	startOfNextPieceOfData = nextComma + 1;
	nextComma = studentData.find(',', startOfNextPieceOfData);
	string strCourse1 = studentData.substr(startOfNextPieceOfData, nextComma - startOfNextPieceOfData);
	int intCourse1 = stoi(strCourse1);

	startOfNextPieceOfData = nextComma + 1;
	nextComma = studentData.find(',', startOfNextPieceOfData);
	string strCourse2 = studentData.substr(startOfNextPieceOfData, nextComma - startOfNextPieceOfData);
	int intCourse2 = stoi(strCourse2);

	startOfNextPieceOfData = nextComma + 1;
	nextComma = studentData.find(',', startOfNextPieceOfData);
	string strCourse3 = studentData.substr(startOfNextPieceOfData, nextComma - startOfNextPieceOfData);
	int intCourse3 = stoi(strCourse3);

	startOfNextPieceOfData = nextComma + 1;
	nextComma = studentData.find(',', startOfNextPieceOfData);
	string strDegreeProgram = studentData.substr(startOfNextPieceOfData, nextComma - startOfNextPieceOfData);
	DegreeProgram aMajor; // Set if else statements provides me a way to convert students major from a string to a enum DegreeProgram
	if (strDegreeProgram == "SECURITY") {
		aMajor = SECURITY;
	}
	else if (strDegreeProgram == "NETWORK") {
		aMajor = NETWORK;
	}
	else {
		aMajor = SOFTWARE;
	}
	add(sID, fName, lName, eMail, intAge, intCourse1, intCourse2, intCourse3, aMajor);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	// simply creating a new student object to class roster array
	//lastIndex gives me a way to keep track of index for array and moves me to an empty element I can place the new student in
	classRosterArray[++Roster::lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}

// Function simply prints out array using print function defined in student.cpp
void Roster::printAll() {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		classRosterArray[i]->print();
	}
}

//Function removes a student by placing student at end of array then decrementing variable lastIndex, essentially moving student outside bounds of array 
void Roster::remove(string studentID) {
	bool studentOnRoster = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->GetStudentId() == studentID) {
			if (i < Roster::lastIndex) {
				Student* tempStudent = classRosterArray[Roster::lastIndex];
				classRosterArray[Roster::lastIndex] = classRosterArray[i];
				classRosterArray[i] = tempStudent;
				studentOnRoster = true;
			}
			Roster::lastIndex--;
		}
	}
	if (!studentOnRoster) {
		cout << "A student with the studentID " << studentID << " was not found on the roster." << endl;
	}
	else
	{
		cout << "Student with the studentID " << studentID << " was removed from the roster" << endl;
	}
}

// Function to print the average number of day a student has spent in a class. Simply iterate through class roster until I find student then find average of days in course by using getter function
void Roster::printAverageDaysInCourse(string studentID) {
	int numberOfCoursesTaken = 3;
	int averageDaysInCourse;
	int index = 0;
	while (classRosterArray[index]->GetStudentId() != studentID) {
		index++;
	}
	averageDaysInCourse = (classRosterArray[index]->GetDaysToCompCourse1() + classRosterArray[index]->GetDaysToCompCourse2() + classRosterArray[index]->GetDaysToCompCourse3()) / numberOfCoursesTaken;
	cout << classRosterArray[index]->GetFirstName() << " has been in their three courses for an average of roughly " << averageDaysInCourse << " days." << endl;
}

//Fucntion prints invalid email addresses by iterating through roster array. Check each student to make sure they do not include spaces and they do inlude an "@" and "."
void Roster::printInvalidEmails() {
	bool allEmailsVaild = true; //Once I work my way through the roster I need a way to tell if all emails are valid. Boolean will be set to false if I find invalid email.

	for (int i = 0; i <= Roster::lastIndex; i++) {
		string eMail = classRosterArray[i]->GetEmail();
		if (eMail.find(' ') != string::npos || eMail.find('@') == string::npos || eMail.find('.') == string::npos) { // find() function returns string::npos when the subtring you're looking for can't be found
			cout << classRosterArray[i]->GetFirstName() << "'s email " << eMail << " is not a valid email." << endl;
			allEmailsVaild = false;
		}
	}
	if (allEmailsVaild) {
		cout << "All students have a valid email address.";
	}
}

//Funntion prints students with specific degree program. Accomplished by going through each student and checking their degree program
void Roster::printByDegreeProgram(DegreeProgram major) {
	string degreeProgram[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	cout << "The following student(s) have " << degreeProgram[major] << " as a degree program." << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->GetDegreeProgram() == major) {
			classRosterArray[i]->print();
		}
	}
}

string Roster::getStudentID(int spotOnRoster) {
	return classRosterArray[spotOnRoster]->GetStudentId();
}

Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}