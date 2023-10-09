#include <iostream>
#include "degree.h"
#include "student.h"

using namespace std;

//Constructor for student
Student::Student() {
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysToCompleteCourse[0] = 0;
	this->daysToCompleteCourse[1] = 0;
	this->daysToCompleteCourse[2] = 0;
	this->major = SECURITY;
}
Student::Student(string aStudentId, string fName, string lName, string eMail, int aAge, int course1, int course2, int course3, DegreeProgram aMajor) {
	this->studentId = aStudentId;
	this->firstName = fName;
	this->lastName = lName;
	this->emailAddress = eMail;
	this->age = aAge;
	this->daysToCompleteCourse[0] = course1;
	this->daysToCompleteCourse[1] = course2;
	this->daysToCompleteCourse[2] = course3;
	this->major = aMajor;
}


//Print function to print all student info
void Student::print() {
	cout << studentId;
	cout << "	First Name: " << firstName;
	cout << "	Last Name: " << lastName;
	cout << "	Age: " << age;
	cout << "		daysInCourse: {" << daysToCompleteCourse[0] << ", " << daysToCompleteCourse[1] << ", " << daysToCompleteCourse[2] << "}";
	cout << "	Degree Program: " << DegreeProgramString[major] << endl;

}

// Implementation of setters for student class
void Student::SetStudentId(string aStudentId) {
	studentId = aStudentId;
}

void Student::SetStudentFirstName(string fName) {
	firstName = fName;
}

void Student::SetStudentLastName(string lName) {
	lastName = lName;
}

void Student::SetStudentEmail(string eMail) {
	emailAddress = eMail;
}

void Student::SetStudentAge(int aAge) {
	age = aAge;
}

void Student::SetDaysToCompCourse1(int course1) {
	daysToCompleteCourse[0] = course1;
}

void Student::SetDaysToCompCourse2(int course2) {
	daysToCompleteCourse[1] = course2;
}

void Student::SetDaysToCompCourse3(int course3) {
	daysToCompleteCourse[2] = course3;
}

void Student::SetDegreeProgram(DegreeProgram aMajor) {
	major = aMajor;
}

//Implementation of getters
string Student::GetStudentId() {
	return studentId;
}
string Student::GetFirstName() {
	return firstName;
}
string Student::GetLastName() {
	return lastName;
}
string Student::GetEmail() {
	return emailAddress;
}
int Student::GetStudentAge() {
	return age;
}
int Student::GetDaysToCompCourse1() {
	return daysToCompleteCourse[0];
}
int Student::GetDaysToCompCourse2() {
	return daysToCompleteCourse[1];
}
int Student::GetDaysToCompCourse3() {
	return daysToCompleteCourse[2];
}
DegreeProgram Student::GetDegreeProgram() {
	return major;
}
