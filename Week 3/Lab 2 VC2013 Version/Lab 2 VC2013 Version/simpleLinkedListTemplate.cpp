#pragma once

#ifndef SIMPLELINKEDLISTTEMPLATEHPP
#define SIMPLELINKEDLISTTEMPLATEHPP

#include <iostream>
#include "simpleLinkedListTemplate.h"
using namespace std;


template <class T>
ListNode<T>::ListNode(T n)
{
	_item = n;
	_next = NULL;
}

template <class T>
void List<T>::insertHead(T n)
{
	ListNode<T> *aNewNode = new ListNode<T>(n);
	aNewNode->_next = _head;
	_head = aNewNode;
	_size++;
};

template <class T>
void List<T>::removeHead()
{
	if (_size > 0) {
		ListNode<T> *temp = _head;
		_head = _head->_next;
		delete temp;
		_size--;
	}
}

template <class T>
void List<T>::print(bool withNL) {

	ListNode<T> *temp = _head;
	while (temp) {
		cout << temp->_item;
		if (withNL)
			cout << endl;
		else
			cout << " ";
		temp = temp->_next;
	}
	cout << endl;
	  
}

template <class T>
bool List<T>::exist(T n) {
	ListNode<T>* curr = this->_head;
	while (curr != NULL) {
		if (curr->content() == n) return true;
		curr = curr->_next;
	}
	return false;
}

template <class T>
T List<T>::headItem()
{
	if (_size)
		return *_head;
}

template <class T>
T List<T>::extractMax()
{
	if (this->_size == 0) return T();
	//else if (this->_size == 1) return this->_head->content();
	ListNode<T>* currptr = this->_head;
	ListNode<T>* nextptr = currptr->_next;
	ListNode<T>* maxptr = currptr;

	while (nextptr != NULL) {
		//cout << "curr = " << currptr->content() << " and currmax = " << maxptr->content() << " and next= = " << (nextptr->content());
		if (nextptr->content() > maxptr->content()) maxptr = nextptr;
		currptr = nextptr;
		nextptr = currptr->_next;
		//cout << "curr same as next? = " << (currptr == nextptr) << endl;
	}


	T max = maxptr->content();

	//found the max alr, need to go back to start to remove it (like selection sort)


	//first, we change the ptr of _next (or _head, if _head is the largest)
		if (maxptr == this->_head) this->_head = maxptr->_next; //if only 1 element, then _next will automatically be NULL per its constructor

	////if not the first element, then go through until find, then delete
		else {
			currptr = this->_head;
			nextptr = currptr->_next;
			while (nextptr != maxptr) {
				currptr = nextptr;
				nextptr = currptr->_next;
			}
			//now, nextptr == maxptr
			currptr->_next = maxptr->_next;

		}
	delete maxptr;
	// if there are duplicates maximas in the list, return the leftmost one (the one closest to the _head)
	return max;
}

template <class T>
void List<T>::reverseOp() {
	if (this->_head == NULL) return;
	//_head points to last element, every other element points backwards.

	ListNode<T>* last = this->_head;
	while (last->_next != NULL) last = last->_next;
	//now last is pointing to last element

	ListNode<T>* prev = this->_head;
	ListNode<T>* curr = prev->_next;
	prev->_next = NULL; //set the _head to point backwards ie point NULL

	if (curr == NULL) return;

	ListNode<T>* next = curr->_next;
	if (next == NULL)
	{
		this->_head = curr;
		curr->_next = prev;
		return;
	}
	
	curr->_next = prev;
	while (next != last) {
		prev = curr;
		curr = next;
		next = next->_next;

		curr->_next = prev;
	}
	last->_next = curr;
	this->_head = last;
}



template <class T>
List<T>::~List()
{
	while (_head)
		removeHead();
};


#endif