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
	if (zachot_count != 0)
	{
		for (int i = 0; i < zachot_count; i++)
		{
			cout << zachot[i] << ", ";
		}
		cout << "\n";
	}
	else
	{
		cout << "The student " << surname << " " << name << " has not passed any tests yet\n";
	}
}

void Student::GetKursach()
{
	if (kursach_count != 0)
	{
		for (int i = 0; i < kursach_count; i++)
		{
			cout << kursach[i] << ", ";
		}
		cout << "\n";
	}
	else
	{
		cout << "The student " << surname << " " << name << " has not yet received any marks for the course\n";
	}
}

void Student::GetExams()
{
	if (exams_count != 0)
	{
		for (int i = 0; i < exams_count; i++)
		{
			cout << exams[i] << ", ";
		}
		cout << "\n";
	}
	else
	{
		cout << "The student " << surname << " " << name << " does not have any grades for the exam yet\n";
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

bool Student::DebtorExam()
{
	if (exams_count != 0)
	{
		for (int i = 0; i < exams_count; i++)
		{
			if (exams[i] == 0)
			{
				return true;
			}
		}
	}
	else
	{
		cout << "The student " << surname << " " << name << " does not have any grades for the exam yet\n";
	}
	return false;
}

double Student::AverageZachetScore()
{
	double sum = 0;
	if (zachot_count != 0)
	{
		for (int i = 0; i < zachot_count; i++)
		{
			sum += zachot[i];
		}
		return (sum / zachot_count);
	}
	else
	{
		return 0;
	}
}
double Student::AverageKursachScore()
{
	double sum = 0;
	if (kursach_count != 0)
	{
		for (int i = 0; i < kursach_count; i++)
		{
			sum += kursach[i];
		}
		return (sum / kursach_count);
	}
	else
	{
		return 0;
	}
}
double Student::AverageExamsScore()
{
	double sum = 0;
	if (exams_count != 0)
	{
		for (int i = 0; i < exams_count; i++)
		{
			sum += exams[i];
		}
		return (sum / exams_count);
	}
	else
	{
		return 0;
	}
}

void Student::RandName()
{
	switch (rand() % 10)
	{
	case 1: 
		strcpy_s(name, size - 1, "Anna");
		break;
	case 2: 
		strcpy_s(name, size - 1, "Valentina");
		break;
	case 3: 
		strcpy_s(name, size - 1, "Viktiria");
		break;
	case 4: 
		strcpy_s(name, size - 1, "Taras");
		break;
	case 5: 
		strcpy_s(name, size - 1, "Nikadim");
		break;
	case 6: 
		strcpy_s(name, size - 1, "Petr");
		break;
	case 7: 
		strcpy_s(name, size - 1, "Elena");
		break;
	case 8: 
		strcpy_s(name, size - 1, "Ivan");
		break;
	case 9: 
		strcpy_s(name, size - 1, "Nikolay");
		break;
	default: 
		strcpy_s(name, size - 1, "Sergei");
		break;
	}
}
void Student::RandSurname()
{
	switch (rand() % 10)
	{
	case 1:
		strcpy_s(surname, size - 1, "Didenko");
		break;
	case 2:
		strcpy_s(surname, size - 1, "Romanenko");
		break;
	case 3:
		strcpy_s(surname, size - 1, "Mioglo");
		break;
	case 4:
		strcpy_s(surname, size - 1, "Omelchenko");
		break;
	case 5:
		strcpy_s(surname, size - 1, "Ptrichenko");
		break;
	case 6:
		strcpy_s(surname, size - 1, "Lupu");
		break;
	case 7:
		strcpy_s(surname, size - 1, "Solomon");
		break;
	case 8:
		strcpy_s(surname, size - 1, "Brandner");
		break;
	case 9:
		strcpy_s(surname, size - 1, "Pershko");
		break;
	default:
		strcpy_s(surname, size - 1, "Rodenko");
		break;
	}
}
void Student::RandPhone()
{
	switch (rand() % 10)
	{
	case 1:
		strcpy_s(phone, size - 1, "+38 (097) 321-12-45");
		break;
	case 2:
		strcpy_s(phone, size - 1, "+38 (096) 321-78-89");
		break;
	case 3:
		strcpy_s(phone, size - 1, "+38 (098) 123-87-54");
		break;
	case 4:
		strcpy_s(phone, size - 1, "+38 (050) 159-69-52");
		break;
	case 5:
		strcpy_s(phone, size - 1, "+38 (066) 789-74-85");
		break;
	case 6:
		strcpy_s(phone, size - 1, "+38 (093) 258-45-45");
		break;
	case 7:
		strcpy_s(phone, size - 1, "+38 (091) 753-45-65");
		break;
	case 8:
		strcpy_s(phone, size - 1, "+38 (097) 785-12-45");
		break;
	case 9:
		strcpy_s(phone, size - 1, "+38 (096) 369-78-25");
		break;
	default:
		strcpy_s(phone, size - 1, "+38 (050) 753-42-78");
		break;
	}
}