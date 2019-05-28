#include <iostream>

/*
\newpage
\fbox{\textbf{Node}}
\newline This Node structure is a common way to implement a node. it hold a pointer to the next node and the data , or in the case the key. I've called it "key" because it holds the key to its corresponding set of blocks stored in the map. This Node structure also has a constructor that sets the key equal to the string provided as a parameter.
*/
struct Node
{
	Node* next = nullptr;
	std::string key = "";
	Node(std::string key);
};

/*
\fbox{\textbf{Queue}}
\newline The Queue structure holds the head and tail node pointer of the linked list queue. I've Implemented a linked list queue because I am quite comfortable with linked lists and I am certainly more comfortable dealing with linked lists than I am dealing with a circular array. The Queue has built in push and pop functions as well.
*/
struct Queue
{
	Node* head = nullptr;
	Node* tail = nullptr;
	void push(std::string key);
	void pop();
};

Node::Node(std::string key)
{
	this->key = key;
}

/*
\newpage
\fbox{\textbf{push}}
\newline The push function adds a node to back of the list. I decided to make a Queue that adds to the tail and pops from the head because in order to pop from the tail we would have to traverse through the linked list. this inefficient compared to the method I am using which does not require traversing through the entire list.
*/
void Queue::push(std::string key)
{
	Node* newnode = new Node(key);
	if(head == nullptr){
		tail = newnode;
		head = newnode;
	}
	else
	{
		tail->next = newnode;
		tail = newnode;
	}
}

/*
\newpage
\fbox{\textbf{pop}}
\newline The pop function pops from the head if the list is not empty. First we make a temporary node pointer which points to head so we don't lose it. Then we move the head to the next node and then delete the temporay node.
*/

void Queue::pop()
{
	if(head == nullptr)
		return;
	Node* tmp = head;
	head = head->next;
	delete(tmp);
}

/*

g++ -g -I/home/debian -I/home/debian/fltk-1.3.4-2 -o "lab" main.cpp `fltk-config --cxxflags --ldflags --use-images --use-cairo`

*/
