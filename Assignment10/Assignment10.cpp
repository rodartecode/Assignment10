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

	void clear()
	{
		friends.clear();
	}

	Person findFriend(const Person &aFriend)
	{
		friends.getEntry(aFriend);
	}

	int getMonth(Person &aFriend)
	{
		return aFriend.getMonth();
	}

	bool contains(Person aFriend)
	{
		return friends.contains(aFriend);
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

		globalMonth = 0;
	}
};

int main()
{
	Dictionary myFriends;

	Person Jesse("Jesse", 1, 3, 1991);
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

	return 0;
}


/*


EXPECTED OUTPUT:


This is a list of all your friends:

Emiliano Zapata, 8/8/1879
Friedrich Engels, 11/28/1820
Jesse, 1/3/1991
Maria de Jesus Patricio Martinez, 12/23/1983
Rosa Luxembourg, 3/5/1871
Sebastien Faure, 1/6/1858
Simone de Beauvoir, 1/9/1908
Subcomandante Marcos, 6/19/1957


This is a list of all your friends born on month: 1

Jesse, 1/3/1991
Sebastien Faure, 1/6/1858
Simone de Beauvoir, 1/9/1908


*/