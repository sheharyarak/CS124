/***********************************************************************
* \obeylines \obeyspaces
* File: H-minHeap.h
* Author(s): Natalie Peck, Gurpreet Singh, Justin Anaya, Sheharyar Khan
* Class: CS-124-02
* Term: Spring 2019
* Lab: Team Project
* Date: 17 May 2019
* Despcription: 
	
	The class file containing declarations of all the functions needed to 
	create a min heap.
	
***********************************************************************/
/*
\includegraphics[scale = 0.5]{MinHeap.png}
*/
/*** Duplication Protection ***/
#ifndef MINHEAP_H
#define MINHEAP_H

/*** System Libraries ***/
#include <vector>
#include <iostream>

/*** Namespace Declaration ***/
using namespace std;
/*\newpage*/
/***********************************/
/** This class implements a heap. **/
/***********************************/

template<typename T>

class MinHeap
{
	public:
		
		/********************** Public Member Functions **********************/
		
		/*Constructs an empty heap.*/
		MinHeap();

		/*
		Adds a new element to this heap.
		Parameter {element}: the element to add
		*/
		void push(T element);

		/*
		Gets the minimum element stored in this heap.
		returns: the minimum element
		*/
		T top() const;

		/*
		Removes the minimum element from this heap.
		*/
		void pop();
/*\newpage*/
		/*
		Gets the size of this heap.
		returns: the size
		*/
		int size() const;
		
		/*
		Re-heaps to preserve desired priority order
		*/
		void fix_heap_public();
		
		/*
		Print all entries in the heap
		*/
		void print_heap_public();

	private:
		
		/********************** Private Variable(s) **********************/
		
		vector<T> elements;
		
		/********************** Private Member Functions **********************/
		/*
		Turns the tree back into a heap, provided only the root
		node violates the heap condition.
		*/
		void fix_heap();
/*\newpage*/
		/********************************************/
		
		/*
		Returns the index of the left child.
		Parameter {index}: the index of a node in this heap
		returns: the index of the left child of the given node
		*/
		int get_left_child_index(int index) const;
		
		/********************************************/
		
		/*
		Returns the index of the right child.
		Parameter {index}: the index of a node in this heap
		returns: the index of the right child of the given node
		*/
		int get_right_child_index(int index) const;
		
		/********************************************/

		/*
		Returns the index of the parent.
		Parameter {index}: the index of a node in this heap
		returns: the index of the parent of the given node
		*/
		int get_parent_index(int index) const;
/*\newpage*/
		/********************************************/

		/*
		Returns the value of the left child.
		Parameter {index}: the index of a node in this heap
		returns: the value of the left child of the given node
		*/
		T get_left_child(int index) const;
		
		/********************************************/

		/*
		Returns the value of the right child.
		Parameter {index}: the index of a node in this heap
		returns: the value of the right child of the given node
		*/
		T get_right_child(int index) const;
		
		/********************************************/

		/*Returns the value of the parent.
		Parameter {index}: the index of a node in this heap
		returns: the value of the parent of the given node
		*/
		T get_parent(int index) const;
/*\newpage*/
		/********************************************/

		/*
		Print all entries in the heap
		*/
		void print_heap();

};

/********************** MinHeap() Constructor *********************/

template<typename T>

MinHeap<T>::MinHeap()

{	
	T dummy;
	elements.push_back(dummy);
}
/*\newpage*/
/*********************************************************************/
/********************** Public Member Functions **********************/
/*********************************************************************/

/********************** push() Function ************************/

template<typename T>

void MinHeap<T>::push(T new_element)
{
	/* Add a new leaf */
	T dummy;
	
	elements.push_back(dummy);
	
	int index = elements.size() - 1;
	
	/* Demote parents that are bigger than the new element */
	while (index > 1 && get_parent(index) > new_element)
	{
		elements[index] = get_parent(index);
		
		index = get_parent_index(index);
	}
	
	/* Store the new element into the vacant slot */
	elements[index] = new_element;
}
/*\newpage*/
/************************ top() Function **********************/

template<typename T>

T MinHeap<T>::top() const
{
	return elements[2];
}

/************************ pop() Function ************************/

template<typename T>

void MinHeap<T>::pop()
{	/* Remove last element */
	
	int last_index = elements.size() - 1;
	
	T last = elements[last_index];
	
	elements.pop_back();
	
	if (last_index > 1)
	{
		elements[1] = last;
		fix_heap();     
	}
}
/*\newpage*/
/*********************** size() Function **********************/

template<typename T>

int MinHeap<T>::size() const
{
	return elements.size() - 1;
}

/********************* fixHeapPublic() Function **********************/

template<typename T>

void MinHeap<T>::fix_heap_public()
{
	fix_heap();
}

/******************* printHeapPublic() Function ********************/

template<typename T>

void MinHeap<T>::print_heap_public()
{
	print_heap();
}
/*\newpage*/
/*********************************************************************/
/********************* Private Member Functions **********************/
/*********************************************************************/

/*********************** fixHeap() Function *********************/

template<typename T>

void MinHeap<T>::fix_heap()
{
	
	T root = elements[1];

	int last_index = elements.size() - 1;
	
	/* Promote children of removed root while they are bigger than root */
	
	int index = 1;
	
	bool done = false;
	
	while (!done)
	{
		int child_index = get_left_child_index(index);
		if (child_index <= last_index)
		{
			/* Get smaller child */
			
			/* Get left child first */
			T child = get_left_child(index);
/*\newpage*/
			/* Use right child instead if it is smaller */
			if (get_right_child_index(index) <= last_index 
			&& child > get_right_child(index))
			{
				child_index = get_right_child_index(index);
				child = get_right_child(index);
			}
			
			/* Check if smaller child is smaller than root */
			if (root > child) 
			{
				/* Promote child */
				elements[index] = child;
				index = child_index;
			}
			
			else
			{ /* Root is smaller than both children */
				done = true;
			}
		}
		
		else 
		{ /* No children */
			done = true; 
		}
	}
	
	/* Store root element in vacant slot */
	elements[index] = root;
}
/*\newpage*/
/***************** getLeftChildIndex() Function ****************/

template<typename T>

int MinHeap<T>::get_left_child_index(int index) const
{
	return 2 * index;
}

/***************** getRightChildIndex() Function ****************/

template<typename T>

int MinHeap<T>::get_right_child_index(int index) const
{
	return (2 * index) + 1;
}

/***************** getParentIndex() Function ****************/

template<typename T>

int MinHeap<T>::get_parent_index(int index) const
{
	return index / 2;
}
/*\newpage*/
/******************** getLeftChild() Function *********************/

template<typename T>

T MinHeap<T>::get_left_child(int index) const
{
	return elements[2 * index];
}

/****************** getRightChild() Function ********************/

template<typename T>

T MinHeap<T>::get_right_child(int index) const
{
	return elements[2 * index + 1];
}

/******************** getParent() Function *********************/

template<typename T>

T MinHeap<T>::get_parent(int index) const
{
	return elements[index / 2];
}
/*\newpage*/
/******************* printHeap() Function *******************/

template<typename T>

void MinHeap<T>::print_heap()
{
	for(int i = 1; i < elements.size(); i++)
	{
		std::cout << elements[i] << std::endl;
	}
}

#endif /* end of MINHEAP.H */
