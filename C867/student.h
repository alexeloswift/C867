//
//  student.h
//  C867
//
//  Created by Alexis Diaz on 1/16/23.
//

#ifndef student_h
#define student_h
#include <stdio.h>
#include "degree.h"

using namespace std;

class Student
{
public:
//  MARK: - Variables

  string studentID;
  string firstName;
  string lastName;
  string emailAddress;
  int age;
  int daysInCourse[3];
  DegreeProgram degreeProgram;

// MARK: - Student Object Constructor

  /// Constructor
  /// - Parameters:
  ///   - studentID: The new student id
  ///   - firstName: first name
  ///   - lastName: last name
  ///   - emailAddress: email
  ///   - age: age
  ///   - daysInCourse1: # of days
  ///   - daysInCourse2: # of days
  ///   - daysInCourse3: # of days
  ///   - degreeProgram: students degree program
  Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

//  MARK: - Methods

  /// This method prints student object data
  void print();

//  Getters

  /// This method returns the student id
  string getStudentID();
  /// this method returns the student first name
  string getFirstName();
  /// This method returns the student last name
  string getLastName();
  /// This method returns the student email
  string getEmailAddress();
  /// This method returns the student age
  int getAge();
  /// This method returns an array of days in course
  int *getDaysInCourse();
  /// This method return s the student degree program
  DegreeProgram getDegreeProgram();
  
// Setters

  /// This method allows us to modify an existing student object id
  /// - Parameter studentID: The id to be modified
  void setStudentID(string studentID);
  /// This method allows us to modify an existing student object first name
  /// - Parameter firstName: The first name to be modified
  void setFirstName(string firstName);
  /// This method allows us to modify an existing student object last name
  /// - Parameter lastName: The last name to be modified
  void setLastName(string lastName);
  /// This method allows us to modify an existing student object email
  /// - Parameter emailAddress: The email to be modified
  void setEmailAddress(string emailAddress);
  /// This method allows us to modify an existing student object age
  /// - Parameter age: The age to be modified
  void setAge(int age);
  /// This method allows us to modify an existing student object days in course array
  /// - Parameters:
  ///   - daysInCourse1: first days in course
  ///   - daysInCourse2: second days in course
  ///   - daysInCourse3: third days in course
  void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
  /// This method allows us to modify an existing student object degree program
  /// - Parameter degreeProgram: The degree program to be modified
  void setDegreeProgram(DegreeProgram degreeProgram);
};

#endif /* student_h */
