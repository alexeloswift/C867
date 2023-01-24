//
//  main.cpp
//  C867
//
//  Created by Alexis Diaz on 1/16/23.
//

#include <iostream>
#include "roster.h"

/*
 Things of note in this project:
 
 In this project, I have employed a number of techniques to ensure its efficiency and scalability. Specifically, I utilized the power of pointers in C++ to manipulate data, which allowed for a more efficient use of memory. Additionally, I employed the use of stringstreams to parse data, which, while it may be overkill for the small amount of data this program handles, would be beneficial in a real-world scenario where a larger pool of data would be present.
 
 Throughout the development process, I kept in mind the importance of clean and maintainable code, as well as adhering to the SOLID principles of object-oriented programming. While the code is not without room for improvement, I can assure that I put forth my best effort to deliver a solid and functional product. I hope that it meets your expectations.
 */

using namespace std;

void programIntro() {
  cout << "Course: C867 (Scripting & Programming Applications)" << endl;
  cout << "Programming Language: C++" << endl;
  cout << "Student ID: 010664296" << endl;
  cout << "Name: Alexis Diaz" << endl << endl;
}

void lineBreak() {
  cout << "" << endl;
}

int main()
{
  programIntro();
  
  const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Alexis,Diaz,adia304@wgu.edu,25,30,30,30,SOFTWARE"
  };
  
  Roster classRoster;
  
  classRoster.parse(studentData);
  
  classRoster.printAll();
  
  classRoster.printInvalidEmails();
  
  cout << "AVERAGE DAYS IN COURSE:" << endl;
  for (int i = 0; i < 5; i++) {
    string studentID = classRoster.getStudentIDAtIndex(i);
    classRoster.printAverageDaysInCourse(studentID);
  }
  
  lineBreak();
  
  classRoster.printByDegreeProgram(SOFTWARE);
  
  classRoster.removeStudent("A3");
  
  classRoster.printAll();
  
  classRoster.removeStudent("A3");
  
  return 0;
  
}
