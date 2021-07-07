#include "Header.h"

int main()
{
	cout << "\t\t***Notice!!!***" << endl;
	cout << "\nI.   IF you are Staff, please insert your ID with s..." << endl;
	cout << "\nII.  If you are Lecture, please insert your ID with l..." << endl;
	cout << "\nIII. If you are Student, please insert your ID with studentID " << endl;
	cout << "\n\nThank you!" << endl;
	cout << "=============================================================="<<endl;
	char userOption = firstMenu();
	secondMenu(userOption);
	return 0;
}


