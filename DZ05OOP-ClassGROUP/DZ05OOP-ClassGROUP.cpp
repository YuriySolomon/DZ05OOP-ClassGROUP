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

	//g1.ShowGroup();
	g1.SortStudent();
	
	cout << "\n";
	g1.ShowGroup();
	cout << "\n";

	GROUP g2;
	g2.SetGroupName("PTR");
	Student s5("Maksim", "Ozinivich", "+38 (097) 321-87-54");
	Student s6("Paraska", "Maksimova", "+38 (097) 321-21-21");
	g2.PushStudent(&s5);
	g2.PushStudent(&s6);
	g2.ShowGroup();
	//g1.TransferStudent(&s4, &g2);
	//g1.TransferStudent(&s3, &g2);
	cout << "\n=========================================== \n";
	
	/*GROUP g3(g1);
	g3.ShowGroup();*/

	/*GROUP g4(2);
	g4.ShowGroup();*/

	/*s1.SetZachot(8);
	s1.SetZachot(9);
	s2.SetZachot(10);
	s2.SetZachot(11);
	s3.SetZachot(11);
	s3.SetZachot(11);
	s4.SetZachot(12);
	s4.SetZachot(12);

	s1.SetKursach(10);
	s2.SetKursach(9);
	s3.SetKursach(11);
	s4.SetKursach(12);

	s1.SetExams(11);
	s1.SetExams(11);
	s2.SetExams(10);
	s2.SetExams(9);
	s3.SetExams(11);
	s3.SetExams(11);
	s4.SetExams(12);
	s4.SetExams(12);
		
	g1.ExpulsionStudent();
	g1.ShowGroup();*/


	/*s1.SetExams(0);
	s2.SetExams(10);
	s3.SetExams(11);
	s4.SetExams(0);
	g1.ExpulsionAllStudent();
	g1.ShowGroup();*/
	
	/*cout << s1.DebtorExam() << "\n";
	cout << s2.DebtorExam() << "\n";
	cout << s3.DebtorExam() << "\n";
	cout << s4.DebtorExam() << "\n";*/

	//.ShowGroup();
	//cout << "\n";
	//g2.SortStudent();
	//g2.ShowGroup();
	/*g1.MergingGroup(&g2);
	g1.ShowGroup();
	cout << "\n";
	g2.ShowGroup();*/

	system("pause >> NULL");
}
