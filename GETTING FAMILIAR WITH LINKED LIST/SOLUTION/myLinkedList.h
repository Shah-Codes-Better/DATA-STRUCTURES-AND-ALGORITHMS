#pragma once
#include "LinkedList.h"

class myLinkedList :public LinkedList
{
public:
	void insertAtHead(int); 
	void insertAtTail(int);	
	void display();
	int deleteFromTail();
	int deleteFromHead();
	bool isEmpty();
	bool deleteValue(int);
	void insertSorted(int);
	bool search(int);
	void deleteDuplicates();
	int numberOfNodes();
};

int myLinkedList::numberOfNodes()
{
	if (isEmpty())
		return 0;
	else
	{
		Node* temp = head;
		int count = 1;

		for (count; temp->next != nullptr; count++)
		{
			temp = temp->next;
		}
		return count;
	}
}

void myLinkedList::deleteDuplicates()
{
	if (isEmpty())
		cout << " LIST IS EMPTY " << endl;
	else if (head == tail)
		cout << " NO DUPLICATES POSSIBLE " << endl;
	else
	{
		
		Node* i = head;
		while (1)
		{
			Node* j = i;

			while (2)
			{
				if (j->next == nullptr)
					break;
				else if (i->data == j->next->data)
				{
					Node* temp = j->next->next;
					delete j->next;
					j->next = nullptr;
					j->next = temp;
				}
				else
					j = j->next;

			}

			if (i->next == nullptr)
				break;
			i = i->next;
		}
	}
}

bool myLinkedList::search(int value)
{
	if (isEmpty())
	{
		cout << " LIST IS EMPTY " << endl;
		return false;
	}
	else
	{
		Node* temp = head;
		while (1)
		{
			if (temp->data == value)
			{
				cout << " IS PRESENT " << endl;
				return true;
			}

			if (temp->next == nullptr)
			{
				cout << " ABSENT " << endl;
				return false;
			}

			temp = temp->next;

		}

	}
}

void myLinkedList::insertSorted(int value)
{
	if (head == nullptr && tail == nullptr) //first NODE to insert
	{
		Node* newNode;	//this is a WILD pointer
		newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;
		head = newNode;		// pointer = memory
		tail = newNode;
	}

	else if (value <= head->data) //smallest value
		insertAtHead(value);

	else if (value >= tail->data) //largest value
		insertAtTail(value);

	else //in between value
	{
		Node* newNode;	//this is a WILD pointer
		newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;

		Node* t1 = head;
		while (1)
		{
			if (value > t1->data && value <= t1->next->data)
			{
				newNode->next = t1->next;
				t1->next = newNode;
				break;
			}

			else
				t1 = t1->next;
		}
	}
}

bool myLinkedList::deleteValue(int value)
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "LL is empty" << endl;
		return false;
	}

	else if (head == tail) //single node case
	{
		if (value == head->data)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return true;
		}

		else
		{
			cout << " NOT FOUND " << endl;
			return false;
		}
	}

	else
	{
		if (value == head->data) //head data deletion
		{
			deleteFromHead();
			return true;
		}

		else if (value == tail->data) //tail data deletion
		{
			deleteFromTail();
			return true;
		}

		else //in between deletion
		{
			Node* t1 = head;
			while (1)
			{
				if (value == t1->next->data)
					break;

				else
					t1 = t1->next;

				if (t1 == tail) //t1->next == nullptr
				{
					cout << " NOT FOUND " << endl;
					return false;
				}
			}

			Node* t2 = t1->next;
			t1->next = t1->next->next;
			delete t2;
			t2 = nullptr;
			return true;
		}
	}
}

bool myLinkedList::isEmpty()
{
	if (head == nullptr && tail == nullptr)
		return true;

	return false;
}

int myLinkedList::deleteFromHead()
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "LL is empty" << endl;
		return NULL;
	}

	else if (head == tail) //single node case
	{
		int RV = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return RV;
	}

	else
	{
		int RV = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
		return RV;
	}
}

int myLinkedList::deleteFromTail()
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "LL is empty" << endl;
		return NULL;
	}

	else if (head == tail) //single node case
	{
		int RV = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return RV;
	}

	else
	{
		Node* temp = head;

		while (1)
		{
			if (temp->next == tail)
				break;

			temp = temp->next;
		}
		
		int returningValue = tail->data;
		delete tail;
		tail = temp;
		temp->next = nullptr;
		return returningValue;
	}
}

void myLinkedList::insertAtHead(int value)
{
	Node* newNode;	//this is a WILD pointer
	newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if (head == nullptr && tail == nullptr) //first NODE to insert
	{
		head = newNode;		// pointer = memory
		tail = newNode;
	}

	else //rest of the NODES
	{
		newNode->next = head;
		head = newNode;
	}
}

void myLinkedList::display()
{
	Node* temp = head;

	while (1)
	{
		if (temp == nullptr)
			break;

		cout << temp->data << endl;
		temp = temp->next;
	}
	

}

void myLinkedList::insertAtTail(int value)
{
	Node* newNode;	//this is a WILD pointer
	newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if (head == nullptr && tail == nullptr) //first NODE to insert
	{
		head = newNode;		// pointer = memory
		tail = newNode;
	}

	else //rest of the NODES
	{
		tail->next = newNode;
		tail = newNode;
	}
}
