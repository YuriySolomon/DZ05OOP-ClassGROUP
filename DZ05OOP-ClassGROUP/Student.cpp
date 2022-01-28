#include "Student.h"

Student::Student() : Student("Ivan", "Didenko", "Vladimirovich", "st. Dacha kovalevskogo 131", "+38 (097) 123-45-67") {}

Student::Student(const char* name, const char* surname, const char* phone) : Student(name, surname, "Vladimirovich", "st. Dacha kovalevskogo 131", phone) {}

Student::Student(const char* name, const char* surname, const char* otchestvo, const char* address, const char* phone)
{
	SetName(name);
	SetSurname(surname);
	SetOtchestvo(otchestvo);	
	SetAddress(address);
	SetPhone(phone);	
}

Student::Student(const Student& original)
{
	SetName(original.name);
	SetSurname(original.surname);
	SetOtchestvo(original.otchestvo);	
	SetAddress(original.address);
	SetPhone(original.phone);
}

Student::~Student()
{
	if (name != nullptr) delete[] name;
	if (surname != nullptr) delete[] surname;
	if (otchestvo != nullptr) delete[] otchestvo;
	if (address != nullptr) delete[] address;
	if (phone != nullptr) delete[] phone;
	if (zachot != nullptr) delete[] zachot;
}

void Student::SetName(const char* name) 
{
	if (strlen(name) == 0)
	{
		throw "You didn't enter a student's name!\n";
	}
	delete[] this->name;
	this->name = new char[size];
	strcpy_s(this->name, size - 1, name);
}

void Student::SetSurname(const char* surname) 
{
	if (strlen(surname) == 0)
	{
		throw "You did not enter a student's last name!\n";
	}
	delete[] this->surname;
	this->surname = new char[size];
	strcpy_s(this->surname, size - 1, surname);
}

void Student::SetOtchestvo(const char* otchestvo)
{
	if (strlen(otchestvo) == 0)
	{
		throw "You did not enter the student's middle name!\n";
	}
	delete[] this->otchestvo;
	this->otchestvo = new char[size];
	strcpy_s(this->otchestvo, size - 1, otchestvo);
}

void Student::SetBirthday(short day, short month, short year) 
{
	birthday.SetDay(day);
	birthday.SetMonth(month);
	birthday.SetYear(year);
}

void Student::SetAddress(const char* address) 
{
	if (strlen(address) == 0)
	{
		throw "You did not enter a student address!\n";
	}
	delete[] this->address;
	this->address = new char[size];
	strcpy_s(this->address, size - 1, address);
}

void Student::SetPhone(const char* phone) 
{
	if (strlen(phone) == 0)
	{
		throw "You have not entered a student phone number!\n";
	}
	delete[] this->phone;
	this->phone = new char[size];
	strcpy_s(this->phone, size - 1, phone);
}

void Student::SetZachot(const short grade) 
{
	short* temp = new short[zachot_count + 1];
	for (int i = 0; i < zachot_count; i++)
	{
		temp[i] = zachot[i];
	}
	temp[zachot_count] = grade;
	delete[] zachot;
	zachot = temp;
	zachot_count++;	
}

void Student::SetKursach(const short grade) 
{
	short* temp = new short[kursach_count + 1];
	for (int i = 0; i < kursach_count; i++)
	{
		temp[i] = kursach[i];
	}
	temp[kursach_count] = grade;
	delete[] kursach;
	kursach = temp;
	kursach_count++;
} 

void Student::SetExams(const short grade) 
{
	short* temp = new short[exams_count + 1];
	for (int i = 0; i < exams_count; i++)
	{
		temp[i] = exams[i];
	}
	temp[exams_count] = grade;
	delete[] exams;
	exams = temp;
	exams_count++;
}

string Student::GetName() const 
{
	return name;
}

string Student::GetSurname() const 
{
	return surname;
}

string Student::GetOtchestvo() const 
{
	return otchestvo;
}

void Student::GetBirthday() const 
{
	cout << birthday.GetDate() << ":" << birthday.GetMonth() << ":" << birthday.GetYear();
}

string Student::GetAddress() const 
{
	return address;
}

string Student::GetPhone() const 
{
	return phone;
}

void Student::GetZachot() 
{
	for (int i = 0; i < zachot_count; i++)
	{
		cout << zachot[i] << ", ";
	}
}

void Student::GetKursach() 
{
	for (int i = 0; i < kursach_count; i++)
	{
		cout << kursach[i] << ", ";
	}
}

void Student::GetExams() 
{
	for (int i = 0; i < exams_count; i++)
	{
		cout << exams[i] << ", ";
	}
}

void Student::ShowStudent() 
{
	cout << GetName() << "\n";
	cout << GetSurname() << "\n";
	cout << GetOtchestvo() << "\n";
	GetBirthday();
	cout << "\n";
	cout << GetAddress() << "\n";
	cout << GetPhone() << "\n";
	GetZachot();
	cout << "\n";
	GetKursach();
	cout << "\n";
	GetExams();
	cout << "\n";
}
