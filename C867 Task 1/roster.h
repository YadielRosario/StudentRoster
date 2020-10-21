#pragma once
#include "student.h"


class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents]; //creating class roster array of pointers (E.1)

public:
	void parse(std::string row); 
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram); 
	void removeStudentByID(std::string studentID); 
	void printAll();
	void printAverageDaysInCourse();
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeP);
	~Roster();
};

