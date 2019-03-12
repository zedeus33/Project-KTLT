#ifndef _Header_H
#define _Header_H

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

struct Date {
	int day, month, year;
};

class STUDENT {
public:
	int No;
	int StudentID;
	string lastname, firstname;
	bool gender;
	Date DoB;
	int index;

	void output();
	//STUDENT(const STUDENT &student);
	//explicit STUDENT(int No = 0,int StudentID = 0,string lastname = nullptr,string firstname = nullptr,bool gender = true,Date DoB = {0,0,0},int index = 0);
};

void menu();
void inputIDPassword(string &id, string &password);

void staff(string id);
void lecture(string id);
void student(string id);
void Continue(string id);
void menuStaff(char &n, string id);
void ContinueStaff(char n, string id);
bool loaddata(const char *path, STUDENT *&a, int &n);

void init(STUDENT *&dest, STUDENT a, int &n);

bool savedata(const char *path, STUDENT *&a, int n);
bool outputPassword(const char *pathInput, const char *pathOutput);
bool login_student(string &account, string &password, const char *path);
#endif //MANAGERPROJ_STUDENT_H#pragma once
