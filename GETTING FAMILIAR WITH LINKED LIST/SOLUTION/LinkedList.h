#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList
{
protected:
	Node* head;
	Node* tail;
public:
	LinkedList();
	virtual void insertAtTail(int) = 0;
	virtual void display() = 0;
	virtual bool search(int) = 0;
	virtual void insertAtHead(int) = 0;
	virtual int deleteFromTail() = 0;
	virtual int deleteFromHead() = 0;
	virtual bool isEmpty() = 0;
	virtual bool deleteValue(int) = 0;
	virtual void insertSorted(int) = 0;
	virtual void deleteDuplicates() = 0;
	virtual int numberOfNodes() = 0;
};

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}