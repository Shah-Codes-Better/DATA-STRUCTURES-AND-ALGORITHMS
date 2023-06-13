#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node* rightChild;
	Node* leftChild;
};