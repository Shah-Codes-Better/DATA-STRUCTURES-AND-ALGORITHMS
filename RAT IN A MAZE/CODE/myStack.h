#pragma once
#include "Stack.h"

template <class T>
class myStack :public Stack<T>
{
public:
	void push(T);
	T pop();
	T top();
	myStack(int ss);
	bool isEmpty();
	bool isFull();
	void display();
};

template <class T>
bool myStack<T>::isFull()
{
	if (Stack<T>::maxSize == Stack<T>::currentSize)
		return true;

	return false;
}

template <class T>
bool myStack<T>::isEmpty()
{
	if (Stack<T>::currentSize == 0)
		return true;

	return false;
}

template <class T>
void myStack<T>::display()
{
	cout << "Maximum Size: " << Stack<T>::maxSize << endl;
	cout << "Current Size: " << Stack<T>::currentSize << endl;

	for (int i = 0; i < Stack<T>::currentSize; i++)
		cout << i << ". " << Stack<T>::arr[i] << endl;
}


template <class T>
myStack<T>::myStack(int ss):Stack<T>(ss)
{

}

template <class T>
void myStack<T>::push(T value)
{
	if (!isFull())
	{
		Stack<T>::arr[Stack<T>::currentSize] = value;
		Stack<T>::currentSize++;
	}

	else
		cout << "Stack is already FULL" << endl;
}


template <class T>
T myStack<T>::pop()
{
	if (isEmpty())
	{
		cout << "Stack is Empty, returning ZERO" << endl;
		return 0;
	}

	Stack<T>::currentSize--;
	return Stack<T>::arr[Stack<T>::currentSize];
}


template <class T>
T myStack<T>::top()
{
	if (isEmpty())
	{
		cout << "Stack is Empty, returning ZERO" << endl;
		return 0;
	}

	return Stack<T>::arr[Stack<T>::currentSize-1];
}