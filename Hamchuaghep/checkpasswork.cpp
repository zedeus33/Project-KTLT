#include "iostream"
#include "conio.h"
#include "fstream"
#include "string"
using namespace std;

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
		getline(fout,id,',');
		getline(fout,pw,'\n');
		if (id == account && pw==password)
		{
			return true;
		}
	}
	return false;
}