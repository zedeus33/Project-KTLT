#include "Header.h"
void menu()
{
	char one = getchar();
	system("cls");
	cout << "1.Log in" << endl;
	cout << "2.Exit" << endl;
	cout << "\t\tEnter number : ";
	int ans;
	cin >> ans;
	switch (ans)
	{
	case 1:
	{
		system("cls");
		char id[50];
		char password[50];
		cout << "Please enter your id : ";
		cin >> id;
		cout << "\nPlease enter your password : ";
		cin >> password;
		int l1 = strlen(id);
		int l2 = strlen(password);
		while (l1 >= 10 || l2 >= 10 || (l1 >= 10 && l2 >= 10))
		{
			system("cls");
			cout << "Your account or password has a maximum of 9 characters. Please try again!" << endl;

			cout << "Please enter your id : ";

			cin >> id;
			cout << "\nPlease enter your password : ";

			cin >> password;
			l1 = strlen(id);
			l2 = strlen(password);
		}
		if (id[0] == 's')
		{
			system("cls");
			staff(id);
		}
		else if (id[0] == 'l')
		{
			system("cls");
			lecture(id);
		}
		else if (id[0] == '1')
		{
			system("cls");
			student(id);
		}
	}break;
	case 2:
	{
		system("cls");
		cout << "Goodbye, Have a nice day!" << endl;
		char two = getchar();
		cout << "Press any key to exit!";
	}break;
	default:
		break;
	}
}
void staff(char id[])
{
	system("cls");
	cout << "Welcome " << id << endl;
	cout << "\n1.Scoreboard" << endl;
	cout << "\n2.Courses" << endl;
	cout << "\n3.Class" << endl;
	cout << "\n4.Attendance list" << endl;
	cout << "\n5.Log out" << endl;
	int ans1;

	cout << "\nEnter your choice : ";
	cin >> ans1;
	switch (ans1)
	{
		case 1:
		{
			system("cls");
			cout << "***Scoreboard***";
			cout << "\nDo you want to continued?(y/n) ";
			char b[10];
			cin >> b;
			if (strcmp(b, "y") == 0)
				staff(id);
			else
				system("cls");
			cout << "Goodbye, Have a nice day!" << endl;

		}break;
		case 2:
		{
			system("cls");
			cout << "***Courses***";
			char b[10];
			cin >> b;
			if (strcmp(b, "y") == 0)
				staff(id);
			else
				system("cls");
			cout << "Goodbye, Have a nice day!" << endl;
		}break;
		case 3:
		{
			system("cls");
			cout << "***Class***";
			char b[10];
			cin >> b;
			if (strcmp(b, "y") == 0)
				staff(id);
			else
				system("cls");
			cout << "Goodbye, Have a nice day!" << endl;

		}break;
		case 4:
		{
			system("cls");
			cout << "***Attendance list***";
			char b[10];
			cin >> b;
			if (strcmp(b, "y") == 0)
				staff(id);
			else
				system("cls");
			cout << "Goodbye, Have a nice day!" << endl;
		}break;
		case 5:
		{
			menu();
		}

	}
}
void lecture(char id[])
{
	cout << "Welcome " << id << endl;

}
void student(char id[])
{
	cout << "Welcome " << id << endl;

}