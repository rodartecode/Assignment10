// Assignment10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "BinarySearchTree.h"
#include "Person.h"
#include "Birthday.h"
#include <string>

using namespace std;

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