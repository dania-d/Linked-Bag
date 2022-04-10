//	LinkedBag340.cpp
//	Created by: CSC340

/*
===>					<===
===>  PLEASE ADD CODE	<===
===>					<===
*/

#include "LinkedBag.h"

template<typename ItemType>
// template parameter declaration
bool LinkedBag<ItemType>::removeSecondNode340() // function template definition
{
// if pointer != nullptr
// pointer->getNext()
    Node<ItemType>* tempPtr = headPtr;     // make tempPtr point to headPtr
    if(headPtr != nullptr){
        tempPtr = headPtr->getNext();   // make tempPtr point to 2nd node
        ItemType i = tempPtr->getItem();    // get data item of the 2nd node
        return remove(i);                   // call remove and pass in data item
    }
   // return true;
}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType &) {
    return true;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType &) const {
    return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType &) const {
    return 0;
}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType> *) const {
    return 0;
}
