#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
using namespace std;

Roster::Roster() {}


void Roster::add(string studentID, string firstName, string lastName,
	string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType) {

	int courseCompletion[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] == nullptr) {
			switch (degreeType) {
			case NETWORKING:
				classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, email, age, courseCompletion);
				break;

			case SECURITY:
				classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, email, age, courseCompletion);
				break;

			case SOFTWARE:
				classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, email, age, courseCompletion);
				break;
			}
			break;
		}
	}
}


Student * Roster::getStudent(int i) {
	return classRosterArray[i];
};


void Roster::remove(string studentID) {
	bool removed = false;
	string name;

	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			if (studentID == classRosterArray[i]->getID()) {
				removed = true;
				cout << "Removing student " << studentID << endl;
				classRosterArray[i] = nullptr;
				delete classRosterArray[i];
				return;
			}
		}
	}
		
	cout << "Student ID " << studentID << " not found.";
}


void Roster::printAll() {
	cout << "Class Roster:" << '\n';
	for (int i = 0; i < 5; ++i) {
			(*classRosterArray[i]).print();
	}
	cout << '\n';
} 


void Roster::printDaysInCourse(string studentID) {
	int sumDays;
	int averageDays;
	int courseCompletion[3];

	for( int i = 0; i < 5; ++i) {
		if ((*classRosterArray[i]).getID() == studentID) {
				courseCompletion[0] = (*classRosterArray[i]).getCompletion()[0];
				courseCompletion[1] = (*classRosterArray[i]).getCompletion()[1];
				courseCompletion[2] = (*classRosterArray[i]).getCompletion()[2];

				sumDays = courseCompletion[0] + courseCompletion[1] + courseCompletion[2];
				averageDays = sumDays / 3;

				cout << studentID << ": " << averageDays << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	cout << "Invalid student email addresses:" << '\n';
	for (int i = 0; i < 5; ++i) {
		string email = classRosterArray[i]->getEmail();
		bool valid = false;

		if (email.find("@") != std::string::npos) {
			if (email.find(".") != std::string::npos) {
				if (email.find(" ") == std::string::npos) {
					valid = true;
				}
			}
		}

		if (valid != true) {
			cout << email << endl;
		}
	}
	cout << '\n';
}

void Roster::printByDegreeProgram(Degree degreeType) {
	cout << "Students by degree program: " << '\n';
	for (int i = 0; i < 5; ++i) {

		if (degreeType == (*classRosterArray[i]).getDegreeProgram()) {
			(*classRosterArray[i]).print();
		}
		else if (degreeType == (*classRosterArray[i]).getDegreeProgram()) {
			(*classRosterArray[i]).print();
		}
		else if (degreeType == (*classRosterArray[i]).getDegreeProgram()) {
			(*classRosterArray[i]).print();
		}
	}
	cout << '\n';
}


void main() {
	const string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		"A5,Lindsey,Weber,lwebe23@wgu.edu,29,14,22,18,SOFTWARE"
	};

	//Create instance of Roster class
	Roster classRoster;

	//Add each student to classRoster
	for (int i = 0; i < 5; ++i) {
		istringstream inString(studentData[i]);
		string array[9];
		Degree degreeType;

		for (int x = 0; x < 9; ++x) {
			getline(inString, array[x], ',');
		}

		degreeType = NONE;

		if (array[8] == "SOFTWARE") {
			degreeType = SOFTWARE;
		}
		else if (array[8] == "SECURITY") {
			degreeType = SECURITY;
		}
		else if (array[8] == "NETWORK") {
			degreeType = NETWORKING;
		}

		classRoster.add(array[0], array[1], array[2], array[3], stoi(array[4]), 
			stoi(array[5]), stoi(array[6]), stoi(array[7]), degreeType);
	}

	//My info & course info
	cout << "C867: Scripting & Programming Applications" << endl;
	cout << "Created in C++" << endl;
	cout << "Lindsey Weber" << endl;
	cout << "Student ID: " << "001233483" << endl;
	cout << '\n';
	
	classRoster.printAll();
	classRoster.printInvalidEmails();
	
	cout << "Average days to complete courses: " << endl;
	for (int i = 0; i < 5; ++i) {
		classRoster.printDaysInCourse(classRoster.getStudent(i)->getID());
	}
	cout << '\n';
	
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");
}

//Say goodbye, Caroline
Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		delete this->classRosterArray[i];
	}
}