#pragma once
#include <iostream>
using namespace std;


class Node
{
private:
	int data;
	int count;
	Node* rightChild;
	Node* leftChild;
public:
	Node();
	Node(int);
	Node(const Node&);
	Node& operator = (const Node&);
	~Node();

	void setData(int);
	void setCount(int);
	void setRight(Node*);
	void setLeft(Node*);
	
	int getData();
	int getCount();
	Node* getRight();
	Node* getLeft();

};
Node::Node()
{
	count = 0;
	rightChild = nullptr;
	leftChild = nullptr;
}
Node::Node(int value)
{
	data = value;
	count = 1;
	rightChild = nullptr;
	leftChild = nullptr;
}
Node::Node(const Node& obj)
{
	data = obj.data;
	count = obj.count;
	leftChild = obj.leftChild;
	rightChild = obj.rightChild;
}
Node& Node::operator=(const Node& obj)
{
	data = obj.data;
	count = obj.count;
	leftChild = obj.leftChild;
	rightChild = obj.rightChild;

	return *this;
}
Node::~Node()
{
	rightChild = nullptr;
	leftChild = nullptr;
	count = 0;
	data = 0;

}
void Node::setData(int data)
{
	this->data = data;
}
void Node::setCount(int count)
{
	this->count = count;
}
void Node::setRight(Node* r)
{
	rightChild = r;
}
void Node::setLeft(Node* l)
{
	leftChild = l;
}

int Node::getData()
{
	return data;
}
int Node::getCount()
{
	return count;
}
Node* Node::getRight()
{
	Node* temp = rightChild;
	return temp;
}
Node* Node::getLeft()
{
	Node* temp = leftChild;
	return temp;
}
