#include "roster.h"
#include <string>

void Roster::parse(std::string studentData)
{
	//This method looks for each comma in the array and assigns it a location (rightLocation). It parses the information to the left of the comma but before the previous comma (leftLocation). It then assigns that string to the correct variable. 

	//student ID
	int rightLocation = studentData.find(",");
	std::string sID = studentData.substr(0, rightLocation);

	//first name
	int leftLocation = rightLocation + 1;
	rightLocation = studentData.find(",", leftLocation);
	std::string fName = studentData.substr(leftLocation, rightLocation - leftLocation);

	//last name
	leftLocation = rightLocation + 1;
	rightLocation = studentData.find(",", leftLocation);
	std::string lName = studentData.substr(leftLocation, rightLocation - leftLocation);

	//email address
	leftLocation = rightLocation + 1;
	rightLocation = studentData.find(",", leftLocation);
	std::string emailAddr = studentData.substr(leftLocation, rightLocation - leftLocation);

	//age
	leftLocation = rightLocation + 1;
	rightLocation = studentData.find(",", leftLocation);
	int sAge = std::stoi(studentData.substr(leftLocation, rightLocation - leftLocation));

	//days in course
	//1
	leftLocation = rightLocation + 1;
	rightLocation = studentData.find(",", leftLocation);
	double days1 = std::stod(studentData.substr(leftLocation, rightLocation - leftLocation));
	//2
	leftLocation = rightLocation + 1;
	rightLocation = studentData.find(",", leftLocation);
	double days2 = std::stod(studentData.substr(leftLocation, rightLocation - leftLocation));
	//3
	leftLocation = rightLocation + 1;
	rightLocation = studentData.find(",", leftLocation);
	double days3 = std::stod(studentData.substr(leftLocation, rightLocation - leftLocation));

	//degree program
	leftLocation = rightLocation + 1;
	rightLocation = studentData.find(",", leftLocation);
	std::string dProgram = studentData.substr(leftLocation, rightLocation - leftLocation);

	//converting the degree program string to correct degree program enum
	DegreeProgram degreeP = SECURITY;
	if (dProgram.at(0) == 'S' && dProgram.at(1) == 'E') {
		degreeP = SECURITY;
	}
	else if (dProgram.at(0) == 'N') {
		degreeP = NETWORK;
	}
	else if (dProgram.at(0) == 'S' && dProgram.at(1) == 'O') {
		degreeP = SOFTWARE;
	}
	//creating the object (E.2)
	add(sID, fName, lName, emailAddr, sAge, days1, days2, days3, degreeP); 

}

//Add method (E.3.a)	
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dProgram)
{
	//assigning daysInCourse to a single array
	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	
	//creating Student object
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, dProgram);

}

//Remove student by ID (E.3.b)
void Roster::removeStudentByID(std::string sID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == sID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		std::cout << sID << " removed from roster." << std::endl << std::endl;
		
	}
	else std::cout << sID << " not found." << std::endl << std::endl;
}


//Printall method which prints all information (E.3.c)
void Roster::printAll()
{
	Student::printHeader(); //header to help organize the columns

	const char separator = ' ';
	const int nameWidth = 6;

	//PrintAll function now calls the print() function
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		
		classRosterArray[i]->print();
		
	}
}


//Calculates and prints average days in course (E.3.d)
void Roster::printAverageDaysInCourse()
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		std::cout << classRosterArray[i]->getStudentID() << ": "; //printAverageDaysInCourse() now outputs using the student ID as an identifier.
		std::cout << (static_cast<double>(classRosterArray[i]->getDaysInCourse()[0]) + static_cast<double>(classRosterArray[i]->getDaysInCourse()[1]) + static_cast<double>(classRosterArray[i]->getDaysInCourse()[0])) / 3.0 << std::endl;
	}
	std::cout << std::endl;
}


//Valid email address should include @ and . but must not have a space (E.3.e)
void Roster::printInvalidEmails()
{

	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		std::string emailAddr = (classRosterArray[i]->getEmailAddress());
		std::string firstName = (classRosterArray[i]->getFirstName());
		std::string lastName = (classRosterArray[i]->getLastName());
		if (emailAddr.find('.') == std::string::npos || (emailAddr.find('@') == std::string::npos || (emailAddr.find(' ') != std::string::npos)))
		{
			any = true;
			std::cout << firstName << " " << lastName << ": " << classRosterArray[i]->getEmailAddress() << std::endl;
		}

		if (!any) std::cout << "NONE" << std::endl;
	}
}

//PrintByDegreeProgram prints students by their degree program (E.3.f)
void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
	Student::printHeader();
	
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeprogram) 
			classRosterArray[i]->print();
	}

	
	std::cout << std::endl;
}


Roster::~Roster()
{
	std::cout << "DESTRUCTOR CALLED" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		std::cout << "Destroying Student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	}


