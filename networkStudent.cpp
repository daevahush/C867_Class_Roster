#include "networkStudent.h"
#include <iostream>

NetworkStudent::NetworkStudent() : Student() {}
NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName,
	string email, int age, int courseCompletion[3]) : Student(studentID, firstName, lastName,
		email, age, courseCompletion) {
	this->degreeType = NETWORKING;
}

Degree NetworkStudent::getDegreeProgram() {
	return degreeType;
}

void NetworkStudent::print() {
	cout << getID();
	cout << "\t First Name: " << getFirstName();
	cout << "\t Last Name: " << getLastName();
	cout << "\t Email Address: " << getEmail();
	cout << "\t Age: " << getAge();
	cout << "\t daysInCourse: " << getCompletion()[0] << ", " << getCompletion()[1] << ", " << getCompletion()[2];
	cout << "\t Degree Program: NETWORKING";
	cout << endl;
}