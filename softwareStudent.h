#pragma once
#include "student.h"

class SoftwareStudent : public Student {

private:
	Degree degreeType = SOFTWARE;

public:
	SoftwareStudent();
	SoftwareStudent(string studentID, string firstName, string lastName,
		string email, int age, int courseCompletion[3]);

	Degree getDegreeProgram();

	void print();
};