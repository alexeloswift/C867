//
//  student.cpp
//  C867
//
//  Created by Alexis Diaz on 1/16/23.
//
#include <iostream>
#include <iomanip>
#include "student.h"
#include "degree.h"

using namespace std;

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
  this->studentID = studentID;
  this->firstName = firstName;
  this->lastName = lastName;
  this->emailAddress = emailAddress;
  this->age = age;
  this->daysInCourse[0] = daysInCourse1;
  this->daysInCourse[1] = daysInCourse2;
  this->daysInCourse[2] = daysInCourse3;
  this->degreeProgram = degreeProgram;
}

// Getters
string Student::getStudentID()
{
  return this->studentID;
}

string Student::getFirstName()
{
  return this->firstName;
}

string Student::getLastName()
{
  return this->lastName;
}

string Student::getEmailAddress()
{
  return this->emailAddress;
}

int Student::getAge()
{
  return this->age;
}

int *Student::getDaysInCourse()
{
  return this->daysInCourse;
}

DegreeProgram Student::getDegreeProgram()
{
  return this->degreeProgram;
}

// Setters
void Student::setStudentID(string studentID)
{
  this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
  this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
  this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
  this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
  this->age = age;
}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3)
{
  this->daysInCourse[0] = daysInCourse1;
  this->daysInCourse[1] = daysInCourse2;
  this->daysInCourse[2] = daysInCourse3;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
  this->degreeProgram = degreeProgram;
}

// Print student information
void Student::print()
{
  const std::string degreeProgramStrings[] = {"SECURITY", "NETWORK", "SOFTWARE"};
  cout << left << setw(5) << this->studentID << setw(10) << this->firstName << setw(10) << this->lastName << setw(5) << this->age <<  "{" << (this->daysInCourse[0])<< ", " << (this->daysInCourse[1]) << ", " << (this->daysInCourse[2]) << "}"  << "   " << degreeProgramStrings[this->degreeProgram] <<  endl;
}
