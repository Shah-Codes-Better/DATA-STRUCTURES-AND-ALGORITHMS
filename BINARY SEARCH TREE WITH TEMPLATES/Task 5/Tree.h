#pragma once
#include "Node.h"

template <class T>
class Tree
{
protected:
	Node<T>* root;
public:
	Tree();
	virtual void insert(T) = 0;
	virtual void inorder() = 0;
	virtual void preorder() = 0;
	virtual void postorder() = 0;
	virtual bool deleteValue(T) = 0;
	virtual bool search(T) = 0;
};

template <class T>
Tree<T>::Tree<T>()
{
	root = nullptr;
}