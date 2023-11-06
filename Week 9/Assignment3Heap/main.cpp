#include "heap.h"
#include "customer.h"


void heapTest();
void hiddenHeapTest();
void customerQueueTest();

int main() {
    heapTest();
    customerQueueTest(10);
 
    //Heap<int> ih;
    //int arr[] = { 100, 80, 60, 50, 61, 20, 55, 90, 40, 70 };
    //for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) ih.insert(arr[i]);
    //cout<< ih.lookFor(70)<<endl;

    //cout << "before:"; ih.printTree();
    //cout << endl << "after:";
    //ih.deleteIndex(4);
    //ih.printHeapArray();
    //ih.printTree();
    
}


void heapTest(){
    
    Heap<int> ih;
	cout << "Interger Heap Test" << endl;
    for (int i=1; i < 16; i++)
    {
        ih.insert(i);
		cout << "Insert " << i << " into the heap." << endl;
		cout << "Heap Array:";
		ih.printHeapArray();
		cout << endl;
        ih.printTree();
        cout << endl << endl;
    }
    

    cout << "Increasing 13 to 99" << endl;
    ih.increaseKey(13,99);
	cout << "Heap Array:";
	ih.printHeapArray();
	cout << endl;
	ih.printTree();
	cout << endl << endl;
    
    cout << "Deleting the item 2" << endl;
    ih.deleteItem(2);
	cout << "Heap Array:";
	ih.printHeapArray();
	cout << endl;
	ih.printTree();
	cout << endl << endl;
    
    cout << "Deleting the item 10" << endl;
    ih.deleteItem(10);
	cout << "Heap Array:";
	ih.printHeapArray();
	cout << endl;
	ih.printTree();
	cout << endl << endl;
    
    cout << "Decreasing the key 15 to 13)"  << endl;
    ih.decreaseKey(15,13);
	cout << "Heap Array:";
	ih.printHeapArray();
	cout << endl;
	ih.printTree();
	cout << endl << endl;



    for (int i = 1; i < 12; i++)
    {
        cout << "Extract Max: Max = ";
        cout << ih.extractMax() << endl;
        ih.printTree();
        cout << endl << endl;
    }

}