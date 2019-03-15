void STUDENT::add(const char *path, STUDENT *&dest, int &n)
{
	No = n + 1;
	cout << "StudentID: ";
	cin >> StudentID;
	cout << "Gender (0: Male 1: Female): ";
	cin >> gender;
	cout << "First name: ";
	cin >> firstname;
	cout << "Last name: ";
	cin.ignore();
	getline(cin, lastname);
	cout << "Day of birth" << endl;
	cout << "Day: ";
	cin >> DoB.day;
	cout << "Month: ";
	cin >> DoB.month;
	cout << "Year: ";
	cin >> DoB.year;
	cout << "Index:";
	cin >> index;


	ofstream file;
	file.open(path, ios::app);
	file << StudentID << " " << lastname << " " << firstname << " " << gender << " "
		<< DoB.day << "/" << DoB.month << "/" << DoB.year << endl;

	auto *newdest = new STUDENT[n + 1];
	for (size_t i = 0; i < n; i++) {
		newdest[i] = dest[i];
	}
	delete[] dest;
	newdest[n].No = No;
	newdest[n].index = index;
	newdest[n].firstname = firstname;
	newdest[n].lastname = lastname;
	newdest[n].gender = gender;
	newdest[n].StudentID = StudentID;
	newdest[n].DoB = DoB;
	dest = newdest;
	n++;
}

