#pragma once
#include "Tree.h"

template <class T>
class BST :public Tree<T>
{
	void INORDER(Node<T>*);
	void PREORDER(Node<T>*);
	void POSTORDER(Node<T>*);
	bool SEARCH(Node<T>*, T);
public:
	void insert(T);
	void inorder();
	void preorder();
	void postorder();
	bool deleteValue(T);
	bool search(T);
};

template <class T>
bool BST<T>::SEARCH(Node<T>* p, T val)
{
	if (p != nullptr)
	{
		if (p->data == val)
		{
			cout << p->data << endl;
			return true;
		}
		else if (p->data > val)
			return SEARCH(p->leftChild, val);
		else
			return SEARCH(p->rightChild, val);


	}
	else
		return false;
}

template <class T>
bool BST<T>::search(T value)
{
	return SEARCH(Tree<T>::root, value);
}

template <class T>
bool BST<T>::deleteValue(T value)
{
	if (Tree<T>::root == nullptr)
		return false;

	else if (Tree<T>::root->leftChild == nullptr && Tree<T>::root->rightChild == nullptr)
	{
		if (value == Tree<T>::root->data)
		{
			delete Tree<T>::root;
			Tree<T>::root = nullptr;
			return true;
		}

		return false;
	}
	else if (Tree<T>::root->leftChild == nullptr && Tree<T>::root->rightChild != nullptr && value == Tree<T>::root->data)
	{
		Node<T>* temp = Tree<T>::root;
		Tree<T>::root = Tree<T>::root->rightChild;
		delete temp;
		temp = nullptr;
		return true;
	}
	else if (Tree<T>::root->leftChild != nullptr && Tree<T>::root->rightChild == nullptr && value == Tree<T>::root->data)
	{
		Node<T>* temp = Tree<T>::root;
		Tree<T>::root = Tree<T>::root->leftChild;
		delete temp;
		temp = nullptr;
		return true;
	}

	else 
	{ 
		Node<T>* p = Tree<T>::root;
		Node<T>* n = Tree<T>::root;

		while (value == n->data)
		{
			if (value < n->data)
			{
				p = n;
				n = n->leftChild;
			}

			else
			{
				p = n;
				n = n->rightChild;
			}

			if (n == nullptr)
				return false;

			
		}

		if (n->leftChild != nullptr && n->rightChild != nullptr)
		{
			Node<T>* d = n;

			p = d;
			n = d;

			n = n->rightChild;

			if (n->leftChild != nullptr)
			{
				while (1)
				{
					p = n;
					n = n->leftChild;

					if (n->leftChild == nullptr)
						break;
				}
			}
			
			
			d->data = n->data;
			value = n->data;

		}

		if (n->leftChild == nullptr && n->rightChild == nullptr)
		{
			if (value < p->data)
			{
				delete n;
				p->leftChild = nullptr;
			}

			else 
			{
				delete n;
				p->rightChild = nullptr;
			}
		}

		else if (n->leftChild == nullptr && n->rightChild != nullptr)
		{
			if (value < p->data)
			{
				p->leftChild = n->rightChild;
				delete n;
				n = nullptr;
			}

			else
			{
				p->rightChild = n->rightChild;
				delete n;
				n = nullptr;
			}
		}

		else if (n->leftChild != nullptr && n->rightChild == nullptr)
		{

			if (value < p->data)
			{
				p->leftChild = n->leftChild;
				delete n;
				n = nullptr;
			}

			else
			{
				p->rightChild = n->leftChild;
				delete n;
				n = nullptr;
			}

		}

		return true;
	}
	
}
template <class T>
void BST<T>::INORDER(Node<T>* p)
{
	if (p != nullptr)
	{
		INORDER(p->leftChild);
		cout << p->data << endl;
		INORDER(p->rightChild);
	}
}
template <class T>
void BST<T>::inorder()
{
	if (Tree<T>::root == nullptr)
		cout << "Tree is empty" << endl;
	else
		INORDER(Tree<T>::root);
}
template <class T>
void BST<T>::POSTORDER(Node<T>* p)
{
	if (p != nullptr)
	{
		POSTORDER(p->leftChild);
		POSTORDER(p->rightChild);
		cout << p->data << endl;
	}
}
template <class T>
void BST<T>::postorder()
{
	if (Tree<T>::root == nullptr)
		cout << "Tree is empty" << endl;
	else
		POSTORDER(Tree<T>::root);
}
template <class T>
void BST<T>::PREORDER(Node<T>* p)
{
	if (p != nullptr)
	{
		cout << p->data << endl;
		PREORDER(p->leftChild);
		PREORDER(p->rightChild);
	}
}
template <class T>
void BST<T>::preorder()
{
	if (Tree<T>::root == nullptr)
		cout << "Tree is empty" << endl;
	else
		PREORDER(Tree<T>::root);
}

template <class T>
void BST<T>::insert(T value)
{
	Node<T>* nn = new Node<T>;
	nn->data = value;
	nn->leftChild = nullptr;
	nn->rightChild = nullptr;

	if (Tree<T>::root == nullptr)
		Tree<T>::root = nn;

	else
	{
		Node<T>* temp = Tree<T>::root;
		while (1)
		{
			if (value < temp->data)
			{
				if (temp->leftChild == nullptr)
				{
					temp->leftChild = nn;
					break;
				}

				else
					temp = temp->leftChild;
			}

			else 
			{
				if (temp->rightChild == nullptr)
				{
					temp->rightChild= nn;
					break;
				}

				else
					temp = temp->rightChild; 
			}
		}
	}
}