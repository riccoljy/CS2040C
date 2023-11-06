#include "BST.h"


void testInsertion1(bool printWithHeight = true);
void testInsertion2(bool printWithHeight = true);
void testSuccessor();
void testSearchMinMax();
void testExist();
void suggestedHiddenCase1();
void suggestedHiddenCase1b();
void suggestedHiddenCase2();
void excerciseTest(bool printWithHeight = true);


int main() {

	testInsertion1(true);

	testExist();
	testSearchMinMax();
	testSuccessor();
	testInsertion2(true);

	excerciseTest();

	//BinarySearchTree<int> bst;

	//cout << bst.size() << endl << "tree ="; bst.printTree(); cout << endl;
	//cout << "in="; bst.inOrderPrint();
	//cout << "pre="; bst.preOrderPrint();
	//cout << "post="; bst.postOrderPrint();
	//cout << "max=" << bst.searchMax(); cout << endl;
	//cout << "min=" << bst.searchMin(); cout << endl;
	//cout << "2exist=" << bst.exist(2); cout << endl;
	//cout << "2successor=" << bst.successor(2); cout << endl;

	//bst.insert(12);
	//bst.insert(15);
	//bst.insert(18);
	//bst.insert(-123456);

	//cout << bst.size() << endl << "tree ="<<endl; bst.printTree(); cout << endl;
	//cout << "in="; bst.inOrderPrint();
	//cout << "pre="; bst.preOrderPrint();
	//cout << "post="; bst.postOrderPrint();
	//cout << "max=" << bst.searchMax(); cout << endl;
	//cout << "min=" << bst.searchMin(); cout << endl;
	//cout << "2exist=" << bst.exist(2); cout << endl;
	//cout << "2successor=" << bst.successor(2); cout << endl << endl;

	//bst.insert(2);
	//bst.insert(120);
	//bst.insert(100);
	//bst.insert(110);
	//bst.insert(10);
	//bst.insert(1);



	//cout << bst.size() << endl << "tree ="<<endl; bst.printTree(); cout << endl;
	//cout << "in="; bst.inOrderPrint();
	//cout << "pre="; bst.preOrderPrint();
	//cout << "post="; bst.postOrderPrint();
	//cout << "max=" << bst.searchMax(); cout << endl;
	//cout << "min=" << bst.searchMin(); cout << endl;
	//cout << "2exist=" << bst.exist(2); cout << endl;
	//cout << "2successor=" << bst.successor(2); cout << endl << endl;
}

void excerciseTest(bool printWithHeight) {

	cout << "Insertion Test 1" << endl;
	int array[] = { 7, 3, 1, 0, 2, 5, 4, 6, 11, 9, 8, 10, 13, 12, 14 };
	BinarySearchTree<int> bsti;
	for (int i = 0; i < 15; i++)
		bsti.insert(array[i]);

	bsti.printTree(printWithHeight);
	cout << endl << endl;
	cout << "The size of the tree is " << bsti.size() << endl;
	cout << "Pre-order Traversal:" << endl;
	bsti.preOrderPrint();
	cout << "In-order Traversal:" << endl;
	bsti.inOrderPrint();
	cout << "Post-order Traversal:" << endl;
	bsti.postOrderPrint();

	cout << endl << endl;
}

void testInsertion1(bool printWithHeight) {

	cout << "Insertion Test 1" << endl;
	int array[] = { 7, 3, 1, 0, 2, 5, 4, 6, 11, 9, 8, 10, 13, 12, 14 };
	BinarySearchTree<int> bsti;
	for (int i = 0; i < 15; i++)
		bsti.insert(array[i]);

	bsti.printTree(printWithHeight);
	cout << endl << endl;
	cout << "The size of the tree is " << bsti.size() << endl;
	cout << "Pre-order Traversal:" << endl;
	bsti.preOrderPrint();
	cout << "In-order Traversal:" << endl;
	bsti.inOrderPrint();
	cout << "Post-order Traversal:" << endl;
	bsti.postOrderPrint();

	cout << "Level order traversal" << endl;
	//bsti.LOT();

	cout << endl << endl;

	
}

void testExist() {

	cout << "Exist Test" << endl;
	BinarySearchTree<int> bsti;
	cout << "Numbers inserted in the tree: ";
	for (int i = 0; i < 11; i++)
	{
		cout << i * 6 << " ";
		bsti.insert(i * 6);
	}

	//	bsti.printTree(false);
	cout << endl << endl;

	for (int i = 0; i < 70; i += 8)
		cout << "The number " << i << (bsti.exist(i) ? " exists " : " does not exist ") << "in the tree" << endl;
	cout << endl << endl;
}

void testInsertion2(bool printWithHeight) {

	cout << "Insertion Test 2" << endl;
	cout << "The tree shape should be the same as Test 1" << endl;
	cout << "if you have done the balancing correctly." << endl;
	BinarySearchTree<int> bsti;
	for (int i = 0; i < 15; i++)
		bsti.insert(i);

	bsti.printTree(printWithHeight);
	cout << endl << endl;
	cout << "The size of the tree is " << bsti.size() << endl;
	cout << "Pre-order Traversal:" << endl;
	bsti.preOrderPrint();
	cout << "In-order Traversal:" << endl;
	bsti.inOrderPrint();
	cout << "Post-order Traversal:" << endl;
	bsti.postOrderPrint();

	cout << endl << endl;
}

void testSearchMinMax() {

	cout << "Search Min/Max Test" << endl;
	int array[] = { 7, 3, 1, 0, 2, 5, 4, 6, 11, 9, 8, 10, 13, 12, 14 };
	BinarySearchTree<int> bsti;
	for (int i = 0; i < 15; i++)
		bsti.insert(array[i]);

	cout << "The minimum number in the tree is " << bsti.searchMin() << endl;
	cout << "The maximum number in the tree is " << bsti.searchMax() << endl;
	cout << endl;

}

void testSuccessor() {

	cout << "Successor Test" << endl;
	BinarySearchTree<int> bsti;
	cout << "Numbers inserted in the tree: ";
	for (int i = 0; i < 11; i++)
	{
		cout << i * 7 << " ";
		bsti.insert(i * 7);
	}

//	bsti.printTree(false);
	cout << endl << endl;

	for (int i = 0; i < 70; i+=10)
		cout << "The successor of " << i << " in the BST is " << bsti.successor(i) << endl;
	cout << endl << endl;
}
