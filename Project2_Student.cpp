#include <utility>

//
// Created by t3bol90 on 2/26/19.
//

#include "Student.h"

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

void init(STUDENT *&dest, STUDENT a, int &n) {
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
        case '1': {
            system("cls");
            string id;
            string password;
            cout << "Please enter your id : ";
            cin >> id;
            cout << "\nPlease enter your password : ";
            cin >> password;
            while (id.size() >= 10 || password.size() >= 10 || (id.size() >= 10 && password.size() >= 10)) {
                system("cls");
                cout << "Your account or password has a maximum of 9 characters. Please try again!" << endl;

                cout << "Please enter your id : ";

                cin >> id;
                cout << "\nPlease enter your password : ";

                cin >> password;
            }
            if (id[0] == 's') {
                system("cls");
                staff(id);
            } else if (id[0] == 'l') {
                system("cls");
                lecture(id);
            } else if (id[0] == '1') {
                system("cls");
                student(id);
            }
            else
            {
                cout << "Wrong id!! Try again"<<endl;
                system("cls");
                menu();
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
        default:
            break;
    }
}

void staff(string id) {
    system("cls");
    cout << "Welcome " << id << endl;
    cout << "\n[0] View profile info" << endl;
    cout << "\n[1] Scoreboard" << endl;
    cout << "\n[2] Courses" << endl;
    cout << "\n[3] Class" << endl;
    cout << "\n[4] Attendance list" << endl;
    cout << "\n[5] Logout" << endl;
    char userOption;

    cout << "\nEnter your choice : ";
    cin >> userOption;
    switch (userOption) {
        case '1': {
            system("cls");
            cout << "***Scoreboard***";
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
            cout << "***Class***";
            Continue(id);
        }
            break;
        case '4':{
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
}

void student(string id) {
    cout << "Welcome " << id << endl;
}


void Continue(string id) {
    cout << "\nDo you want to continued?(y/n) ";
    string YesorNo;
    cin >> YesorNo;
    if (YesorNo == "Yes")
        if (id[0] == 's') {
            system("cls");
            staff(id);
        } else if (id[0] == 'l') {
            system("cls");
            lecture(id);
        } else if (id[0] == '1') {
            system("cls");
            student(id);
        } else
            system("cls");
    cout << "Goodbye, Have a nice day!" <<
         endl;
}
