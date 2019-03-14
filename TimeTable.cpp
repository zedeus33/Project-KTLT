#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;
struct date
{
	int day, month, year;
};
struct time
{
	int hour, minute;
};
class timeTable
{
	private:
		int Number[15];
		char CourseID[15][10];
		char CourseName[15][60];
		char Class [15][8];
		char LecturerAccount[15][50];
		date StartDate[15];
		date EndDate[15];
		char DayOfWeek[15][5];
		time StartTime[15];
		time EndTime[15];
		char Room[15][8];
	public:
		timeTable();
		int InputTimeTable(const char *path);
};

timeTable::timeTable()
{
	for (int i = 0; i < 16; i++)
	{
		Number[i] = StartTime[i].minute = StartTime[i].hour = StartDate[i].day = StartDate[i].month = StartDate[i].year =
			EndTime[i].minute = EndTime[i].hour = EndDate[i].day = EndDate[i].month = EndDate[i].year;
	}
}

int timeTable::InputTimeTable(const char *path)
{
	ifstream file;
	file.open(path);
	if (!file.is_open())
	{
		return 0;
	}
	int i = 0;
	while (file.good())
	{
		file >> Number[i];
		file.ignore();
		file.getline(CourseID[i],10, ',');
		file.getline(CourseName[i], 60, ',');
		file.getline(Class[i], 8, ',');
		file.getline(LecturerAccount[i], 50, ',');
		file >> StartDate[i].day;
		file.ignore();
		file >> StartDate[i].month;
		file.ignore();
		file >> StartDate[i].year;
		file.ignore();
		file >>EndDate[i].day;
		file.ignore();
		file >> EndDate[i].month;
		file.ignore();
		file >> EndDate[i].year;
		file.ignore();
		file.getline(DayOfWeek[i], 5, ',');
		file >> StartTime[i].hour;
		file.ignore();
		file >> StartTime[i].minute;
		file.ignore();
		file >> EndTime[i].hour;
		file.ignore();
		file >> EndTime[i].minute;
		file.ignore();
		file.getline(Room[i], 8, '\n');
		i++;
	}
	file.close();
	return 1;
}