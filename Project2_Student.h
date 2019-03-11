#ifndef MANAGERPROJ_STUDENT_H
#define MANAGERPROJ_STUDENT_H

#include <iostream>
#include <string>
#include <fstream>

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
void staff(string id);
void lecture(string id);
void student(string id);
void Continue(string id);

bool loaddata(const char *path, STUDENT *&a, int &n);

void init(STUDENT *&dest, STUDENT a, int &n);

bool savedata(const char *path, STUDENT *&a, int n);

#endif //MANAGERPROJ_STUDENT_H