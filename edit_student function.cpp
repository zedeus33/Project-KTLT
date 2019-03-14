void STUDENT::editStudentID()
{
	cout << "Edit Student ID:";
	cin >> StudentID;
}

void STUDENT::editLastName()
{
	cout << "Edit Last Name: ";
	cin.ignore();
	getline(cin, lastname);
}

void STUDENT::editFirstName()
{
	cout << "Edit First Name: ";
	cin >> firstname;
}

void STUDENT::editGender()
{
	cout << "Edit Gender (0: Male 1: Female): ";
	cin >> gender;
}

void STUDENT::editDoB()
{
	cout << "Edit Day: ";
	cin >> DoB.day;
	cout << "Edit Month";
	cin >> DoB.month;
	cout << "Edit Year";
	cin >> DoB.year;
}

void STUDENT::editIndex()
{
	cout << "Edit Index: ";
	cin >> index;
}