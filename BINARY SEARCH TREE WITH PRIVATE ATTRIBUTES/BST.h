#pragma once
#include "Node.h"

class BST
{
private:

	Node* root;

	void INORDER(Node*);
	void PREORDER(Node*);
	void POSTORDER(Node*);
	bool SEARCH(Node*, int, int&);
	int COUNT(Node*, int);
public:
	BST();
	~BST();

	void insert(int);
	void inorder();
	void preorder();
	void postorder();
	bool deleteValue(int);
	int count(int);
	bool searchtree(int,int&,int&);
};

int BST::COUNT(Node* temp, int val)
{
	if (temp != nullptr)
	{
		if (val == temp->getData())
			return temp->getCount();
		else if (val < temp->getData())
			return COUNT(temp->getLeft(), val);
		else
			return COUNT(temp->getRight(), val);
	}
	else
		return -1;
}

int BST::count(int value)
{
	int RV = COUNT(root, value);
	if (RV == -1)
		cout << " NOT FOUND, RETURNING -1 " << endl;
	return RV;
}

bool BST::SEARCH(Node* temp, int val, int& c)
{
	if (temp != nullptr)
	{
		c++;
		if (val == temp->getData())
			return true;
		else if (val < temp->getData())
			return SEARCH(temp->getLeft(), val, c);
		else
			return SEARCH(temp->getRight(), val, c);
	}
	else
		return false;
}

bool BST::searchtree(int value, int& comp, int& lev)
{
	if (SEARCH(root,value, comp))
	{
		lev = comp - 1; // LEVEL IS ALWAYS ONE LESS THAN NO. OF COMPARISONS
		return true;
	}
	else
	{
		lev = -1;
		return false;
	}

}


bool BST::deleteValue(int value)
{
	if (root == nullptr)
		return false;
	else if (root->getLeft() == nullptr && root->getRight() == nullptr)
	{
		if (value == root->getData())
		{
			root->setCount(root->getCount() - 1);

			if (root->getCount() == 0)
			{
				delete root;
				root = nullptr;
			}
			return true;
		}
		return false;
	}
	else if (root->getLeft() == nullptr && root->getRight() != nullptr && root->getData() == value)
	{
		root->setCount(root->getCount() - 1);
		if (root->getCount() == 0)
		{
			Node* temp = root;
			root = root->getRight();
			delete temp;
			temp = nullptr;
		}
		return true;
	}
	else if (root->getLeft() != nullptr && root->getRight() == nullptr && root->getData() == value)
	{
		root->setCount(root->getCount() - 1);
		if (root->getCount() == 0)
		{
			Node* temp = root;
			root = root->getLeft();
			delete temp;
			temp = nullptr;
		}
		return true;
	}
	else
	{
		Node* p = root;
		Node* n = root;

		while (1)
		{
			if (value == n->getData())
			{
				n->setCount(n->getCount() - 1);
				break;
			}
			if (value < n->getData())
			{
				p = n;
				n = n->getLeft();
			}

			else
			{
				p = n;
				n = n->getRight();
			}

			if (n == nullptr)
				return false;

		}

		if (n->getCount() == 0)
		{
			if (n->getLeft() != nullptr && n->getRight() != nullptr)
			{
				Node* d = n;

				p = d;
				n = d;

				n = n->getRight();

				if (n->getLeft() != nullptr)
				{
					while (1)
					{
						p = n;
						n = n->getLeft();

						if (n->getLeft() == nullptr)
							break;
					}
				}

				d->setData(n->getData());
				d->setCount(n->getCount());

				value = n->getData();
			}

			if (n->getLeft() == nullptr && n->getRight() == nullptr)
			{

				if (value < p->getData())
				{
					delete n;
					p->setLeft(nullptr);
				}

				else
				{
					delete n;
					p->setRight(nullptr);
				}
			}

			else if (n->getLeft() == nullptr && n->getRight() != nullptr)
			{


				if (value < p->getData())
				{
					p->setLeft(n->getRight());
					delete n;
					n = nullptr;
				}

				else
				{
					p->setRight(n->getRight());
					delete n;
					n = nullptr;
				}
			}

			else if (n->getLeft() != nullptr && n->getRight() == nullptr)
			{

				if (value < p->getData())
				{
					p->setLeft(n->getLeft());
					delete n;
					n = nullptr;
				}

				else
				{
					p->setRight(n->getLeft());
					delete n;
					n = nullptr;
				}

			}
		}
		return true;

	}
}

void BST::POSTORDER(Node* temp)
{
	if (temp != nullptr)
	{
		POSTORDER(temp->getLeft());
		for (int i = 0; i < temp->getCount(); i++)
			cout << temp->getData() << endl;
		POSTORDER(temp->getRight());

	}
}

void BST::postorder()
{
	if (root == nullptr)
		cout << " EMPTY " << endl;
	else
		POSTORDER(root);

}

void BST::PREORDER(Node* temp)
{
	if (temp != nullptr)
	{
		PREORDER(temp->getLeft());
		for (int i = 0; i < temp->getCount(); i++)
			cout << temp->getData() << endl;
		PREORDER(temp->getRight());

	}
}

void BST::preorder()
{
	if (root == nullptr)
		cout << " EMPTY " << endl;
	else
		PREORDER(root);

}


void BST::INORDER(Node* temp)
{
	if (temp != nullptr)
	{
		INORDER(temp->getLeft());
		for (int i = 0; i < temp->getCount(); i++)
			cout << temp->getData() << endl;
		INORDER(temp->getRight());

	}
}

void BST::inorder()
{
	if (root == nullptr)
		cout << " EMPTY " << endl;
	else
		INORDER(root);

}

void BST::insert(int value)
{
	Node* nn = new Node(value);
	if (root == nullptr)
		root = nn;
	else
	{
		Node* temp = root;
		while (1)
		{
			if (value == temp->getData())

			{
				temp->setCount(temp->getCount() + 1);
				delete nn;
				nn = nullptr;
				break;
			}
			if (value < temp->getData())
			{
				if (temp->getLeft() == nullptr)
				{
					temp->setLeft(nn);
					break;
				}

				else
					temp = temp->getLeft();
			}

			else
			{
				if (temp->getRight() == nullptr)
				{
					temp->setRight(nn);
					break;
				}

				else
					temp = temp->getRight();
			}
		}
	}
}

BST::BST()
{
	this->root = nullptr;
}
BST::~BST()
{
	while (root != nullptr)
		deleteValue(root->getData());
}