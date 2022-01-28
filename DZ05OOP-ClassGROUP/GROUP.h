#pragma once
#include "AllLibraries.h"
#include "Student.h"
#include "Date.h"

class GROUP
{
	Student** student = nullptr;
	unsigned int GroupCount = 0; // number of students in a group
	char* GroupName = nullptr; // group name
	char* GroupDirection = nullptr; // group specialization
	unsigned int GroupCourse = 101; // course number

public:
	GROUP(); // К-ТОР по умолчанию
	GROUP(unsigned int GroupCount); // C-TOR with an arbitrary number of students
	GROUP(const GROUP& original); // C-TOP copies of the group
	~GROUP(); // D-TOP

	void SetGroupCount(unsigned int GroupCount); // Setter to enter the number of people in the group
	void SetGroupName(const char* GroupName); // Setter for entering the group name
	void SetGroupDirection(const char* GroupDirection); // Setter on input group specialization
	void SetGroupCourse(unsigned int GroupCourse); // Setter to enter course number

	unsigned int GetGroupCount() const; // Geter to display the number of people in the group
	string GetGroupName() const; // Geter for displaying the group name
	string GetGroupDirection() const; // Geter on conclusion specialization of the group
	unsigned int GetGroupCourse() const; // Geter to output course number

	void ShowGroup(); // Show all students in a group
	void PushStudent(Student* s); // Adding a student to a group
	void SortStudent(); // Sorting students by last name
};
