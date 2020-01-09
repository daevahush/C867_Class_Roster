#pragma once
#include <string>
#include "degree.h"
using namespace std;


class Student {

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int courseCompletion[3]; 
	Degree degreeType;
		
public:
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int * getCompletion();
	virtual Degree getDegreeProgram();

	void setID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setCompletion(int courseCompletion[]);
	void setDegreeType(Degree degreeType);

	Student();
	Student(string studentID, string firstName, string lastName, 
		string email, int age, int courseCompletion[]);

	virtual void print();

	~Student();
};
