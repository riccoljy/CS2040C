#include <iostream>
#include "simpleIntLinkedList.h"
using namespace std;

ListNode::ListNode(int n)
{
	_item = n;
	_next = NULL;
}

void List::insertHead(int n)
{
	ListNode *aNewNode = new ListNode(n);
	aNewNode->_next = _head;
	_head = aNewNode;
	_size++;
};

void List::removeHead()
{
	if (_size > 0) {
		ListNode *temp = _head;
		_head = _head->_next;
		delete temp;
		_size--;
	}
}

void List::print() {
	ListNode* curr = this->_head;
	while (curr != NULL) {
		cout << curr->content() << " ";
		curr = curr->_next;
	}
	cout << endl; // modify this
}

bool List::exist(int n) {
	ListNode* curr = this->_head;
	while (curr != NULL) {
		if (curr->_item == n) {
			return true;
		}
		curr = curr->_next;
		}
	return false; // modify this
}

ListNode *List::headItem()
{
	if (this->_head != NULL) return this->_head;
	return 0; // modify this
}
bool List::empty() {
	if (this->_head == NULL) return 1;
	return 0;
}

ListNode *List::tailItem()
{
	if (this->empty()) return 0;
	ListNode* curr = this->_head;
	while (curr->_next != NULL) {
		curr = curr->_next;
	}
	return curr;
}

void List::removeTail()
{
	if (this->empty()) return;
	ListNode* curr = this->_head;
	ListNode* prev = NULL;
	while (curr->_next != NULL) {
		prev = curr;
		curr = curr->_next;
	}
	if (prev == NULL) { //ie List only has one ListNode
		this->removeHead();
		return;
	}

	//curr is last, prev is 2nd last
	prev->_next = NULL;
	delete curr;
	this->_size--;
}

List::~List()
{
	while (_size != 0)
		removeHead();
};

