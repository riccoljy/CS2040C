#pragma once
#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree;

template <class T>
class TreeNode {
private:
	T _item;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	TreeNode<T>* _parent;
	int _height;
public:
	TreeNode(T x) { _parent = _left = _right = NULL; _item = x; _height = 0; };
	friend BinarySearchTree<T>;
};

template <class T>
class BinarySearchTree {
protected:
	int _size;
	TreeNode<T>* _root;
	void _printTree(int indent, TreeNode<T>*, bool withHeight);

	// The following functions are optional for you to implement. 
	TreeNode<T>*  _insert(TreeNode<T>* current, T x);
	void _inOrderPrint(TreeNode<T>*);
	void _postOrderPrint(TreeNode<T>*);
	void _preOrderPrint(TreeNode<T>*);
	TreeNode<T>* _rightRotation(TreeNode<T>*);
	TreeNode<T>* _leftRotation(TreeNode<T>*);
	TreeNode<T>* _searchMax(TreeNode<T>*);
	TreeNode<T>* _searchMin(TreeNode<T>*);
	TreeNode<T>* _search(TreeNode<T>*, T);
	void _destroySubTree(TreeNode<T>*);

	

public:
	BinarySearchTree() { _root = NULL; _size = 0; }
	~BinarySearchTree();
	int size() { return _size; };
	void insert(T);
	void printTree(bool withHeight = 1);
	void inOrderPrint();
	void postOrderPrint();
	void preOrderPrint();
	T searchMax() { TreeNode<T>* maxnode = _searchMax(_root); return maxnode ? maxnode->_item : T(); }; //
	T searchMin() { TreeNode<T>* minnode = _searchMin(_root); return minnode ? minnode->_item : T(); }; //
	bool exist(T x) { return _search(_root, x) ? true : false; };//
	TreeNode<T>* search(T x) { return _search(_root, x); };
	T successor(T);

	void leftrotate(T x) { _leftRotation(_search(_root, x)); }
	void rightrotate(T x) { _rightRotation(_search(_root, x)); }
};

template <class T>
void BinarySearchTree<T>::insert(T x)
{
	_root = _root ? _insert(_root, x) : new TreeNode<T>(x);
	if (_size == 0) _size++;
}

template <class T>
void BinarySearchTree<T>::_printTree(int indent, TreeNode<T>* node, bool withHeight) {

	if (!node)
		return;

	if (node->_right)
		_printTree(indent + 2, node->_right, withHeight);
	for (int i = 0; i < indent; i++)
		cout << "  ";
	cout << node->_item;
	if (withHeight)
		cout << "(h=" << node->_height << ")";
	cout << endl;
	if (node->_left)
		_printTree(indent + 2, node->_left, withHeight);


};

template <class T>
void BinarySearchTree<T>::printTree(bool withHeight) {
	_printTree(0, _root, withHeight);
}


template <class T>
void BinarySearchTree<T>::preOrderPrint() {

	_preOrderPrint(_root);
	cout << endl;
}


template <class T>
void BinarySearchTree<T>::_preOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	cout << node->_item << " ";
	_preOrderPrint(node->_left);
	_preOrderPrint(node->_right);
}


template <class T>
void BinarySearchTree<T> ::_destroySubTree(TreeNode<T>* node)
{
	if (node->_left)
		_destroySubTree(node->_left);
	if (node->_right)
		_destroySubTree(node->_right);
	delete node;
}

template <class T>
BinarySearchTree<T> :: ~BinarySearchTree()
{
	if (_root)
		_destroySubTree(_root);
}



template <class T>
void BinarySearchTree<T>::inOrderPrint() {
	_inOrderPrint(_root);
	cout << endl;
}


template <class T>
void BinarySearchTree<T>::_inOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	_inOrderPrint(node->_left);
	cout << node->_item << " ";
	_inOrderPrint(node->_right);
}


template <class T>
void BinarySearchTree<T>::postOrderPrint() {
	_postOrderPrint(_root);
	cout << endl;

}


template <class T>
void BinarySearchTree<T>::_postOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	_postOrderPrint(node->_left);
	_postOrderPrint(node->_right);
	cout << node->_item << " ";
}



