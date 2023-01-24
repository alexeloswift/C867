//
//  roster.cpp
//  C867
//
//  Created by Alexis Diaz on 1/16/23.
//
#include <iostream>
#include <sstream>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

Roster::Roster()
{
  // Initialize classRosterArray
  this->classRosterArray = new Student *[5];
  this->lastIndex = -1; // No students added yet
  this->capacity = 5;
}

Roster::~Roster()
{
  // Delete all students in classRosterArray
  for (int i = 0; i <= lastIndex; i++)
  {
    delete classRosterArray[i];
  }
  // Delete classRosterArray itself
  delete[] classRosterArray;
}

void Roster::parse(const string studentData[]) {
  for (int i = 0; i < 5; i++)
  {
    string currentStudentData = studentData[i];
    stringstream ss(currentStudentData);
    string studentID, firstName, lastName, emailAddress, ageString, daysInCourse1String, daysInCourse2String, daysInCourse3String, degreeProgramString;
    int age, daysInCourse1, daysInCourse2, daysInCourse3;
    DegreeProgram degree;
    
    getline(ss, studentID, ',');
    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, emailAddress, ',');
    getline(ss, ageString, ',');
    getline(ss, daysInCourse1String, ',');
    getline(ss, daysInCourse2String, ',');
    getline(ss, daysInCourse3String, ',');
    getline(ss, degreeProgramString, ',');
    
    age = stoi(ageString);
    daysInCourse1 = stoi(daysInCourse1String);
    daysInCourse2 = stoi(daysInCourse2String);
    daysInCourse3 = stoi(daysInCourse3String);
    
    if (degreeProgramString == "SECURITY")
      degree = SECURITY;
    else if (degreeProgramString == "NETWORK")
      degree = NETWORK;
    else degree = SOFTWARE;
    
    this->add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
  }
}

void Roster::add(string studentID, string firstName, string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
  // Create new student object
  Student *newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
  // Check if there is already a student with the same ID
  for (int i = 0; i <= lastIndex; i++)
  {
    if (this->classRosterArray[i]->getStudentID() == studentID)
    {
      cout << "Error: Student with ID " << studentID << " already exists" << endl;
      return;
    }
  }
  if (lastIndex < capacity)
  {
    this->classRosterArray[++lastIndex] = newStudent;
  }
}

void Roster::removeStudent(string studentID)
{
  cout << "REMOVING STUDENT " << studentID << "..." << endl;
  
  bool found = false;
  for (int i = 0; i <= lastIndex; i++)
  {
    if (this->classRosterArray[i]->getStudentID() == studentID)
    {
      found = true;
      delete this->classRosterArray[i];
      this->classRosterArray[i] = this->classRosterArray[lastIndex];
      lastIndex--;
    }
  }
  if (!found)
  {
    cout << "ERROR: " << "Student with ID " << studentID << " not found" << endl;
  }
  cout << "" << endl;
}

void Roster::printAll()
{
  cout << "ALL STUDENTS:" << endl;
  for (int i = 0; i <= lastIndex; i++)
  {
    this->classRosterArray[i]->print();
  }
  cout << "" << endl;
}

void Roster::printInvalidEmails()
{
  cout << "INVALID EMAILS:" << endl;
  
  for (int i = 0; i <= lastIndex; i++)
  {
    string email = this->classRosterArray[i]->getEmailAddress();
    if (email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos)
    {
      cout << email << endl;
    }
  }
  cout << "" << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
  cout << "DEGREE PROGRAM: SOFTWARE" << endl;
  
  for (int i = 0; i <= lastIndex; i++)
  {
    if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram)
    {
      this->classRosterArray[i]->print();
    }
  }
  cout << "" << endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
  bool found = false;
  for (int i = 0; i <= lastIndex; i++)
  {
    if (this->classRosterArray[i]->getStudentID() == studentID)
    {
      found = true;
      int *courseDays = this->classRosterArray[i]->getDaysInCourse();
      cout << studentID << " - Average days in course: " << (courseDays[0] + courseDays[1] + courseDays[2]) / 3 << endl;
    }
  }
  
  if (!found)
  {
    cout << "ERROR:" << "Student with ID " << studentID << " not found" << endl;
  }
  
}

string Roster::getStudentIDAtIndex(int index) {
  if (index >= 0 && index <= lastIndex) {
    return classRosterArray[index]->getStudentID();
  }
  else {
    return "Error: Invalid index";
  }
}



