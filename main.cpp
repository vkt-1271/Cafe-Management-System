#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
#include <conio.h>
#include "MasterEntry.h"
using namespace std;

class MemberEntry : public MasterEntry
{
public:
	MemberEntry()
	{
		int x = display();
		switch (x)
		{
		case 1:
			AddNew();
			break;
		case 2:
			Show();
			break;
		case 3:
			UpdateRecord();
			break;
		case 4:
			DeleteRecord();
			break;
		case 5:
			SearchRecord();
			break;
		case 6:
			// MasterEntry();
			break;
		}
	}
	MemberEntry(int k) {}
	void AddNew()
	{
		int k = 0;
		system("cls");
		MemberEntry obj(0);
		cout << "Enter Id,Name, and Time: " << endl;
		cin >> obj.id;
		fstream p2;
		p2.open("MemberEntry.dat", ios::in | ios::binary);
		MemberEntry obj1(0);
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			if (obj1.id == obj.id)
			{
				cout << "Already exists!" << endl;
				k = 1;
			}
		}
		if (k == 0)
		{
			cin.ignore();
			cin.getline(obj.name, 19);
			cin.getline(obj.time, 9);
			obj.NoOfEntry = 1;
			fstream p1;
			p1.open("MemberEntry.dat", ios::app | ios::binary);
			p1.write((char *)&obj, sizeof(obj));
			p1.close();
		}
		p2.close();
	}

	void UpdateRecord()
	{
		system("cls");
		int x, k = 1;
		cout << "Enter ID:";
		cin >> x;
		fstream p2;
		p2.open("MemberEntry.dat", ios::in | ios::binary);
		MemberEntry obj1(0);
		fstream fout;
		fout.open("new.dat", ios::out | ios::binary);
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			if (obj1.id == x)
			{
				k = 0;
				cout << "Number of Entry Increased by 1" << endl;
				obj1.NoOfEntry++;
			}
			fout.write((char *)&obj1, sizeof(obj1));
		}
		if (k)
		{
			cout << "No Data Found!" << endl;
		}
		p2.close();
		fout.close();
		remove("MemberEntry.dat");
		rename("new.dat", "MemberEntry.dat");
	}
	void DeleteRecord()
	{
		system("cls");
		int x, k = 1;
		cout << "Enter ID:";
		cin >> x;
		fstream p2;
		p2.open("MemberEntry.dat", ios::in | ios::binary);
		MemberEntry obj1(0);
		fstream fout;
		fout.open("new.dat", ios::out | ios::binary);
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			if (obj1.id == x)
			{
				k = 0;
				cout << "Record Deleted" << endl;
			}
			else
			{
				fout.write((char *)&obj1, sizeof(obj1));
			}
		}
		if (k)
		{
			cout << "No Data Found!" << endl;
		}
		p2.close();
		fout.close();
		remove("MemberEntry.dat");
		rename("new.dat", "MemberEntry.dat");
	}
	void SearchRecord()
	{
		system("cls");
		int x, k = 1;
		cout << "Enter ID:";
		cin >> x;
		fstream p2;
		p2.open("MemberEntry.dat", ios::in | ios::binary);
		MemberEntry obj1(0);
		cout << "ID:\tName:\t\tTime:\tNo: Of Entry:" << endl;
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			if (obj1.id == x)
			{
				k = 0;
				cout << obj1.id << "\t" << obj1.name << "\t" << obj1.time << "\t" << obj1.NoOfEntry << endl;
				break;
			}
		}
		if (k)
		{
			cout << "No Data Found!" << endl;
		}
		p2.close();
	}
};
class ComputerEntry : public MasterEntry
{
public:
	ComputerEntry()
	{
		int x = display();
		switch (x)
		{
		case 1:
			AddNew();
			break;
		case 2:
			Show();
			break;
		case 3:
			UpdateRecord();
			break;
		case 4:
			DeleteRecord();
			break;
		case 5:
			SearchRecord();
			break;
		case 6:
			// MasterEntry();
			break;
		}
	}
	ComputerEntry(int k) {}
	void AddNew()
	{
		int k = 0;
		system("cls");
		MemberEntry obj(0);
		cout << "Enter Id,Name, and Time: " << endl;
		cin >> obj.id;
		fstream p2;
		p2.open("ComputerEntry.dat", ios::in | ios::binary);
		ComputerEntry obj1(0);
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			if (obj1.id == obj.id)
			{
				cout << "Already exists!" << endl;
				k = 1;
			}
		}
		if (k == 0)
		{
			cin.ignore();
			cin.getline(obj.name, 19);
			cin.getline(obj.time, 9);
			obj.NoOfEntry = 1;
			fstream p1;
			p1.open("ComputerEntry.dat", ios::app | ios::binary);
			p1.write((char *)&obj, sizeof(obj));
			p1.close();
		}
		p2.close();
	}
	void Show()
	{
		system("cls");
		fstream p2;
		p2.open("ComputerEntry.dat", ios::in | ios::binary);
		ComputerEntry obj1(0);
		cout << "ID:\tName:\t\tTime:\tNo: Of Entry:" << endl;
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			cout << obj1.id << "\t" << obj1.name << "\t" << obj1.time << "\t" << obj1.NoOfEntry << endl;
		}
		p2.close();
	}
	void UpdateRecord()
	{
		system("cls");
		int x, k = 1;
		cout << "Enter ID:";
		cin >> x;
		fstream p2;
		p2.open("ComputerEntry.dat", ios::in | ios::binary);
		ComputerEntry obj1(0);
		fstream fout;
		fout.open("new.dat", ios::out | ios::binary);
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			if (obj1.id == x)
			{
				k = 0;
				cout << "Number of Entry increased by 1" << endl;
				obj1.NoOfEntry++;
			}
			fout.write((char *)&obj1, sizeof(obj1));
		}
		if (k)
		{
			cout << "No Data Found!" << endl;
		}
		p2.close();
		fout.close();
		remove("ComputerEntry.dat");
		rename("new.dat", "ComputerEntry.dat");
	}
	void DeleteRecord()
	{
		system("cls");
		int x, k = 1;
		cout << "Enter ID:";
		cin >> x;
		fstream p2;
		p2.open("ComputerEntry.dat", ios::in | ios::binary);
		ComputerEntry obj1(0);
		fstream fout;
		fout.open("new.dat", ios::out | ios::binary);
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			if (obj1.id == x)
			{
				k = 0;
				cout << "Record Deleted" << endl;
			}
			else
			{
				fout.write((char *)&obj1, sizeof(obj1));
			}
		}
		if (k)
		{
			cout << "No Data Found!" << endl;
		}
		p2.close();
		fout.close();
		remove("ComputerEntry.dat");
		rename("new.dat", "ComputerEntry.dat");
	}
	void SearchRecord()
	{
		system("cls");
		int x, k = 1;
		cout << "Enter ID:";
		cin >> x;
		fstream p2;
		p2.open("ComputerEntry.dat", ios::in | ios::binary);
		ComputerEntry obj1(0);
		cout << "ID:\tName:\t\tTime:\tNo: Of Entry:" << endl;
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			if (obj1.id == x)
			{
				k = 0;
				cout << obj1.id << "\t" << obj1.name << "\t" << obj1.time << "\t" << obj1.NoOfEntry << endl;
				break;
			}
		}
		if (k)
		{
			cout << "No Data Found!" << endl;
		}
		p2.close();
	}
};

