//  LinkedBag.cpp
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <cstddef>
#include "Node.h"
#include "LinkedBag.h"

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

//The following default constructor initializes the head pointer and the current
//number of items in the bag:
template<typename ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {}    // default constructor initializes the head pointer and current num of items in the bag

template<typename ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag) {
    itemCount = aBag.itemCount;
    Node<ItemType>* origChainPtr = aBag.headPtr;    // pointer of type Node pointing to head node in aBag

    if (origChainPtr == nullptr) {
        headPtr = nullptr;
    }
    else {
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        Node<ItemType>* newChainPtr = headPtr;
        origChainPtr = origChainPtr->getNext();

        while (origChainPtr != nullptr)
        {
            ItemType nextItem = origChainPtr->getItem();
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }

        newChainPtr->setNext(nullptr);
    }
}

template<typename ItemType>
LinkedBag<ItemType>::~LinkedBag() {
    clear();
}

template<typename ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

// --Method to add new item to chain--
// its most convenient to add a new item at beginning of LinkedBag because the first node
// is the only one we can access directly
//
// make headPtr point to the new node, and the new node must point to the node that had been
// at the beginning of the chain.
template<typename ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry) {
    Node<ItemType>* nextNodePtr = new Node<ItemType>(); // allocates a node to which nextNodePtr points
    nextNodePtr->setItem(newEntry);     // set data item of the new node (nextNodePtr)
    nextNodePtr->setNext(headPtr);  // nextNodePtr points to chain
    headPtr = nextNodePtr;                      // nextNodePtr is now first node (head pointer)
    itemCount++;
    return true;
}

// --Method to retrieve the entries that are in a bag and returns them to the client within a vector
template<typename ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
    std::vector<ItemType> bagContents;
    Node<ItemType>* curPtr = headPtr;   // curPtr points to the current node ( starts at head pointer and keeps track of current position within the chain)
    int counter = 0;
    // traverse the chain of nodes
    while ((curPtr != nullptr) && (counter < itemCount)) {
        bagContents.push_back(curPtr->getItem());   // access data item of current node/ copy it to bagContents
        curPtr = curPtr->getNext(); // advance the current pointer to the next node
        counter++;
    }

    return bagContents;
}

template<typename ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);

    if (canRemoveItem) {
        entryNodePtr->setItem(headPtr->getItem());
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        itemCount--;
    }

    return canRemoveItem;
}

// --Method to delete node objects
// Our method add uses the operator new to create a new node object and place it on the heap.
// Because C++ does not have garbage collection as Java does, it is our class’s responsibility to
// ensure that the object is removed from the heap using delete
template<typename ItemType>
void LinkedBag<ItemType>::clear() {
    Node<ItemType>* nodeToDeletePtr = headPtr;

    while (headPtr != nullptr) {
        headPtr = headPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = headPtr;
    }

    itemCount = 0;
}
//-- Method to count the number of times the object occurs in the linked chain
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
    int frequency = 0;
    int counter = 0;
    Node<ItemType>* curPtr = headPtr;

    while ((curPtr != nullptr) && (counter < itemCount)) {
        if (anEntry == curPtr->getItem()) {
            frequency++;
        }
        counter++;
        curPtr = curPtr->getNext();
    }

    return frequency;
}

template<typename ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const {
    return (getPointerTo(anEntry) != nullptr);
}

// Returns either a pointer to the node containing a given entry
// or the null pointer if the entry is not in the bag.
template<typename ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const {
    bool found = false;
    Node<ItemType>* curPtr = headPtr;

    while (!found && (curPtr != nullptr)) {
        if (anEntry == curPtr->getItem()) {
            found = true;
        }
        else {
            curPtr = curPtr->getNext();
        }
    }

    return curPtr;
}