//Created six source code files (B)

#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"



int main()
{
    
    std::cout << "C867 Scripting and Programming Applications" << std::endl;
    std::cout << "Programming language used: C++" << std::endl;
    std::cout << "Student ID: 001510067" << std::endl;
    std::cout << "Yadiel Rosario" << std::endl;

    //studentData table (A)
    const std::string studentData[] =

    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Yadiel,Rosario,yadielrosario@gmail.com,26,12,4,9,SOFTWARE"
    };

    const int numStudents = 5;

    // Creating roster(F.2)
    Roster classRoster; 

    //Adding each student (F.3)
    for (int i = 0; i < numStudents; i++) 
    {
        classRoster.parse(studentData[i]);
    }

    //Program functionality (F.4)
    std::cout << "Displaying all students: " << std::endl;
    classRoster.printAll();
    std::cout << std::endl;

    std::cout << "Displaying invalid email addresses:" << std::endl;
    classRoster.printInvalidEmails();
    std::cout << std::endl;

    std::cout << "Displaying average days per class: " << std::endl;
    classRoster.printAverageDaysInCourse();

   
    
     std::cout << "Displaying by degree program: " << degreeProgramStrings[SOFTWARE] << std::endl;
     classRoster.printByDegreeProgram(SOFTWARE);
   

    std::cout << "Removing student with ID A3:" << std::endl;
    classRoster.removeStudentByID("A3");
    std::cout << std::endl;

    std::cout << "Displaying all students: " << std::endl;
    classRoster.printAll();
    std::cout << std::endl;

    std::cout << "Removing student with ID A3:" << std::endl;
    classRoster.removeStudentByID("A3");
    std::cout << std::endl;
    
    std::cout << "Press Enter to continue...";


    std::cin.get();
   
}


