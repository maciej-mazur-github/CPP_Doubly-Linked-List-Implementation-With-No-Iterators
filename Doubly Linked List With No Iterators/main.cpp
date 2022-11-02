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
	Person composer1("Bach"), composer2("Vivaldi"), composer3("Heineken"), composer4("Stradivarious");
	list1.addElement(composer1);
	//list1.addElement(composer2);
	list1.setChosenAsFirst();
	//list1.addElement(composer3);
	//list1.set_chosen_after_last();
	//list1.addElement(composer4);

	cout << list1 << "\n\n";

	list1.removeChosenElement();
	cout << "This list again: " << list1;

	list1.moveToPosition(1);
	list1.printChosenElement();
	list1.moveToPosition(2);
	list1.printChosenElement();

	list1.moveToPosition(1);
	//list1.setChosenAsFirst();
	//list1.set_chosen_as_last();
	//list1.set_chosen_after_last();
	list1.removeChosenElement();
	cout << list1;






	List<int> list2;
	int a = 1, b = 2, c = 3, d = 4, e = 5;

	list2.addElement(a);
	list2.addElement(b);
	list2.addElement(c);
	list2.moveToPosition(1);
	list2.addElement(d);
	list2.addElement(e);

	cout << "\n\n" << list2;



}