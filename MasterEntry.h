#ifndef HEADER_FILE
#define HEADER_FILE

#include <iostream>
using namespace std;

class MasterEntry
{
	public:
	int id;
	char name[20];
	char time[10];
	int NoOfEntry;
	
	virtual void AddNew()=0;
	virtual void Show()=0;
	virtual void UpdateRecord()=0;
	virtual void DeleteRecord()=0;
	virtual void SearchRecord()=0;
	int display()
	{
		system("cls");
		cout<<"\n\t\t\t****************************\n";	
		cout<<"\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
		cout<<"\t\t\t\xB2\xB2\xB1\xB1\n";
		cout<<"\t\t\t\xB2\xB2\xB1\xB1 1-> Add New   \n";
		cout<<"\t\t\t\xB2\xB2\xB1\xB1\n";
		cout<<"\t\t\t\xB2\xB2\xB1\xB1 2-> Show   \n";
		cout<<"\t\t\t\xB2\xB2\xB1\xB1\n";
		cout<<"\t\t\t\xB2\xB2\xB1\xB1 3-> Update Record  \n";
		cout<<"\t\t\t\xB2\xB2\xB1\xB1\n";
		cout<<"\t\t\t\xB2\xB2\xB1\xB1 4-> Delete Record  \n";
		cout<<"\t\t\t\xB2\xB2\xB1\xB1\n";
		cout<<"\t\t\t\xB2\xB2\xB1\xB1 5-> Search Record  \n";
		cout<<"\t\t\t\xB2\xB2\xB1\xB1\n";
		cout<<"\t\t\t\xB2\xB2\xB1\xB1 6-> Return  \n";	
		cout<<"\t\t\t\xB2\xB2\xB1\xB1  ";
		cout<<"\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
		cout<<"\t\t\t";
		cout<<"\n__________________________\n";
		cout<<"\n\tEnter your choice : ";
		char choise;
		fflush(stdin);
		cin>>choise;
		while(choise<'1' || choise>'1'+6-1)
		{
			cout<<"\n\t\tWrong Choice!\n\n";
			cout<<"\n\t\tEnter your choice : ";
			fflush(stdin);
			cin>>choise;
		}
		return choise-'0';
	}
};



#endif