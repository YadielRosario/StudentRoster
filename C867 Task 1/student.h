#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"


class Student
{

public:
	const static int daysSize = 3;

protected:
	//Variables included in Student class (D.1)
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysInCourse[daysSize];
	DegreeProgram degreeProgram;
	
public: //Access to each instane variable is done through setters and getters (D.2.c)
	Student();
	Student(std::string studentID, std::string firstname, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
	~Student();
	
	//Getters for each variable (D.2.a)
	std::string getStudentID();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	//Setters for each variable (D.2.b)
	void setStudentID(std::string sID);
	void setFirstName(std::string firstN);
	void setLastName(std::string lastN);
	void setEmailAddress(std::string emailAddr);
	void setAge(int ageNum);
	void setDaysInCourse(int numDays[]);
	void setDegreeProgram(DegreeProgram degreeP);
	
	
	static void printHeader();

	void print();


};
	

	
