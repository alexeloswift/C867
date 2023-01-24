//
//  roster.h
//  C867
//
//  Created by Alexis Diaz on 1/16/23.
//

#ifndef roster_h
#define roster_h
#include <stdio.h>
#include "student.h"
#include "degree.h"

using namespace std;

class Roster {
  
  //  MARK: - Private Properties

private:

  Student** classRosterArray; // Pointer to array of pointers to Student objects
  int lastIndex; // Last occupied index in classRosterArray
  int capacity; // Maximum size of classRosterArray
  
  // MARK: - Roster Object Constructor & Destructor

public:
  
  /// Constructor
  Roster();
  /// Destructor
  ~Roster();
  
  //  MARK: - Methods
  
  /// Parse array of student data strings
  /// - Parameter array: The array of data that will be parsed
  void parse(const string studentData[]);
  /// Add a student to the roster
  /// - Parameters:
  ///   - studentID: id to be added
  ///   - firstName: first name to be added
  ///   - lastName: last name to be added
  ///   - emailAddress: email to be added
  ///   - age: age to be added
  ///   - daysInCourse1: # of days to be added
  ///   - daysInCourse2: # of days to be added
  ///   - daysInCourse3: # of days to be added
  ///   - degreeProgram: degree to be added
  void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
  /// Remove a student from the roster
  /// - Parameter studentID: The id of the student that needs to be removed
  void removeStudent(string studentID);
  /// Print all students in the roster
  void printAll();
  /// Print all invalid email addresses
  void printInvalidEmails();
  /// Print all students in a specific degree program
  /// - Parameter degreeProgram: the degree program that youre looking for
  void printByDegreeProgram(DegreeProgram degreeProgram);
  /// Print the average number of days in a course for a specific student
  /// - Parameter studentID: the id of the student in question
  void printAverageDaysInCourse(string studentID);
  
  //  Helper Methods
  
  /// Get the student ID of a student
  /// - Parameter index: specific index in the roster array
  string getStudentIDAtIndex(int index);
};

#endif /* roster_h */
