#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include "Person.h"
#include "doubly_linked_list.h"
using namespace std;



int main()
{
	List<Person> list1;
	Person composer1("Bach"), composer2("Vivaldi"), composer3("Chopin"), composer4("Stradivarious");
	list1.addElement(composer1);
	list1.addElement(composer2);
	list1.addElement(composer3);
	list1.addElement(composer4);
	
	cout << "Current status of list1:\n";
	cout << list1;
	cout << "\n\n";
	cout << "After removal of the first element:\n";
	list1.setChosenAsFirst();
	list1.removeChosenElement();
	cout << list1;
	cout << "\n\n";
	

	cout << list1 << "\n\n";

	cout << "Removing the chosen element again (by default the chosen element is the first one):" << endl;
	list1.removeChosenElement();
	cout << "This list again: " << list1;

	cout << "\nMoving pointer chosenNodePtr to position(1) and printing its content: ";
	list1.moveToPosition(1);
	list1.printChosenElement();
	cout << "\nMoving pointer chosenNodePtr to position(2) and printing its content: ";
	list1.moveToPosition(2);
	list1.printChosenElement();

	cout << "Setting chosenNodePtr pointer on the first list element, printing this element, then removing this element and printing the content of the remaining list:" << endl;
	list1.setChosenAsFirst();
	list1.printChosenElement();
	list1.removeChosenElement();
	cout << list1;



	cout << "\n\nTesting List template for List<int>:\n";
	List<int> list2;
	int a = 1, b = 2, c = 3, d = 4, e = 5;

	list2.addElement(a);
	list2.addElement(b);
	list2.addElement(c);
	list2.addElement(d);
	list2.addElement(e);

	cout << "Current list2 status:\n";
	cout << list2;
	cout << "\nTrying to insert b (2) element again but this at the position(3) and then printing the result list:\n";
	list2.moveToPosition(3);
	list2.addElement(b);
	cout << list2;
	cout << "\nTrying to insert b (2) element again but this at the position(0) and then printing the result list:\n";
	list2.setChosenAsFirst();
	list2.addElement(b);
	cout << list2;
	cout << "\nTrying to insert b (2) element again but this at the last but one position and then printing the result list:\n";
	list2.setChosenAsLast();
	list2.addElement(b);
	cout << list2;
	cout << "\nTrying to insert b (2) element again but this at the last position and then printing the result list:\n";
	list2.setChosenAfterLast();
	list2.addElement(b);
	cout << list2;



}