#include "GROUP.h"

int main()
{
	GROUP g1;
	
	Student s1;
	Student s2("Yuriy", "Solomon", "+38 (097) 123-78-45");
	Student s3("Mia", "Brandner", "+38 (097) 123-12-12");
	Student s4("Arcadiy", "Makarov", "+38 (097) 123-89-56");

	g1.PushStudent(&s1);
	g1.PushStudent(&s2);
	g1.PushStudent(&s3);
	g1.PushStudent(&s4);

	g1.ShowGroup();
	g1.SortStudent();
	
	cout << "\n";
	g1.ShowGroup();

	system("pause >> NULL");
}
