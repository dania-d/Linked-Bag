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
    Node<ItemType> *tempPtr = headPtr;     // make tempPtr point to headPtr
    if (tempPtr != nullptr) {
        tempPtr = headPtr->getNext();   // make tempPtr point to 2nd node
        ItemType i = tempPtr->getItem();    // get data item of the 2nd node
        return remove(i);                   // call remove and pass in data item
    }

}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType &newEntry) {
    // we know we've reached the end of linked bag when the node points to nullptr
    // iterate
    Node<ItemType> *curPtr = headPtr; // set curPtr pointer to the head pointer
    int counter = 0;    // not necessary, but provides defense against going beyond end of the chain.
    while ((curPtr->getNext() != nullptr) &&
           (counter < itemCount)) { // After the last node is accessed, curPtr becomes nullptr, and the loop terminates
        // std::cout << "22222222in while loop";
        curPtr = curPtr->getNext();  // advance the pointer to the next node
        counter++;
    }
    if (curPtr->getNext() == nullptr) {    // extra check: == nullptr means we are at the end
        Node<ItemType> *newNodePtr = new Node<ItemType>(); // allocates new Node entry to which newNodePtr points
        newNodePtr->setItem(newEntry);  // set data item of the Node
        curPtr->setNext(newNodePtr);    // set newNodePtr as the last node
        itemCount++;
        return true;
    }
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    int count = 0;
    Node<ItemType> *currentPtr = headPtr;
    while (currentPtr != nullptr) {
        count++;
        currentPtr = currentPtr->getNext(); // advance the pointer to the next node
    }
    return count;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    Node<ItemType> *currentPtr = headPtr;
    return getCurrentSize340RecursiveHelper(currentPtr);
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType> *ptr) const {
    if (ptr == nullptr) {
        return 0;
    } else {
        return 1 + getCurrentSize340RecursiveHelper(ptr->getNext());
    }
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    Node<ItemType> *currentPtr = headPtr;

//    if(currentPtr == nullptr){
//        return 0;
//    } else {
//        return 1 + getCurrentSize340RecursiveNoHelper();
//    }
    return 0;

}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType &item) const {

    Node<ItemType> *curPtr = headPtr;

    return getFrequencyOf340RecursiveHelper(curPtr, item);
    //return 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType> *ptr, const ItemType &ref) const {
    if (ptr == nullptr) {
        return 0;
    } else if (ref == ptr->getItem()) {
        return 1 + getFrequencyOf340RecursiveHelper(ptr->getNext(), ref);
    } else {
        return getFrequencyOf340RecursiveHelper(ptr->getNext(), ref);
    }

}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType &) const {
    return 0;
}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {

    return nullptr;
}


