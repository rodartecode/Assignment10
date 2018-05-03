// Assignment10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "BinarySearchTree.h"
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

		if (newYear <= 1)
			year = 1;
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

	const int getMonth()
	{
		return month;
	}

	const int getDay()
	{
		return day;
	}

	const int getYear()
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

	const Birthday operator=(Birthday &right)
	{
		month = right.getMonth();
		day = right.getDay();
		year = right.getYear();

		return *this;
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

	Person(string newName, int newMonth, int newDay, int newYear)
	{
		name = newName;
		bday.setBirthday(newMonth, newDay, newYear);
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

class Dictionary
{
private:
	BinarySearchTree<Person> friends;

public:
	Dictionary()
	{

	}

	~Dictionary()
	{

	}

	bool addFriend(Person newFriend)
	{
		return friends.add(newFriend);
	}

	bool removeFriend(Person oldFriend)
	{
		return friends.remove(oldFriend);
	}

	string findBirthday(Person theFriend)
	{
		return "test";
	}

	void displayFriends()
	{

	}

	void allInMonth(int month)
	{

	}


};

int main()
{
	Dictionary myFriends;

	Person Jesse("Jesse", 1, 3, 1991);
	Person Rosa("Rosa Luxembourg", 3, 5, 1871);
	Person Friedrich("Friedrich Engels", 11, 28, 1820);
	Person Simone("Simone de Beauvoir", 1, 9, 1908);

	myFriends.addFriend(Jesse);

    return 0;
}


template class BinarySearchTree<Person>;