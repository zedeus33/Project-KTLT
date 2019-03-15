#ifndef _Header_H
#define _Header_H

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#define STUDENT_PASSWORD "D:/Document/HCMUS_FIT/KI THUAT LAP TRINH/Lab/PROJECT/StudentManager/Project-KTLT-master/Project-KTLT-master/Password_18CLC6_Students.txt"
#define DATA_STUDENT "D:/Document/HCMUS_FIT/KI THUAT LAP TRINH/Lab/PROJECT/StudentManager/Project-KTLT-master/Project-KTLT-master/18CLC6_Students.txt"
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
	string password;
	void output();
};
class CLASS
{
public:
    explicit CLASS(string classname = "Default Class",int amount = 1);
    CLASS(const CLASS &c);
    ~CLASS();
    string getClassname();
private:
	string classname;
	int amount;
	STUDENT *list = new STUDENT[amount];
};


//MENU:
char firstMenu();
void inputIDPassword(string &id, string &password);
void secondMenu(char userOption);

char firstStaffMenu(string id);
void secondStaffMenu(string id);

void staffContinue(string id);

void firstLectureMenu(string id);


void firstStudentMenu(string id);
bool creatDefaultIP(const char *pathInput, const char *pathOutput);
bool checkLoginStudent(string &account, string &password, const char *path);


void systemContinue(string id);
void staffMenuClass(string id);

bool loaddata(const char *path, STUDENT *&a, int &n);

void init(STUDENT *&dest, STUDENT a, int &n);

bool savedata(const char *path, STUDENT *&a, int n);


#endif //MANAGERPROJ_STUDENT_H#pragma once