template <class T>
TreeNode<T>* BinarySearchTree<T>::_insert(TreeNode<T>* current, T x) {
	if (!current) return NULL;

	if (current->_item > x)
	{
		if (current->_left)
		{
			current->_left = _insert(current->_left, x);

			//int leftHeight = current->_left ? current->_left->_height : -1;
			//int rightHeight = current->_right ? current->_right->_height : -1;

			//if (leftHeight - rightHeight > 1) current = _rightRotation(current);
			//else if (rightHeight - leftHeight > 1) current = _leftRotation(current);
		}
		else
		{
			current->_left = new TreeNode<T>(x);
			current->_left->_parent = current;
			_size++;
			/*TreeNode<T>* curr = current;
			while (curr) {
				curr->_height = max(curr->_left ? curr->_left->_height : -1, curr->_right ? curr->_right->_height : -1) + 1;
				curr = curr->_parent;
			}*/
		}
	}

	else if (x > current->_item) {
		if (current->_right)
		{
 
		current->_right = _insert(current->_right, x);

		//int leftHeight = current->_left ? current->_left->_height : -1;
		//int rightHeight = current->_right ? current->_right->_height : -1;
 
		//if (leftHeight - rightHeight > 1) current = _rightRotation(current);
		//else if (rightHeight - leftHeight > 1) current = _leftRotation(current);
		}
		else
		{
			current->_right = new TreeNode<T>(x);
			current->_right->_parent = current;
			_size++;
			/*TreeNode<T>* curr = current;
			while (curr) {
				curr->_height = max(curr->_left ? curr->_left->_height : -1, curr->_right ? curr->_right->_height : -1) + 1;
				curr = curr->_parent;
			}*/
			
		}
	}


	current->_height = max(current->_left ? current->_left->_height : -1, current->_right ? current->_right->_height : -1) + 1;
	int leftHeight = current->_left ? current->_left->_height : -1;
	int rightHeight = current->_right ? current->_right->_height : -1;

	if (leftHeight - rightHeight > 1) {
		//first check whether "one straight line"
		int left2Height = current->_left->_left ? current->_left->_left->_height : -1;
		int right2Height = current->_left->_right ? current->_left->_right->_height : -1;
		//if not one straight line, make it one line first
		if (right2Height - left2Height > 0) _leftRotation(current->_left);
		//after one straight line, then rotate as per normal
		current =_rightRotation(current);
	}
	else if (rightHeight - leftHeight > 1) {//first check whether "one straight line"
		int left2Height = current->_right->_left ? current->_right->_left->_height : -1;
		int right2Height = current->_right->_right ? current->_right->_right->_height : -1;
		//if not one straight line, make it one line first
		if (left2Height - right2Height > 0) _rightRotation(current->_right);
		//after one straight line, then rotate as per normal
		current =_leftRotation(current);
	}

	return current; // When the node already existed in the tree

}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_searchMax(TreeNode<T>* current) {
	if (!current) return NULL;
	while (current->_right) current = current->_right;
	return current;
}


