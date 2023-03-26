#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	//TODO - Implementation
	length = 0;
	capacity = 2;
	data = new s_tuple[capacity]();

	if (data == nullptr) {
		cerr << "DynamicArray(): failed to allocate memory" << endl;
		exit(-1);
	}
}

//Complexity: O(n)
void Bag::add(TElem elem) {
	//TODO - Implementation
	if (length == capacity) {
		// double the capacity
		resize(capacity * 2);
	}
	int i, index = length;
	for (i = 0; i < length; i++)
		if (elem == data[i].element)
			index = i;
	if (index != length)
		data[index].count = data[index].count + 1;
	else
	{
		data[length].element = elem;
		data[length].count = 1;
		length++;
	}
}

//Complexity: O(n)
bool Bag::remove(TElem elem) {
	//TODO - Implementation
	int index = -1;
	for (int i = 0; i < length; i++)
		if (elem == data[i].element)
			index = i;
	if (index == -1)
		return false;
	if (data[index].count > 1)
		data[index].count--;
	else
	{
		for (unsigned int i = index; i < length - 1; i++)
			data[i] = data[i + 1];
		length--;
	}
	return true;
} 

//Complexity: O(n)
bool Bag::search(TElem elem) const {
	//TODO - Implementation
	for (int i = 0; i < length; i++)
		if (data[i].element == elem)
			return true;
	return false; 
}

//Complexity: O(n)
int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
	for (int i = 0; i < length; i++)
		if (data[i].element == elem)
			return data[i].count;
	return 0; 
}

//Complexity: O(n)
int Bag::size() const {
	//TODO - Implementation
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += data[i].count;
	return sum;
}

//Complexity: O(1)
bool Bag::isEmpty() const {
	//TODO - Implementation
	return length == 0;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	//TODO - Implementation
	delete[] data;
}


//Complexity: O(n)
void Bag::resize(unsigned int newCapacity) {

	this->capacity = newCapacity;
	// no realloc  in c++

	s_tuple* newData = new s_tuple[newCapacity]();
	if (newData == nullptr) {
		cerr << "resize(): failed to allocate memory" << endl;
		exit(-1);
	}
	// previous elements located in data
	// copy them in newData
	for (unsigned int i = 0; i < length; i++) {
		newData[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newData;
}

