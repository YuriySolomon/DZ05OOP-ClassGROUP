#pragma once
#include "AllLibraries.h"
#include "Date.h"

class Student
{
private:
	char* name;
	char* surname;
	char* otchestvo;
	Date birthday;
	char* address;
	char* phone;
	short* zachot = nullptr; // credit grades
	short* kursach = nullptr; // grades for coursework
	short* exams = nullptr; // exam grades
	unsigned short size = 50; // number of characters in arrays
	short zachot_count = 0; // total number of grades per credit
	short kursach_count = 0; // total number of grades per course
	short exams_count = 0; // total number of grades for exams

public:
	Student();
	Student(const char* name, const char* surname, const char* phone);
	Student(const char* name, const char* surname, const char* otchestvo, const char* address, const char* phone);
	Student(const Student& original);
	~Student();
	void SetName(const char* name); // Name setter
	void SetSurname(const char* surname); // Last name setter
	void SetOtchestvo(const char* otchestvo); // Setter for entering middle name
	void SetBirthday(short day, short month, short year);
	void SetAddress(const char* address); // Address setter
	void SetPhone(const char* phone); // Phone number setter
	void SetZachot(const short grade); // Setter for creating credit grades
	void SetKursach(const short grade); // Setter for creating course grades
	void SetExams(const short grade); // Setter for creating grades for exams
	string GetName() const; // Shows student name
	string GetSurname() const; // Shows the last name of the student
	string GetOtchestvo() const; // Shows the student's middle name
	void GetBirthday() const; // Shows student's date of birth
	string GetAddress() const; // Shows student address
	string GetPhone() const; // Shows student phone number
	void GetZachot(); // Shows grades by credits
	void GetKursach(); // Shows course grades
	void GetExams(); // Shows grades for exams
	void ShowStudent(); // Showing all fields of the student object
	bool DebtorExam(); // Return true if there is a debt for at least one exam
	double AverageZachetScore(); // Average score for credits
	double AverageKursachScore(); // Average score for coursework
	double AverageExamsScore(); // Average score for exams
	void RandName(); // Random student name generation
	void RandSurname(); // Random student last name generation
	void RandPhone(); // Random student phone number generation
};

