#pragma once
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"

class Roster {

private:
	Student * classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

public:
	Student * getStudent(int i);

	void add(string studentID, string firstName, string lastName,
		string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);

	Roster();

	~Roster();
};