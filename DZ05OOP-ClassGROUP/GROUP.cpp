#include "GROUP.h"

GROUP::GROUP() : GROUP(0)
{
	//cout << "C-TOR \n";
}
GROUP::GROUP(unsigned int GroupCount)
{
	//cout << "C-TOR Par\n";
	SetGroupCount(GroupCount);
	SetGroupName("SPU");
	SetGroupDirection("Programmer");
	SetGroupCourse(1);
}

GROUP::GROUP(const GROUP& original)
{
	cout << "C-TOR Copy\n";
}
GROUP::~GROUP()
{
	if (student != nullptr) delete[] student;
	if (GroupDirection != nullptr) delete[] GroupDirection;
	if (GroupName != nullptr) delete[] GroupName;
}

void GROUP::SetGroupCount(unsigned int GroupCount)
{
	if (GroupCount < 0 || GroupCount > 20)
	{
		throw "Incorrect course number entered";
	}
	this->GroupCount = GroupCount;
}
void GROUP::SetGroupName(const char* GroupName)
{
	if (strlen(GroupName) == 0)
	{
		throw "You did not enter a group name\n";
	}
	int size = strlen(GroupName);
	delete[] this->GroupName;
	this->GroupName = new char[++size];
	strcpy_s(this->GroupName, size, GroupName);
}
void GROUP::SetGroupDirection(const char* GroupDirection)
{
	if (strlen(GroupDirection) == 0)
	{
		throw "You have not entered a group specialization\n";
	}
	int size = strlen(GroupDirection);
	delete[] this->GroupDirection;
	this->GroupDirection = new char[++size];
	strcpy_s(this->GroupDirection, size, GroupDirection);
}
void GROUP::SetGroupCourse(unsigned int GroupCourse)
{
	if (GroupCourse < 0 || GroupCourse > 6)
	{
		throw "Incorrect course number entered";
	}
	this->GroupCourse = GroupCourse;
}

unsigned int GROUP::GetGroupCount() const
{
	return GroupCount;
}
string GROUP::GetGroupName() const
{
	return GroupName;
}
string GROUP::GetGroupDirection() const
{
	return GroupDirection;
}
unsigned int GROUP::GetGroupCourse() const
{
	return GroupCourse;
}

void GROUP::ShowGroup()
{
	cout << "Group: " << GetGroupName() << "\n";
	cout << "Direction: " << GetGroupDirection() << "\n";
	if (GroupCount != 0)
	{
		cout << "\nStudents in a group: \n";
	}
	for (int i = 0; i < GroupCount; i++)
	{
		cout  << (i + 1) << " - " << student[i]->GetSurname() << " " << student[i]->GetName() << "\n";
	}
	
}

void GROUP::PushStudent(Student* s)
{	
	Student** temp = new Student * [GroupCount + 1];
	for (int i = 0; i < GroupCount; i++)
	{
		temp[i] = student[i];
	}
	temp[GroupCount] = s;
	delete[] student;
	student = temp;
	GroupCount++;
}

void GROUP::SortStudent()
{
	Student** temp = new Student * [GroupCount];
	for (int i = 0; i < GroupCount - 1; i++)
	{
		for (int j = 0; j < GroupCount - i - 1; j++)
		{
			if (student[j]->GetSurname() > student[j + 1]->GetSurname())
			{
				temp[j] = student[j];
				student[j] = student[j + 1];
				student[j + 1] = temp[j];
			}
		}		
	}
}