class CafeManagement : public MasterEntry
{
	int time1;
	float price;

public:
	CafeManagement()
		: price(100)
	{
		int x = display();
		switch (x)
		{
		case 1:
			AddNew();
			break;
		case 2:
			Show();
			break;
		case 3:
			UpdateRecord();
			break;
		case 4:
			DeleteRecord();
			break;
		case 5:
			SearchRecord();
			break;
		case 6:
			// MasterEntry();
			break;
		}
	}

	CafeManagement(int k) : price(100)
	{
		strcpy(time, "null");
		NoOfEntry = 0;
		time1 = 0;
	}
	void AddNew()
	{
		system("cls");
		int k = 0;
		CafeManagement obj(0);
		cout << "Enter Id,Name, and Time in hours: " << endl;
		cin >> obj.id;
		fstream p2;
		p2.open("Booking.dat", ios::in | ios::binary);
		CafeManagement obj1(0);
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			if (obj1.id == obj.id)
			{
				cout << "Already exists!" << endl;
				k = 1;
			}
		}
		if (k == 0)
		{
			cin.ignore();
			cin.getline(obj.name, 19);
			strcpy(obj.time, "null");
			cin >> obj.time1;
			obj.NoOfEntry = 0;
			fstream p1;
			p1.open("Booking.dat", ios::app | ios::binary);
			p1.write((char *)&obj, sizeof(obj));
			p1.close();
		}
		p2.close();
	}
	void Show()
	{
		system("cls");
		fstream p2;
		p2.open("Booking.dat", ios::in | ios::binary);
		CafeManagement obj1(0);
		cout << "ID:\tName:\t\tTime:\tPrice: " << endl;
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			cout << obj1.id << "\t" << obj1.name << "\t" << obj1.time1 << "\t" << obj1.time1 * obj1.price << endl;
		}
		p2.close();
	}
	void UpdateRecord()
	{
		system("cls");
		int x, k = 1;
		cout << "Enter ID:";
		cin >> x;
		fstream p2;
		p2.open("Booking.dat", ios::in | ios::binary);
		CafeManagement obj1(0);
		fstream fout;
		fout.open("new.dat", ios::out | ios::binary);
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			if (obj1.id == x)
			{
				k = 0;
				cout << "Number new time:" << endl;
				cin >> obj1.time1;
			}
			fout.write((char *)&obj1, sizeof(obj1));
		}
		if (k)
		{
			cout << "No Data Found!" << endl;
		}
		p2.close();
		fout.close();
		remove("Booking.dat");
		rename("new.dat", "Booking.dat");
	}
	void DeleteRecord()
	{
		system("cls");
		int x, k = 1;
		cout << "Enter ID:";
		cin >> x;
		fstream p2;
		p2.open("Booking.dat", ios::in | ios::binary);
		CafeManagement obj1(0);
		fstream fout;
		fout.open("new.dat", ios::out | ios::binary);
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			if (obj1.id == x)
			{
				k = 0;
				cout << "Record Deleted" << endl;
			}
			else
			{
				fout.write((char *)&obj1, sizeof(obj1));
			}
		}
		if (k)
		{
			cout << "No Data Found!" << endl;
		}
		p2.close();
		fout.close();
		remove("Booking.dat");
		rename("new.dat", "Booking.dat");
	}
	void SearchRecord()
	{
		system("cls");
		int x, k = 1;
		cout << "Enter ID:";
		cin >> x;
		fstream p2;
		p2.open("Booking.dat", ios::in | ios::binary);
		CafeManagement obj1(0);
		cout << "ID:\tName:\t\tTime:\tPrice:" << endl;
		while (p2.read((char *)&obj1, sizeof(obj1)) != NULL)
		{
			if (obj1.id == x)
			{
				k = 0;
				cout << obj1.id << "\t" << obj1.name << "\t" << obj1.time1 << "\t" << obj1.time1 * obj1.price << endl;
				break;
			}
		}
		if (k)
		{
			cout << "No Data Found!" << endl;
		}
		p2.close();
	}
};

