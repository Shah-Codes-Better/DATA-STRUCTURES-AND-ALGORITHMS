#pragma once

#include "myLinkedList.h"

class Stack
{
private:
	myLinkedList stk;
public:
	Stack();
	void push(int);
	int pop();
	int top();
	bool isEmpty();
	void display();
};

Stack::Stack()
{

}
void Stack::push(int value)
{
	stk.insertAtTail(value);
}
int Stack::pop()
{
	if (!stk.isEmpty())
		return stk.deleteFromTail();
	
	cout << " STACK IS EMPTY " << endl;
	return 0;
}
int Stack::top()
{
	if (!stk.isEmpty())
	{
		int rv = stk.deleteFromTail();
		stk.insertAtTail(rv);
		return rv;
	}
	cout << " STACK IS EMPTY " << endl;
	return 0;
}
bool Stack::isEmpty()
{
	return stk.isEmpty();
}
void Stack::display()
{
	stk.display();
}