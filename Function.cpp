#include "Header.h"

bool loaddata(const char *path, STUDENT *&dest, int &n) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return false;
	n = 0;
	string firstline;
	getline(fin, firstline);
	while (!fin.eof()) {
		STUDENT a;
		string temp;
		getline(fin, temp, ',');
		a.No = stoi(temp);
		getline(fin, temp, ',');
		a.StudentID = stoi(temp);
		getline(fin, a.lastname, ',');
		getline(fin, a.firstname, ',');
		getline(fin, temp, ',');
		a.gender = temp != "Male";
		getline(fin, temp, '/');
		a.DoB.day = stoi(temp);
		getline(fin, temp, '/');
		a.DoB.month = stoi(temp);
		getline(fin, temp, '\r');
		a.DoB.year = stoi(temp);
		getline(fin, temp, '\n');
		init(dest, a, n);
	}
	fin.close();
	return true;
}

void init(STUDENT *&dest, STUDENT a, int &n)
{
	auto *newdest = new STUDENT[n + 1];
	for (size_t i = 0; i < n; i++) {
		newdest[i] = dest[i];
	}
	delete[] dest;
	newdest[n].No = a.No;
	newdest[n].index = a.index;
	newdest[n].firstname = a.firstname;
	newdest[n].lastname = a.lastname;
	newdest[n].gender = a.gender;
	newdest[n].StudentID = a.StudentID;
	newdest[n].DoB = a.DoB;
	dest = newdest;
	n++;
}

bool savedata(const char *path, STUDENT *&a, int n) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
		return false;
	fout << n << endl;
	for (int i = 0; i < n; i++) {
		fout << a[i].StudentID << " " << a[i].lastname << " " << a[i].firstname << " " << a[i].gender << " "
			<< a[i].DoB.day << "/" << a[i].DoB.month << "/" << a[i].DoB.year << endl;
	}
	fout.close();
	return true;
	//No,StudentID,Lastname,Firstname,Gender,DoB

}

void STUDENT::output() {
	cout << No << "\n\tSTUDENT: " << lastname << " " << firstname << endl;
	cout << "STUDENTID: " << StudentID << endl;
}

void menu() {
	char one = getchar();
	system("cls");
	cout << "1.Log in" << endl;
	cout << "2.Exit" << endl;
	cout << "\t\tEnter number : ";
	char ans;
	cin >> ans;
	switch (ans) {
	case '1':
	{
		system("cls");
		string id;
		string password;
		choquyen:
		inputIDPassword(id, password);
		bool LandSPass = outputPassword("D:/resoures/Project2_18CLC6_Students.txt", "D:/resoures/Password_18CLC6_Students.txt");
		

		
			
			if (LandSPass)
			{
				if (id[0] == 's') {
					system("cls");
					staff(id);
				}
				else if (id[0] == 'l') {
					system("cls");
					lecture(id);
				}
				else if (id[0] == '1') {
					system("cls");
					LandSPass = login_student(id, password, "D:/resoures/Password_18CLC6_Students.txt");
					if (LandSPass)
					{
						student(id);
					}
					else
					{
						cout << "Wrong id!! Please try again" << endl;
						goto choquyen;
					}
					
				}
				else
				{
					system("cls");
					
					system("pause");
					goto choquyen;
				}
			}		
		
	}
			  break;
	case '2': {
		system("cls");
		cout << "Goodbye, Have a nice day!" << endl;
		char two = getchar();
		cout << "Press any key to exit!";
		exit(0);
	}
			  break;
	default:
	{
		system("cls");
		cout << "Wrong input! Please try again" << endl;
		system("pause");
		menu();
	}
		
	}
}

void staff(string id) {
	system("cls");
	cout << "Welcome " << id << endl;
	cout << "\n[0] View profile info" << endl;
	cout << "\n[1] Class" << endl;
	cout << "\n[2] Courses" << endl;
	cout << "\n[3] Scoreboard" << endl;
	cout << "\n[4] Attendance list" << endl;
	cout << "\n[5] Logout" << endl;
	char userOption;

	cout << "\nEnter your choice : ";
	cin >> userOption;
	switch (userOption) {
		case '0':
		{
			system("cls");
			cout << "***View profile info***";
			Continue(id);
		}
		case '1': {
			system("cls");
			cout << "***Class***";
			char staffans;
			menuClass(staffans,id);
			Continue(id);

		}
				  break;
		case '2': {
			system("cls");
			cout << "***Courses***";
			Continue(id);
		}
				  break;
		case '3': {
			system("cls");
			cout << "***Scoreboard***";
			Continue(id);
		}
				  break;
		case '4': {
			system("cls");
			cout << "***Attendance list***";
			Continue(id);
		}break;
		case '5': {
			system("cls");
			id = "";
			menu();
		}

	}
}