template <class T>
TreeNode<T>* BinarySearchTree<T>::_searchMin(TreeNode<T>* current) {
	if (!current) return NULL;
	while (current->_left) current = current->_left;
	return current;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_search(TreeNode<T>* current, T x) {
	if (!current) return NULL;
	if (current->_item == x) return current;
	else if (x < current->_item) return current->_left ? _search(current->_left, x) : NULL;
	else{return current->_right ? _search(current->_right, x) : NULL;}
}


template <class T>
T BinarySearchTree<T>::successor(T x)
{
	if (!_root) return NULL;
	TreeNode<T>* curr = _root;
	while (curr) {
		if (x == curr->_item) break;
		else if (x < curr->_item) {
			if (curr->_left) { curr = curr->_left; continue; }
			else break;
		}
		else /*bigger*/
		{
			if (curr->_right) { curr = curr->_right; continue; }
			else break;
		}
	}
	//now curr is pointing to node closest to x
	if (x < curr->_item) return curr->_item;
	if (curr->_right) {
		curr = curr->_right;
		while (curr->_left) curr = curr->_left;
		return curr->_item;
	}
	while (curr->_parent) {
		if (curr->_parent->_left == curr) return curr->_parent->_item;
		curr = curr->_parent;
	}
	//if reach here, means x is largest item.
	return NULL;

}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_leftRotation(TreeNode<T>* node)
{
	//if input pointer is pointing to a node but not on tree (fail-safe)
	if (!node) return NULL;
	TreeNode<T>* location = _search(_root, node->_item);
	if (!location) return NULL;

	//normal rotate
	else
	{
		if (!node->_right) return node;
		else /*if got right ie normal*/ {

			TreeNode<T>* replacement = node->_right;
			replacement->_parent = node->_parent;
			if (!node->_parent) _root = replacement;
			else if (node == node->_parent->_left) node->_parent->_left = replacement;
			else /*if node is parent's right,*/ { node->_parent->_right = replacement; }

			//after changing parent's left/right,
			node->_right = replacement->_left; 
			if (node->_right) node->_right->_parent = node;
			replacement->_left = node; node->_parent = replacement;

			TreeNode<T>* curr = node;
			while (curr) {
				curr->_height = max(curr->_left ? curr->_left->_height : -1, curr->_right ? curr->_right->_height : -1) + 1;
				curr = curr->_parent;
			}
			return replacement;
		}
	}
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_rightRotation(TreeNode<T>* node)
{
	//if input pointer is pointing to a node but not on tree (fail-safe)
	if (!node) return NULL;
	TreeNode<T>* location = _search(_root, node->_item);
	if (!location) return NULL;

	//normal rotate
	if (!node->_left) return node;
	/*if got left ie normal*/

	TreeNode<T>* replacement = node->_left;
	replacement->_parent = node->_parent;
	if (!node->_parent) _root = replacement;
	else if (node == node->_parent->_left) node->_parent->_left = replacement;
	else /*if node is parent's right,*/ { node->_parent->_right = replacement; }

	//after changing parent's left/right,
	node->_left = replacement->_right;
	replacement->_right = node;
	node->_parent = replacement;

	TreeNode<T>* curr = node;
	while (curr) {
		curr->_height = max(curr->_left ? curr->_left->_height : -1, curr->_right ? curr->_right->_height : -1) + 1;
		curr = curr->_parent;
	}
	return replacement;
}






//#include <iostream>
//using namespace std;
//template <class T>
//class BinarySearchTree;
//template <class T>
//class TreeNode {
//private:
//	T _item;
//	TreeNode<T>* _left;
//	TreeNode<T>* _right;
//	int _height;
//public:
//	TreeNode(T x) { _left = _right = NULL; _item = x; _height = 0; };
//	friend BinarySearchTree<T>;
//};
//template <class T>
//class BinarySearchTree {
//protected:
//	int _size;
//	TreeNode<T>* _root;
//	void _printTree(int indent, TreeNode<T>*, bool withHeight);
//	void _findheight(TreeNode<T>*);
//	TreeNode<T>* _insert(TreeNode<T>* current, T x);
//	bool _exist(TreeNode<T>* current, T x);
//	void _inOrderPrint(TreeNode<T>*);
//	void _postOrderPrint(TreeNode<T>*);
//	void _preOrderPrint(TreeNode<T>*);
//	T _searchMax(TreeNode<T>* current);
//	T _searchMin(TreeNode<T>* current);
//	int _balancetree(TreeNode<T>*);
//	TreeNode<T>* _rightRotation(TreeNode<T>*);
//	TreeNode<T>* _leftRotation(TreeNode<T>*);
//	void _destroySubTree(TreeNode<T>*);
//public:
//	BinarySearchTree() { _root = NULL; _size = 0; }
//	~BinarySearchTree();
//	int size() { return _size; };
//	void insert(T);
//	void printTree(bool withHeight = 1);
//	void inOrderPrint();
//	void postOrderPrint();
//	void preOrderPrint();
//	T searchMax();
//	T searchMin();
//	bool exist(T x);
//	T successor(T);
//};
//template <class T>
//void BinarySearchTree<T>::insert(T x) {
//	_root = _root ? _insert(_root, x) : new TreeNode<T>(x);
//	if (_size == 0) _size++;
//}
//template <class T>
//TreeNode<T>* BinarySearchTree<T>::_insert(TreeNode<T>* current, T x) {
//	if (current->_item > x)
//	{
//		if (current->_left)
//			current->_left = _insert(current->_left, x);
//		else
//		{
//			current->_left = new TreeNode<T>(x);
//			_size++;
//		}
//	}
//	else if (x > current->_item) {
//		if (current->_right)
//			current->_right = _insert(current->_right, x);
//		else
//		{
//			current->_right = new TreeNode<T>(x);
//			_size++;
//		}
//	}
//	else
//		return current;
//	_findheight(current);
//	int bal = _balancetree(current);
//	if (bal > 1) {
//		if (_balancetree(current->_right) < 0) {
//			current->_right = _rightRotation(current->_right);
//		}
//		current = _leftRotation(current);
//	}
//	else if (bal < -1) {
//		if (_balancetree(current->_left) > 0) {
//			current->_left = _leftRotation(current->_left);
//		}
//		current = _rightRotation(current);
//	}
//	return current;
//}
//template <class T>
//void BinarySearchTree<T>::printTree(bool withHeight) {
//	_printTree(0, _root, withHeight);
//}
//template <class T>
//void BinarySearchTree<T>::_printTree(int indent, TreeNode<T>* node, bool withHeight) {
//	if (!node)
//		return;
//	if (node->_right)
//		_printTree(indent + 2, node->_right, withHeight);
//	for (int i = 0; i < indent; i++)
//		cout << "  ";
//	cout << node->_item;
//	if (withHeight)
//		cout << "(h=" << node->_height << ")";
//	cout << endl;
//	if (node->_left)
//		_printTree(indent + 2, node->_left, withHeight);
//};
//template <class T>
//void BinarySearchTree<T>::_findheight(TreeNode<T>* node) {
//	int left = -1;
//	int right = -1;
//	if (node->_left) {
//		left = node->_left->_height;
//	}
//	if (node->_right) {
//		right = node->_right->_height;
//	}
//	if (left > right) node->_height = left + 1;
//	else node->_height = right + 1;
//}
//template <class T>
//void BinarySearchTree<T>::_destroySubTree(TreeNode<T>* node) {
//	if (node->_left)
//		_destroySubTree(node->_left);
//	if (node->_right)
//		_destroySubTree(node->_right);
//	delete node;
//}
//template <class T>
//BinarySearchTree<T> :: ~BinarySearchTree() {
//	if (_root)
//		_destroySubTree(_root);
//}
//template <class T>
//void BinarySearchTree<T>::preOrderPrint() {
//	_preOrderPrint(_root);
//	cout << endl;
//}
//template <class T>
//void BinarySearchTree<T>::_preOrderPrint(TreeNode<T>* node) {
//	if (!node) return;
//	cout << node->_item << " ";
//	_preOrderPrint(node->_left);
//	_preOrderPrint(node->_right);
//}
//template <class T>
//void BinarySearchTree<T>::inOrderPrint() {
//	_inOrderPrint(_root);
//	cout << endl;
//}
//template <class T>
//void BinarySearchTree<T>::_inOrderPrint(TreeNode<T>* node) {
//	if (!node) return;
//	_inOrderPrint(node->_left);
//	cout << node->_item << " ";
//	_inOrderPrint(node->_right);
//}
//template <class T>
//void BinarySearchTree<T>::postOrderPrint() {
//	_postOrderPrint(_root);
//	cout << endl;
//}
//template <class T>
//void BinarySearchTree<T>::_postOrderPrint(TreeNode<T>* node) {
//	if (!node) return;
//	_postOrderPrint(node->_left);
//	_postOrderPrint(node->_right);
//	cout << node->_item << " ";
//}
//template <class T>
//T BinarySearchTree<T>::searchMax() {
//	return _searchMax(_root);
//}
//template <class T>
//T BinarySearchTree<T>::_searchMax(TreeNode<T>* current) {
//	if (!current) return NULL;
//	TreeNode<T>* temp = current;
//	while (temp->_right) {
//		temp = temp->_right;
//	}
//	return temp->_item;
//}
//template<class T>
//T BinarySearchTree<T>::searchMin() {
//	return _searchMin(_root);
//}
//template <class T>
//T BinarySearchTree<T>::_searchMin(TreeNode<T>* current) {
//	if (!current) return NULL;
//	TreeNode<T>* temp = current;
//	while (temp->_left) {
//		temp = temp->_left;
//	}
//	return temp->_item;
//}
//template <class T>
//bool BinarySearchTree<T>::exist(T x) {
//	return _exist(_root, x);
//}
//template <class T>
//bool BinarySearchTree<T>::_exist(TreeNode<T>* current, T x) {
//	if (!current) return false;
//	while (current) {
//		if (current->_item < x) {
//			current = current->_right;
//		}
//		else if (current->_item > x) {
//			current = current->_left;
//		}
//		else {
//			return true;
//		}
//	}
//	return false;
//}
//template <class T>
//T BinarySearchTree<T>::successor(T x) {
//	if (!_root) return NULL;
//	TreeNode<T>* temp = _root;
//	T tempitem, previtem;
//	while (temp) {
//		tempitem = temp->_item;
//		if (x == tempitem && temp->_right) {
//			temp = temp->_right;
//
//			while (temp->_left) {
//				temp = temp->_left;
//
//			}
//			return temp->_item;
//		}
//		else if (tempitem > x) {
//			temp = temp->_left;
//			previtem = tempitem;
//		}
//		else {
//			temp = temp->_right;
//		}
//	}
//	return previtem;
//}
//template <class T>
//int BinarySearchTree<T>::_balancetree(TreeNode<T>* current) {
//	if (!_root) return NULL;
//	int left = -1;
//	int right = -1;
//	if (current->_right) {
//		right = current->_right->_height;
//	}
//	if (current->_left) {
//		left = current->_left->_height;
//	}
//	return right - left;
//}
//template <class T>
//TreeNode<T>* BinarySearchTree<T>::_leftRotation(TreeNode<T>* node) {
//	TreeNode<T>* newroot = node->_right;
//	node->_right = newroot->_left;
//	newroot->_left = node;
//	_findheight(node);
//	_findheight(newroot);
//	return newroot;
//}
//template <class T>
//TreeNode<T>* BinarySearchTree<T>::_rightRotation(TreeNode<T>* node) {
//	TreeNode<T>* newroot = node->_left;
//	node->_left = newroot->_right;
//	newroot->_right = node;
//	_findheight(node);
//	_findheight(newroot);
//	return newroot;
//}
