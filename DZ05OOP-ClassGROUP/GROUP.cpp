#include "GROUP.h"

GROUP::GROUP() : GROUP(1)
{
	cout << "C-TOR \n";
}
GROUP::GROUP(unsigned int GroupCount)
{
	cout << "C-TOR Par\n";
	SetGroupCount(GroupCount);
	/*SetGroupName(GroupName);
	SetGroupDirection(GroupDirection);
	SetGroupCourse(GroupCourse)*/;
}
GROUP::GROUP(const GROUP& original)
{
	cout << "C-TOR Copy\n";
}
GROUP::~GROUP()
{
	cout << "D-TOR \n";
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
	//cout << "size = " << size << "\n";
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
	if (GroupCourse < 0 || GroupCourse > 1000)
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
	cout << GetGroupCount() << "\n";
	/*cout << GetGroupName() << "\n";
	cout << GetGroupDirection() << "\n";
	cout << GetGroupCourse() << "\n";*/
}

void GROUP::PushStudent()
{
	GroupCount++;
	Student** temp = new Student * [GroupCount];
	for (int i = 0; i < GroupCount; i++)
	{
		temp[i] = student[i];
	}
	//Student* stud = new Student();

}