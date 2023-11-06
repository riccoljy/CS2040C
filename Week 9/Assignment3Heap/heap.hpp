#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef heaphpp
#define heaphpp


////idk why need this nor the point of these overloads
//template <class T> bool operator<(T from, T to) { return from < to; }
//template <class T> bool operator== (T from, T s) { return from == s; }
//
template <class T>
void Heap<T>::_swapIndex(int from, int to) {
	T temp = _heap[from];
	_heap[from] = _heap[to];
	_heap[to] = temp;
}
//
////dont reference T direct?
template <class T>
void Heap<T>::_bubbleUp(int index) {

	int parentindex = floor((index - 1) / 2);
	//T prnt = _heap[parentindex];
	//T curr = _heap[index];

	while (_heap[index] > _heap[parentindex])
	{
		_swapIndex(index, parentindex);
		index = parentindex;
		parentindex = floor((index - 1) / 2);
		//prnt = _heap[parentindex];
	}
}
//
//
////dont reference T direct?
template <class T>
void Heap<T>::_bubbleDown(int index) {
	int indexL = index * 2 + 1;
	int indexR = indexL + 1;
	
	T L = _heap[indexL], R = _heap[indexR], curr = _heap[index];

	//when bubble DONT BUBBLE ONE AT TIME
	//if one at time, then just implement swap
	// when bubbledown, go all the way down until cannot go anymore

	while ((indexL <= _n - 1 || indexR <= _n - 1) /*&& (_heap[index] < _heap[indexR] || _heap[index]< _heap[indexL])*/) {
		if (curr > L && curr > R) return;
		else if (_heap[indexL] > _heap[indexR]) { _swapIndex(indexL, index); index = indexL; }
		else { _swapIndex(index, indexR); index = indexR; }

		
		indexL = index * 2 + 1;
		indexR = indexL + 1;
		//L = _heap[indexL];
		//R = _heap[indexR];
	}
}

template <class T>
void Heap<T>::insert(T item) {
	_heap[_n] = item;
	_bubbleUp(_n);
	_n++;
}

template <class T>
T Heap<T>::extractMax() {
	//ONLY FOR BINARY MAX HEAP if binary min heap then min will be index0
	T maxitem = _heap[0];
	//deleteIndex(0);
	_heap[0] = _heap[_n - 1];
	_n--;
	_bubbleDown(0);
	return maxitem;
}


template <class T>
void Heap<T>::printHeapArray() {
	for (int i = 0; i < _n; i++)
		cout << _heap[i] << " ";
	cout << endl;
}

template <class T>
int Heap<T>::_lookFor(T x){ // not a very good implementation, but just use this for now.
    int i;
	for (i = 0; i < _n; i++)
		if (_heap[i] == x) 
			return i;
    return -1;
}

//dont compare T direct?
template <class T>
void Heap<T>::decreaseKey(T from, T to)
{
	if (from < to) return increaseKey(from, to);
	int index = _lookFor(from);
	if (index == -1) return;
	_heap[index] = to;
	_bubbleDown(index);
}


template <class T>
void Heap<T>::increaseKey(T from, T to)
{
	if (from > to) return decreaseKey(from, to);
	int index = _lookFor(from);
	if (index == -1) return;
	_heap[index] = to;
	_bubbleUp(index);
}

template <class T>
void Heap<T>::deleteIndex(int index) {
	if (index > _n || index < 0) return;
	T throwaway = _heap[index]; T replacement = _heap[_n - 1];
	_swapIndex(index, _n - 1);
	_n--;

	//if dont subtract n first, in decrease key, it will take into account the invisible elements
	//decreaseKey(throwaway, replacement);
	


}

template <class T>
void Heap<T>::deleteItem(T x)
{
	int index = _lookFor(x);
	if (index == -1) return;
	deleteIndex(index);
}

template <class T>
void Heap<T>::printTree() {
    int parity = 0;
	if (_n == 0)
		return;
	int space = pow(2,1 + (int) log2f(_n)),i;
	int nLevel = (int) log2f(_n)+1;
	int index = 0,endIndex;
    int tempIndex;
	
	for (int l = 0; l < nLevel; l++)
	{
		index = 1;
        parity = 0;
		for (i = 0; i < l; i++)
			index *= 2;
		endIndex = index * 2 - 1;
		index--;
        tempIndex = index;
        while (index < _n && index < endIndex) {
            for (i = 0; i < space-1; i++)
                cout << " ";
            if(index==0)
                cout << "|";
            else if (parity)
                cout << "\\";
            else
                cout << "/";
            parity = !parity;
            for (i = 0; i < space; i++)
                cout << " ";
			index++;
		}
        cout << endl;
        index=tempIndex;
		while (index < _n && index < endIndex) {
			for (i = 0; i < (space-1-((int) log10(_heap[index]))); i++)
				cout << " ";
			cout << _heap[index];
			for (i = 0; i < space; i++)
				cout << " ";
			index++;
		}
		cout << endl;
		space /= 2;
	}
}



#endif
