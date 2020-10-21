#include "student.h"

//Default contructor 
Student::Student() 
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysSize; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::NETWORK;
}

//Constructor with parameters (D.2.d)
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysSize; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}

//Destructor
Student::~Student() {}

//Getters (D.2.a)
std::string Student::getStudentID() { return this->studentID; }
std::string Student::getFirstName() { return this->firstName; }
std::string Student::getLastName() { return this->lastName; }
std::string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//Setters (D.2.b)
void Student::setStudentID(std::string sID) { this->studentID = sID; }
void Student::setFirstName(std::string firstN) { this->firstName = firstN; }
void Student::setLastName(std::string lastN) { this->lastName = lastN; }
void Student::setEmailAddress(std::string emailAddr) { this->emailAddress = emailAddr; }
void Student::setAge(int ageNum) { this->age = ageNum; }
void Student::setDaysInCourse(int numDays[])
{
	for (int i = 0; i < daysSize; i++) this->daysInCourse[i] = numDays[i];
}
void Student::setDegreeProgram(DegreeProgram degreeP) { this->degreeProgram = degreeP; }

void Student::printHeader()
{
	std::cout << "Student ID|First Name|Last Name|Email Address          |Age  |Days To Complete Courses|Degree Program" << std::endl;
}

void Student::print() //prints specific student data (D.2.e)
{	
	const char separator = ' ';
	const int nameWidth = 6;

	std::cout << std::left << std::setw(11) << this->getStudentID();
	std::cout << std::setw(11) <<this->getFirstName();
	std::cout << this->getLastName() << '\t';
	std::cout << this->getEmailAddress() << '\t';
	std::cout << std::setw(6) << this->getAge();
	std::cout << std::setw(10) << this->getDaysInCourse()[0];
	std::cout << std::setw(10) << this->getDaysInCourse()[1];
	std::cout << std::setw(5) << this->getDaysInCourse()[2];
	std::cout << degreeProgramStrings[this->getDegreeProgram()] << std::endl;
}
