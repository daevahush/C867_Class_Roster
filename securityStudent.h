#pragma once
#include "student.h"

class SecurityStudent : public Student {

private:
	Degree degreeType = SECURITY;

public:
	SecurityStudent();
	SecurityStudent(string studentID, string firstName, string lastName,
		string email, int age, int courseCompletion[3]);

	Degree getDegreeProgram();

	void print();
};