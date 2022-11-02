#pragma once

#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;


template <class T>
class list;

template <class T>
ostream& operator<<(ostream& out, const list<T>& arg);

template <class T>
class list
{
protected:
	struct node
	{
		T* obj_ptr;
		node* next_node_ptr;
		node* previous_node_ptr;
		node()
			: next_node_ptr(NULL), previous_node_ptr(NULL), obj_ptr(NULL) {}
	};

	node* first_node_ptr;
	node* last_node_ptr;
	node* chosen_node_ptr;

	int element_counter;

public:
	list()
	{
		first_node_ptr = last_node_ptr = chosen_node_ptr = NULL;
		element_counter = 0;
	}

	friend ostream& operator<< <T>(ostream& out, const list<T>& arg);

	void add_element(T& obj);

	void print_chosen_element() const
	{
		if (!first_node_ptr)
			return;

		else
			cout << chosen_node_ptr->obj_ptr;
	}

	void set_chosen_as_first()
	{
		if (first_node_ptr)
			chosen_node_ptr = first_node_ptr;
	}

	void set_chosen_as_last()
	{
		if (last_node_ptr)
			chosen_node_ptr = last_node_ptr;
	}

	void set_chosen_after_last()
	{
		chosen_node_ptr = NULL;
	}

	node* go_to_next_node()
	{
		chosen_node_ptr = chosen_node_ptr->next_node_ptr;
		return chosen_node_ptr;
	}

	node* go_to_previous_node()
	{
		chosen_node_ptr = chosen_node_ptr->previous_node_ptr;
		return chosen_node_ptr;
	}

	void move_to_position(int position)
	{
		if (!first_node_ptr)
			return;

		if (position >= element_counter)
			set_chosen_after_last();
		else
		{
			set_chosen_as_first();

			for (int i = 0; i < position; i++)
			{
				go_to_next_node();
			}
		}
	}

	void remove_chosen_element();

	~list();

private:
	void add_element_as_first(node* newly_added_node_ptr);
	void add_element_as_last(node* newly_added_node_ptr);
	void add_element_in_middle(node* newly_added_node_ptr);
	//node* find_node_before_chosen();

	void remove_last_element();
	void remove_first_element();
	void remove_middle_element();
};
//##################################################################################
//##################################################################################


template <class T>
list<T>::~list()
{
	if (!first_node_ptr)  // stop doing anything if the list is empty
		return;

	node* bishop;
	int i;
	cout << "\n\n";

	for (chosen_node_ptr = first_node_ptr, i = 0; chosen_node_ptr; i++)
	{
		bishop = chosen_node_ptr->next_node_ptr;
		delete chosen_node_ptr;
		chosen_node_ptr = bishop;

		//cout << "Destruction of the " << i << " element" << endl;
	}
}



template <class T>
void list<T>::remove_middle_element()
{
	typename list<T>::node* previous_node = chosen_node_ptr->previous_node_ptr;
	typename list<T>::node* next_node = chosen_node_ptr->next_node_ptr;

	delete chosen_node_ptr;
	previous_node->next_node_ptr = next_node;
	next_node->previous_node_ptr = previous_node;
}


template <class T>
void list<T>::remove_first_element()
{
	// 1-element list scenario has been covered in remove_last_element()

	if (first_node_ptr->next_node_ptr == last_node_ptr) // 2-element list scenario
	{
		delete first_node_ptr;
		first_node_ptr = last_node_ptr;  // the list becomes a 1-element one
		chosen_node_ptr = first_node_ptr;
		first_node_ptr->previous_node_ptr = NULL;
	}

	else
	{
		node* second_node = first_node_ptr->next_node_ptr;
		delete first_node_ptr;
		first_node_ptr = second_node;
		chosen_node_ptr = first_node_ptr;
		first_node_ptr->previous_node_ptr = NULL;
	}
}


template <class T>
void list<T>::remove_last_element()  // 3 scenarios possible here
{
	if (first_node_ptr == last_node_ptr)  // if this is 1-element list then after the operation the list becomes empty
	{
		delete chosen_node_ptr;    // free the memory

		first_node_ptr = last_node_ptr = chosen_node_ptr = NULL;
		return;
	}

	else if (first_node_ptr->next_node_ptr == last_node_ptr)   // if this is a 2-element list
	{
		delete chosen_node_ptr;
		last_node_ptr = chosen_node_ptr = first_node_ptr;
		first_node_ptr->next_node_ptr = NULL;
		return;
	}

	else
	{
		typename list<T>::node* penultimate = last_node_ptr->previous_node_ptr;
		delete last_node_ptr;
		penultimate->next_node_ptr = NULL;
		last_node_ptr = penultimate;
	}

}

template <class T>
void list<T>::remove_chosen_element()
{
	if (!chosen_node_ptr)   // if the list is empty or chosen_node_ptr points at after the last element (is NULL)
		return;

	if (chosen_node_ptr == last_node_ptr)
	{
		remove_last_element();
		//return;    // to avoid checking out the remaining conditions
	}

	else if (chosen_node_ptr == first_node_ptr)
	{
		remove_first_element();
		//return;
	}

	else
		remove_middle_element();


	element_counter--;
}


template <class T>
ostream& operator<<(ostream& out, const list<T>& arg)
{
	if (!(arg.first_node_ptr))
		return out;

	typename list<T>::node* chaser = arg.first_node_ptr;

	for (; chaser; chaser = chaser->next_node_ptr)
	{
		out << *(chaser->obj_ptr) << "\t";
	}

	return out;
}


//template <class T>
//typename list<T>::node* list<T>::find_node_before_chosen()
//{
//	node* bishop = first_node_ptr;
//
//	for (bishop; bishop->next_node_ptr != chosen_node_ptr; bishop = bishop->next_node_ptr);
//
//	return bishop;
//}


template <class T>
void list<T>::add_element_in_middle(node* newly_added_node_ptr)
{
	node* previous_node = chosen_node_ptr->previous_node_ptr;
	previous_node->next_node_ptr = newly_added_node_ptr;
	newly_added_node_ptr->previous_node_ptr = previous_node;
	newly_added_node_ptr->next_node_ptr = chosen_node_ptr;
	chosen_node_ptr->previous_node_ptr = newly_added_node_ptr;
	chosen_node_ptr = newly_added_node_ptr;
}


template <class T>
void list<T>::add_element_as_last(node* newly_added_node_ptr)
{
	last_node_ptr->next_node_ptr = newly_added_node_ptr;
	newly_added_node_ptr->previous_node_ptr = last_node_ptr;
	last_node_ptr = newly_added_node_ptr;
}



template <class T>
void list<T>::add_element_as_first(node* newly_added_node_ptr)
{
	if (!first_node_ptr)   // in case the list is empty yet
	{
		first_node_ptr = newly_added_node_ptr;
		last_node_ptr = newly_added_node_ptr;
	}
	else
	{
		newly_added_node_ptr->next_node_ptr = first_node_ptr;
		first_node_ptr->previous_node_ptr = newly_added_node_ptr;
		first_node_ptr = newly_added_node_ptr;
		chosen_node_ptr = first_node_ptr;
	}
}

template <class T>
void list<T>::add_element(T& obj)
{
	node* new_node_ptr = new node;
	new_node_ptr->obj_ptr = &obj;

	if (!first_node_ptr || chosen_node_ptr == first_node_ptr)
		add_element_as_first(new_node_ptr);
	else
	{
		if (!chosen_node_ptr)
		{
			add_element_as_last(new_node_ptr);
		}
		else
		{
			add_element_in_middle(new_node_ptr);
		}
	}

	element_counter++;
}


