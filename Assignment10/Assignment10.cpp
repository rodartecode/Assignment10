// Assignment10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

using namespace std;

class Birthday 
{
private:
	int month;
	int day;
	int year;

public:
	Birthday()
	{
		month = 1;
		day = 1;
		year = 1900;
	}

	Birthday(int newMonth, int newDay, int newYear)
	{
		if (newMonth <= 1)
			month = 1;
		else if (newMonth >= 12)
			month = 12;
		else
			month = newMonth;

		if (newDay <= 1)
			day = 1;
		else if (newDay >= 31)
			day = 31;
		else
			day = newDay;

		if (newYear <= 1900)
			year = 1900;
		else if (newYear >= 2018)
			year = 2018;
		else
			year = newYear;
	}

	Birthday(Birthday &birthday)
	{
		month = birthday.month;
		day = birthday.day;
		year = birthday.year;
	}
	
	~Birthday()
	{
	}

	int getMonth()
	{
		return month;
	}

	int getDay()
	{
		return day;
	}

	int getYear()
	{
		return year;
	}

	void setBirthday(int newMonth, int newDay, int newYear)
	{
		if (newMonth <= 1)
			month = 1;
		else if (newMonth >= 12)
			month = 12;
		else
			month = newMonth;

		if (newDay <= 1)
			day = 1;
		else if (newDay >= 31)
			day = 31;
		else
			day = newDay;

		if (newYear <= 1900)
			year = 1900;
		else if (newYear >= 2018)
			year = 2018;
		else
			year = newYear;
	}

	string birthdayString()
	{
		string date = "";

		date.append(to_string(getMonth()));
		date.append("/");
		date.append(to_string(getDay()));
		date.append("/");
		date.append(to_string(getYear()));

		return date;
	}

	Birthday operator=(Birthday& right)
	{
		month = right.getMonth();
		day = right.getDay();
		year = right.getYear();
	}
};

class Person
{
private:
	string name;
	Birthday bday;
public:

	Person()

	{

	}

	Person(string newName, Birthday birthday)
	{
		name = newName;
		bday = birthday;
	}

	Person(Person &newPerson)
	{
		name = newPerson.name;
		bday = newPerson.bday;
	}

	~Person()

	{

	}

	int getMonth()
	{
		return bday.getMonth();
	}



};




int main()
{
    return 0;
}

