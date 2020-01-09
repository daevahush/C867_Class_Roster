#pragma once
#include "student.h"

class NetworkStudent : public Student {

private:
	Degree degreeType = NETWORKING;

public:
	NetworkStudent();
	NetworkStudent(string studentID, string firstName, string lastName,
		string email, int age, int courseCompletion[3]);

	Degree getDegreeProgram();

	void print();
};