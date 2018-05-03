CS 110C Assignment 10: Birthdays

City College of San Francisco

Instructor: Max Luttrell

Spring 2018


For this assignment, you will implement a dictionary to track the name and birthday of your friends and relatives.  You should be able to do the following operations:

- add an entry

- remove an entry

- search the dictionary for the birthday for a given name

- display the name and birthday of every entry in the dictionary

- list everyone in the dictionary who was born in a given month


The search key is the name, and you may assume that the names are unique.


Design and implement a C++ class to represent a person, which contains a name and a birthday at minimum.  Additionally, design and implement a C++ class to represent an ADT Dictionary of Person objects.  Do not use an existing library class for the dictionary, you must implement your own.


Searching for a person in your dictionary must be an average-case O(log n) operation; adding and removing can be O(n); and the "list everyone who was born in a given month" operation can be an O(n) operation.  With these requirements in mind, it is up to you which type of dictionary to use.  You are free to leverage any work done in previous assignments.


You may create an interactive program which supports all of the required operations, or you may hard-code a sequence of operations that fully demonstrates your dictionary.
