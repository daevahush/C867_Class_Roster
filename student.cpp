#include<iostream>
#include<string>
#include "student.h"
#include "roster.h"

//get
string Student::getID() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmail() {
	return this->email;
}

int Student::getAge() {
	return this->age;
}

int * Student::getCompletion() {
		return this->courseCompletion;
}

Degree Student::getDegreeProgram() {
	return this->degreeType;
}

//set
void Student::setID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setCompletion(int courseCompletion[]) {
	for (int i = 0; i < 3; ++i) {
		this->courseCompletion[i] = courseCompletion[i];
	}
}

void Student::setDegreeType(Degree degreeType) {
	this->degreeType = degreeType;
}

//contstructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	this->courseCompletion[0] = 0;
	this->courseCompletion[1] = 0;
	this->courseCompletion[2] = 0;
}
Student::Student(string studentID, string firstName, string lastName,string email, 
	int age, int courseCompletion[]) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->courseCompletion[0] = courseCompletion[0];
	this->courseCompletion[1] = courseCompletion[1];
	this->courseCompletion[2] = courseCompletion[2];
}

void Student::print() {}

//destructor
Student::~Student() {}