void End()
{
	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
	cout << "\t\t\t\t\xB2\xB2    \t\t\t\t       \xB2\xB2\n";
	cout << "\t\t\t\t\xB2\xB2   THANK-YOU FOR USING THIS $YSTEM.  \xB2\xB2\n";
	cout << "\t\t\t\t\xB2\xB2     \t\t\t\t       \xB2\xB2";
	cout << "\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
	cout << "\n\n\n\n\n\n";
	exit(0);
}
int choice(int x)
{
	char choise;
	fflush(stdin);
	cin >> choise;
	while (choise < '1' || choise > '1' + x - 1)
	{
		cout << "\n\t\tWrong Choice!\n\n";
		cout << "\n\t\tEnter your choice : ";
		fflush(stdin);
		cin >> choise;
	}
	return choise - '0';
}
int Menu()
{
	system("cls");
	cout << "\n\n\t\t\t\t-----------------------------------------------" << endl;
	cout << "\t\t\t\t Welcome To The \"CYBER CAFE\" Management System" << endl;
	cout << "\t\t\t\t-----------------------------------------------" << endl;
	cout << "\t\t\t\t \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\ \n\n\n";
	cout << "\t\t\t\t\t1-> Master Entry\n\n";
	cout << "\t\t\t\t\t2-> Cafe Management\n\n";
	cout << "\t\t\t\t\t3-> Exit\n\n\n\n";
	cout << "\n__________________________\n";
	cout << "\n\tEnter your choice : ";
	int x = choice(3);
	if (x == 1)
	{
		system("cls");
		cout << "\n\t\t\t****************************\n";
		cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1\n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1 1-> Member Entry  \n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1\n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1 2-> Computer Entry  \n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1\n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1 3-> Return  \n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1  ";
		cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
		cout << "\t\t\t";
		cout << "\n__________________________\n";
		cout << "\n\tEnter your choice : ";
		x = choice(3);
		switch (x)
		{
		case 1:
		{
			MemberEntry obj;
			getch();
			Menu();
		}
		break;
		case 2:
		{
			ComputerEntry obj;
			getch();
			Menu();
		}
		break;
		case 3:
			Menu();
			break;
		}
	}
	else if (x == 2)
	{
		system("cls");
		cout << "\n\t\t\t****************************\n";
		cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1\n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1 1-> Booking  \n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1\n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1 2-> Charges  \n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1\n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1 3-> Return  \n";
		cout << "\t\t\t\xB2\xB2\xB1\xB1\n";
		cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
		cout << "\t\t\t";
		cout << "\n__________________________\n";
		cout << "\n\tEnter your choice : ";
		x = choice(3);
		switch (x)
		{
		case 1:
		{
			CafeManagement obj;
			getch();
			Menu();
		}
		break;
		case 2:
		{
			CafeManagement obj(0);
			obj.SearchRecord();
			getch();
			Menu();
		}
		break;
		case 3:
			Menu();
			break;
		}
	}
	else if (x == 3)
	{
		End();
	}
}
int main()
{
	Menu();
}
