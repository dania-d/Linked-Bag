//  Node.cpp
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "Node.h"

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

template<typename ItemType>
// default constructor
Node<ItemType>::Node() : item(), next(nullptr) {}
// 2nd constructor
template<typename ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr) {}
// 3rd constructor
template<typename ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
        item(anItem), next(nextNodePtr) {}

template<typename ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
    next = nextNodePtr;
}

template<typename ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
}

template<typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return next;
}