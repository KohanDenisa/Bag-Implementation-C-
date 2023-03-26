#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	index = 0;
	preindex = 0;
	//TODO - Implementation
}

void BagIterator::first() {
	//TODO - Implementation
	index = 0;
	preindex = 0;
}


void BagIterator::next() {
	//TODO - Implementation
	if (valid() == false) {
		throw std::exception();
	}

	preindex++;
	if (preindex == bag.data[index].count) {
		index++;
		preindex = 0;
	}
}


bool BagIterator::valid() const {
	//TODO - Implementation
	return index < bag.length;
}



TElem BagIterator::getCurrent() const
{
	//TODO - Implementation
	if (valid() == false) {
		throw std::exception();
	}
	return bag.data[index].element;
}
