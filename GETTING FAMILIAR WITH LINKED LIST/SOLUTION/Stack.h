#pragma once

#include "myLinkedList.h"

template <typename T>
class Stack
{
private:
	myLinkedList<T> stk;
public:
	Stack();
	void push(T);
	T pop();
	T top();
	bool isEmpty();
	void display();
};
template <typename T>
Stack<T>::Stack()
{

}
template <typename T>
void Stack<T>::push(T value)
{
	stk.insertAtTail(value);
}
template <typename T>
T Stack<T>::pop()
{
	if (!stk.isEmpty())
		return stk.deleteFromTail();
	
	cout << " STACK IS EMPTY " << endl;
	return 0;
}
template <typename T>
T Stack<T>::top()
{
	if (!stk.isEmpty())
	{
		T rv = stk.deleteFromTail();
		stk.insertAtTail(rv);
		return rv;
	}
	cout << " STACK IS EMPTY " << endl;
	return 0;
}
template <typename T>
bool Stack<T>::isEmpty()
{
	return stk.isEmpty();
}
template <typename T>
void Stack<T>::display()
{
	stk.display();
}