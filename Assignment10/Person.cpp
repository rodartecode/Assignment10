#include "stdafx.h"

#include <string>
#include "Birthday.h"
#include "Person.h"

Person::Person()
{
}

Person::Person(std::string newName, Birthday birthday)
{
	name = newName;
	bday = birthday;
}

Person::Person(std::string newName, int newMonth, int newDay, int newYear)
{
	name = newName;
	bday.setBirthday(newMonth, newDay, newYear);
}

Person::Person(const Person &newPerson)
{
	name = newPerson.name;
	bday = newPerson.bday;
}

Person::~Person()

{
}

int Person::getMonth()
{
	return bday.getMonth();
}

bool Person::operator==(const Person &right)
{
	return this->name == right.name;
}

bool Person::operator < (const Person &right)
{
	return this->name < right.name;
}

bool Person::operator > (const Person &right)
{
	return this->name > right.name;
}