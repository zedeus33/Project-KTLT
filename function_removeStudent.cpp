#include "iostream"
#include "conio.h"
#include "fstream"
#include "string"
using namespace std;

bool remove(const char *path, STUDENT *&p, int &n, const int &StudentID)
{
	int gender;
	ifstream fin;
	fin.open(path);
	fin >> n;
	int checkTF = n; //Kiểm tra để biết trả về true hay false
	string temp1, temp;
	fin.ignore();
	for (int i = 0; i < n; i++)
	{
		(p + i)->No = i + 1;
		fin >> (p + i)->StudentID;
		fin.seekg(1, ios::cur);
		getline(fin, (p + i)->lastname, ' ');
		do
		{
			getline(fin, temp, ' ');
			if (temp != "0" && temp != "1")
			{
				temp1 = temp1 + " " + temp;
			}
		} while (temp != "0" && temp != "1");
		temp1.erase(temp1.begin());
		(p + i)->firstname = temp1;
		temp1 = "";
		fin.seekg(-2, ios::cur);
		fin >> gender;
		(p + i)->gender = gender;
		getline(fin, temp, '/');
		(p + i)->DoB.day = stoi(temp);
		getline(fin, temp, '/');
		(p + i)->DoB.month = stoi(temp);
		getline(fin, temp, '\n');
		(p + i)->DoB.year = stoi(temp);
		if ((p + i)->StudentID == StudentID)
		{
			i--;
			n--;
		}
	}
	fin.close();
	if (checkTF == n)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void removeStudent(const char *path) // hàm ngoài làm điều kiện mỗi lớp đưa vào 1 địa chỉ riêng
{
	int StudentID, n; //n: số sinh viên của lớp
	char again[5];
	do
	{
		ifstream fin;
		fin.open(path);
		fin >> n;
		fin.close();
		STUDENT *p = new STUDENT[n];
		cout << "Enter ID Student to remove: ";
		cin >> StudentID;
		bool ans = remove(path, p, n, StudentID);
		if (ans == true)
		{
			savedata(path, p, n);
			cout << "<<< THIS STUDENT HAS BEEN REMOVED SUCCESSFULLY ^.^ >>>\n";
			cout << "\t\t\t[......Continue to remove?......]: ";
			cin >> again;
		}
		else
		{
			cout << "<<< --REMOVE FAIL--NO STUDENT IN THIS CLASS ~.~ >>>\n";
			cout << "\t\t\t[......Remove again?......]: ";
			cin >> again;
		}
	} while (_stricmp(again, "yes") == 0);
}