void lecture(string id) {
	cout << "Welcome " << id << endl;
	Continue(id);
}

void student(string id) {
	cout << "Welcome " << id << endl;
	system("pause");
	Continue(id);
}


void Continue(string id) {
	cout << "\nDo you want to continued?(yes/no) ";
	string YesorNo;
	cin >> YesorNo;
	if (YesorNo == "yes") {
		if (id[0] == 's') {
			system("cls");
			staff(id);
		}
		else if (id[0] == 'l') {
			system("cls");
			lecture(id);
		}
		else if (id[0] == '1') {
			system("cls");
			student(id);
		}	
	}
	else 
	{
			system("cls");

			cout << "Goodbye, Have a nice day!" <<endl;
			system("pause");
			exit(0);
	}
}
void menuClass(char &n, string id)
{
	
	cout << "\n[1].Import students of a class." << endl;
	cout << "\n[2].Add a new student to a class." << endl;
	cout << "\n[3].Edit an existing student." << endl;
	cout << "\n[4].Remove a student." << endl;
	cout << "\n[5].Change students from class A to class B." << endl;
	cout << "\n[6].View list of classes." << endl;
	cout << "\n[7].View list of student in a class." << endl;
	cout << "\n[8].Return" << endl;
	cout << "Enter your choice : ";
	cin >> n;
	switch (n)
	{
		case '1':
		{
			int N = 0;
			STUDENT *p = new STUDENT[N];			
			bool ans = loaddata("D:/resoures/Project2_18CLC1_Students.csv", p, N);
			if (ans)
			{
				ans = savedata("D:/resoures/Project2_18CLC1_Students.txt", p, N);
				if (ans) {
					cout << "Load Project2_18CLC1_Students and save to Project2_18CLC1_Students.txt successfully!" << endl;
				}
				else
				{
					cout << "Can't load data!! Please try again!" << endl;
					system("pause");
				}
			}
			
			ContinueStaff(n, id);
		}break;
		case '2':
		{
			
		}break;
		case '3':
		{

		}break;
		case '4':
		{

		}break;
		case '5':
		{

		}break;
		case '6':
		{

		}break;
		case '7':
		{

		}break;
		case '8':
		{
			system("cls");
			staff(id);
		}
	}
}
void ContinueStaff(char n, string id)
{
	cout << "\nDo you want to continue?(yes/no)";
	string YesorNo;
	cin >> YesorNo;
	if (YesorNo == "yes")
	{
		system("cls");
		menuClass(n,id);
	}
	else
	{
		staff(id);
	}
}
bool outputPassword(const char *pathInput, const char *pathOutput)
{
	ifstream fileInput;
	fileInput.open(pathInput);
	if (!fileInput.is_open())
		return false;
	int n;
	fileInput >> n;
	int *id = new int[n];

	int *password = new int[n];
	Date DoB;
	char temp;
	for (int i = 0; i < n; i++)
	{
		fileInput >> id[i];
		do
		{
			fileInput >> temp;
		} while (temp != '1' && temp != '0');
		fileInput.ignore();
		fileInput >> DoB.day;
		fileInput.ignore();
		fileInput >> DoB.month;
		fileInput.ignore();
		fileInput >> DoB.year;
		fileInput.ignore();
		password[i] = DoB.year * 10000 + DoB.day * 100 + DoB.month;
		password[i] = (id[i] % 10000) * 10000 + (password[i] % 10000);
	}
	fileInput.close();

	ofstream fileOutput;
	fileOutput.open(pathOutput);
	if (!fileOutput.is_open())
		return false;
	fileOutput << n << endl;
	for (int i = 0; i < n; i++)
	{
		fileOutput << id[i] << "," << password[i] << endl;;
	}
	fileOutput.close();
	return true;

}

bool login_student(string &account, string &password, const char *path)
{
	ifstream fout;
	fout.open(path);
	int aos; /*aos: Amount of student,lecture*/
	string id, pw;
	fout >> aos;
	fout.seekg(3);
	for (int i = 0; i < aos; i++)
	{
		getline(fout, id, ',');
		getline(fout, pw, '\n');
		if (id == account && pw == password)
		{
			return true;
		}
	}
	return false;
}
void inputIDPassword(string &id, string &password)
{
	cout << "Please enter your id : ";
	cin >> id;
	cout << "\nPlease enter your password : ";
	cin >> password;

	while (id.size() >= 10 || password.size() >= 10 || (id.size() >= 10 && password.size() >= 10))
	{
		system("cls");
		cout << "Your account or password has a maximum of 9 characters. Please try again!" << endl;

		cout << "Please enter your id : ";

		cin >> id;
		cout << "\nPlease enter your password : ";

		cin >> password;
	}
}