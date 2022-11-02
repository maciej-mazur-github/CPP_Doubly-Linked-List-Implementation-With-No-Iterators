#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include "Person.h"
#include "doubly_linked_list.h"
using namespace std;



int main()
{
	list<Person> list1;
	Person composer1("Bach"), composer2("Vivaldi"), composer3("Heineken"), composer4("Stradivarious");
	list1.add_element(composer1);
	//list1.add_element(composer2);
	list1.set_chosen_as_first();
	//list1.add_element(composer3);
	//list1.set_chosen_after_last();
	//list1.add_element(composer4);

	cout << list1 << "\n\n";

	list1.remove_chosen_element();
	cout << "This list again: " << list1;

	list1.move_to_position(1);
	list1.print_chosen_element();
	list1.move_to_position(2);
	list1.print_chosen_element();

	list1.move_to_position(1);
	//list1.set_chosen_as_first();
	//list1.set_chosen_as_last();
	//list1.set_chosen_after_last();
	list1.remove_chosen_element();
	cout << list1;






	list<int> list2;
	int a = 1, b = 2, c = 3, d = 4, e = 5;

	list2.add_element(a);
	list2.add_element(b);
	list2.add_element(c);
	list2.move_to_position(1);
	list2.add_element(d);
	list2.add_element(e);

	cout << "\n\n" << list2;



}