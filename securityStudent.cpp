#include "securityStudent.h"
#include <iostream>

SecurityStudent::SecurityStudent() : Student() {}
SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName,
	string email, int age, int courseCompletion[3]) : Student(studentID, firstName, lastName,
		email, age, courseCompletion) {
	this->degreeType = SECURITY;
}

Degree SecurityStudent::getDegreeProgram() {
	return degreeType;
}


void SecurityStudent::print() {
	cout << getID();
	cout << "\t First Name: " << getFirstName();
	cout << "\t Last Name: " << getLastName();
	cout << "\t Email Address: " << getEmail();
	cout << "\t Age: " << getAge();
	cout << "\t daysInCourse: " << getCompletion()[0] << ", " << getCompletion()[1] << ", " << getCompletion()[2];
	cout << "\t Degree Program: SECURITY";
	cout << endl;
}