#include "softwareStudent.h"
#include <iostream>

SoftwareStudent::SoftwareStudent() : Student(){}
SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName,
	string email, int age, int courseCompletion[3]) : Student(studentID, firstName, lastName,
		email, age, courseCompletion) {
	this->degreeType = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram() {
	return degreeType;
}

void SoftwareStudent::print() {
	cout << getID();
	cout << "\t First Name: " << getFirstName();
	cout << "\t Last Name: " << getLastName();
	cout << "\t Email Address: " << getEmail();
	cout << "\t Age: " << getAge();
	cout << "\t daysInCourse: " << getCompletion()[0] << ", " << getCompletion()[1] << ", " << getCompletion()[2];
	cout << "\t Degree Program: SOFTWARE";
	cout << endl;
}