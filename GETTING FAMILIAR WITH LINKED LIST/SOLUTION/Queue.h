#pragma once

#include "myLinkedList.h"

template <typename T>
class Queue
{
private:
	myLinkedList<T> que;
public:
	Queue();
	void enqueue(T);
	T dequeue();
	T front();
	bool isEmpty();
	void display();
};
template <typename T>
Queue<T>::Queue()
{

}
template <typename T>
void Queue<T>::enqueue(T value)
{
	que.insertAtTail(value);
}
template <typename T>
T Queue<T>::dequeue()
{
	if (!que.isEmpty())
		return que.deleteFromHead();

	cout << " QUEUE IS EMPTY " << endl;
	return 0;
}
template <typename T>
T Queue<T>::front()
{
	if (!que.isEmpty())
	{
		T rv = que.deleteFromHead();
		que.insertAtHead(rv);
		return rv;
	}
	cout << " QUEUE IS EMPTY " << endl;
	return 0;
}
template <typename T>
bool Queue<T>::isEmpty()
{
	return que.isEmpty();
}
template <typename T>
void Queue<T>::display()
{
	que.display();
}