#pragma once

#include "myLinkedList.h"

class Queue
{
private:
	myLinkedList que;
public:
	Queue();
	void enqueue(int);
	int dequeue();
	int front();
	bool isEmpty();
	void display();
};

Queue::Queue()
{

}
void Queue::enqueue(int value)
{
	que.insertAtTail(value);
}
int Queue::dequeue()
{
	if (!que.isEmpty())
		return que.deleteFromHead();

	cout << " QUEUE IS EMPTY " << endl;
	return 0;
}
int Queue::front()
{
	if (!que.isEmpty())
	{
		int rv = que.deleteFromHead();
		que.insertAtHead(rv);
		return rv;
	}
	cout << " QUEUE IS EMPTY " << endl;
	return 0;
}
bool Queue::isEmpty()
{
	return que.isEmpty();
}
void Queue::display()
{
	que.display();
}