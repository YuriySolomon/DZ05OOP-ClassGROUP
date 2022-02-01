#include "GROUP.h"

GROUP::GROUP() : GROUP(0)
{
}
GROUP::GROUP(unsigned int GroupCount)
{
	SetGroupCount(GroupCount);
	SetGroupName("SPU");
	SetGroupDirection("Programmer");
	SetGroupCourse(1);	
	for (int i = 0; i < GroupCount; i++)
	{
		//cout << "The developer thinks over the logic of the algorithm.\n";
	}
}

GROUP::GROUP(const GROUP& original)
{
	SetGroupCount(original.GroupCount);
	SetGroupName(original.GroupName);
	SetGroupDirection(original.GroupDirection);
	SetGroupCourse(original.GroupCourse);
	Student** temp = new Student * [original.GroupCount];
	for (int i = 0; i < GroupCount; i++)
	{
		temp[i] = original.student[i];
	}
	delete[] student;
	student = temp;
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
	if (GroupCount == 0)
	{
		cout << "Group " << GetGroupName() << " is empty\n";
		return;
	}
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

void GROUP::RemoveStudent(Student* s)
{
	Student** temp = new Student * [GroupCount - 1];
	bool k = true;
	for (int i = 0; i < GroupCount; i++)
	{
		if (student[i] == s)
		{
			k = false;
		}
		else if (k)
		{
			temp[i] = student[i];
		}
		else
		{
			temp[i - 1] = student[i];
		}
	}
	delete[] student;
	student = temp;
	GroupCount--;
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

void GROUP::TransferStudent(Student* s, GROUP* g)
{
	Student** temp_rem = new Student * [GroupCount - 1];
	Student** temp_add = new Student * [g->GetGroupCount() + 1];
	bool k = true;
	for (int i = 0; i < GroupCount; i++)
	{
		if (student[i] == s) // if (student[i]->GetSurname() == s->GetSurname())
		{
			for (int j = 0; j < g->GetGroupCount(); j++)
			{
				temp_add[j] = g->student[j];
			}
			temp_add[g->GetGroupCount()] = s;
			k = false;
		}
		else if (k)
		{
			temp_rem[i] = student[i];
		}
		else
		{
			temp_rem[i - 1] = student[i];
		}
	}
	delete[] g->student;
	g->student = temp_add;
	g->SetGroupCount(g->GetGroupCount() + 1);
	delete[] student;
	student = temp_rem;
	GroupCount--;	
}

void GROUP::MergingGroup(GROUP* g)
{
	Student** temp = new Student * [GroupCount + g->GetGroupCount()];
	int j = 0;
	for (int i = 0; i < (GroupCount + g->GetGroupCount()); i++)
	{
		if (i < GroupCount)
		{
			temp[i] = student[i];
		}
		else 
		{
			temp[i] = g->student[j];
			j++;
		}		
	}
	delete[] student;
	student = temp;
	GroupCount += g->GetGroupCount();
	g->SetGroupCount(0);
}

void GROUP::ExpulsionStudent()
{
	int num = 0;
	double grade = 0;
	grade = (student[0]->AverageZachetScore() + student[0]->AverageKursachScore() + student[0]->AverageExamsScore()) / 3;
	for (int i = 1; i < GroupCount; i++)
	{
		if (grade > (student[i]->AverageZachetScore() + student[i]->AverageKursachScore() + student[i]->AverageExamsScore()) / 3)
		{
			grade = (student[i]->AverageZachetScore() + student[i]->AverageKursachScore() + student[i]->AverageExamsScore()) / 3;
			num = i;
		}
	}
	RemoveStudent(student[num]);
}

int GROUP::NumberDebtorsExam()
{
	int kol = 0;
	for (int i = 0; i < GroupCount; i++)
	{
		if (student[i]->DebtorExam() == 1)
		{
			kol++;
		}
	}
	return kol;
}

void GROUP::ExpulsionAllStudent()
{
	Student** temp = new Student * [GroupCount - NumberDebtorsExam()];
	int j = 0;
	for (int i = 0; i < GroupCount; i++)
	{		
		if (student[i]->DebtorExam() == true)
		{
			j++;
		}
		else
		{
			temp[i - j] = student[i];
		}
	}
	delete[] student;
	student = temp;
	GroupCount -= j;	
}