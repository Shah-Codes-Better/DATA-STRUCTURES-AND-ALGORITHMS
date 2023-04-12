#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack
{
protected:
	T* arr;
	int maxSize;
	int currentSize;
public:
	virtual void push(T) = 0; 	//add Value
	virtual T pop() = 0;		//remove Value
	virtual T top() = 0;
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
	Stack(int);
};

template <class T>
Stack<T>::Stack(int s)
{
	arr = new T[s];
	maxSize = s;
	currentSize = 0;
}