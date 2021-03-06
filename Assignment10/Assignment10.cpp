// Assignment10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "BinarySearchTree.h"
#include "Person.h"
#include "Birthday.h"
#include <string>
#include <iostream>

using namespace std;

int globalMonth;

void display(Person &aFriend)
{
	std::cout << aFriend.getName() << ", " << aFriend.birthdayString() << endl;
}

void traversalHelper(Person &aFriend)
{
	if (globalMonth == aFriend.getMonth()) display(aFriend); 
}

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

	bool isEmpty()
	{
		return friends.isEmpty();
	}

	int getNumberOfItems()
	{
		return friends.getNumberOfNodes();
	}

	bool addFriend(Person newFriend)
	{
		return (friends.add(newFriend));
	}

	bool removeFriend(Person oldFriend)
	{
		return friends.remove(oldFriend);		
	}

	bool removeName(string aName)
	{
		Person temp = Person(aName, 1, 1, 1);
		return friends.remove(temp);
	}

	void clear()
	{
		friends.clear();
	}

	Person findFriend(const Person &aFriend)
	{
		friends.getEntry(aFriend);
	}

	Person findName(string aName)
	{
		Person temp = Person(aName, 1, 1, 1);
		return friends.getEntry(temp);
	}

	int getMonth(Person &aFriend)
	{
		return aFriend.getMonth();
	}

	bool contains(Person aFriend)
	{
		return friends.contains(aFriend);
	}

	bool contains(string aName)
	{
		Person temp = Person(aName, 1, 1, 1);
		return friends.contains(temp);
	}
	
	void displayFriends()
	{
		std::cout << "This is a list of all your friends: \n\n";

		friends.inorderTraverse(display);

		std::cout << endl << endl;
	}

	void allInMonth(int month)
	{
		globalMonth = month;

		std::cout << "This is a list of all your friends born on month: " << month << endl << endl;
		friends.inorderTraverse(traversalHelper);
		cout << endl;

		globalMonth = 0;
	}
};

int main()
{
	Dictionary myFriends;

	Person Jesse("AAAA", 1, 3, 1991);
	Person Rosa("Rosa Luxembourg", 3, 5, 1871);
	Person Friedrich("Friedrich Engels", 11, 28, 1820);
	Person Simone("Simone de Beauvoir", 1, 9, 1908);
	Person Marcos("Subcomandante Marcos", 6, 19, 1957);
	Person Emiliano("Emiliano Zapata", 8, 8, 1879);
	Person Marichuy("Maria de Jesus Patricio Martinez", 12, 23, 1983);
	Person Sebastien("Sebastien Faure", 1, 6, 1858);

	myFriends.addFriend(Jesse);
	myFriends.addFriend(Rosa);
	myFriends.addFriend(Simone);
	myFriends.addFriend(Friedrich);
	myFriends.addFriend(Marcos);
	myFriends.addFriend(Emiliano);
	myFriends.addFriend(Marichuy);
	myFriends.addFriend(Sebastien);
	
	myFriends.displayFriends();
	myFriends.allInMonth(1);

	cout << "Searching for 'AAAA'" << endl;
	if (myFriends.contains("AAAA"))
	{
		Person temp = myFriends.findName("AAAA");
		cout << temp.getName() << " born on " << temp.birthdayString() << endl << endl;
	}
	else
	{
		cout << "Person not found.." << endl << endl;
	}

	cout << "Now removing 'AAAA'" << endl;

	if (myFriends.removeName("AAAA"))
	{
		cout << "AAAA is no longer my friend" << endl << endl;
	}
	
	myFriends.allInMonth(1);

	return 0;
}


/*


EXPECTED OUTPUT:


This is a list of all your friends:

AAAA, 1/3/1991
Emiliano Zapata, 8/8/1879
Friedrich Engels, 11/28/1820
Maria de Jesus Patricio Martinez, 12/23/1983
Rosa Luxembourg, 3/5/1871
Sebastien Faure, 1/6/1858
Simone de Beauvoir, 1/9/1908
Subcomandante Marcos, 6/19/1957


This is a list of all your friends born on month: 1

AAAA, 1/3/1991
Sebastien Faure, 1/6/1858
Simone de Beauvoir, 1/9/1908

Searching for 'AAAA'
AAAA born on 1/3/1991

Now removing 'AAAA'
AAAA is no longer my friend

This is a list of all your friends born on month: 1

Simone de Beauvoir, 1/9/1908
Sebastien Faure, 1/6/1858



*/