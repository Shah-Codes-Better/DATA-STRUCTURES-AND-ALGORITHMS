#pragma once
#include "LinkedList.h"
template <typename T>
class myLinkedList :public LinkedList<T>
{
public:
	void insertAtHead(T); 
	void insertAtTail(T);	
	void display();
	T deleteFromTail();
	T deleteFromHead();
	bool isEmpty();
	bool deleteValue(T);
	void insertSorted(T);
	bool search(T);
	void deleteDuplicates();
	T numberOfNodes();
};

template <typename T>
T myLinkedList<T>::numberOfNodes()
{
	if (isEmpty())
		return 0;
	else
	{
		Node<T>* temp = LinkedList<T>::head;
		int count = 1;

		for (count; temp->next != nullptr; count++)
			temp = temp->next;
		
		return count;
	}
}
template <typename T>
void myLinkedList<T>::deleteDuplicates()
{
	if (isEmpty())
		cout << " LIST IS EMPTY " << endl;
	else if (LinkedList<T>::head == LinkedList<T>::tail)
		cout << " NO DUPLICATES POSSIBLE " << endl;
	else
	{
		
		Node<T>* i = LinkedList<T>::head;
		while (1)
		{
			Node<T>* j = i;
			while (2)
			{
				if (j->next == nullptr)
					break;
				else if (i->data == j->next->data)
				{
					Node<T>* temp = j->next->next;
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
template <typename T>
bool myLinkedList<T>::search(T value)
{
	if (isEmpty())
	{
		cout << " LIST IS EMPTY " << endl;
		return false;
	}
	else
	{
		Node<T>* temp = LinkedList<T>::head;
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
template <typename T>
void myLinkedList<T>::insertSorted(T value)
{
	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr) //first Node<T> to insert
	{
		Node<T>* newNode;	//this is a WILD pointer
		newNode = new Node<T>;
		newNode->data = value;
		newNode->next = nullptr;
		LinkedList<T>::head = newNode;		// pointer = memory
		LinkedList<T>::tail = newNode;
	}

	else if (value <= LinkedList<T>::head->data) //smallest value
		insertAtHead(value);

	else if (value >= LinkedList<T>::tail->data) //largest value
		insertAtTail(value);

	else //in between value
	{
		Node<T>* newNode;	//this is a WILD pointer
		newNode = new Node<T>;
		newNode->data = value;
		newNode->next = nullptr;

		Node<T>* t1 = LinkedList<T>::head;
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
template <typename T>
bool myLinkedList<T>::deleteValue(T value)
{
	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr)
	{
		cout << "LL is empty" << endl;
		return false;
	}

	else if (LinkedList<T>::head == LinkedList<T>::tail) //single Node<T> case
	{
		if (value == LinkedList<T>::head->data)
		{
			delete LinkedList<T>::head;
			LinkedList<T>::head = nullptr;
			LinkedList<T>::tail = nullptr;
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
		if (value == LinkedList<T>::head->data) //LinkedList<T>::head data deletion
		{
			deleteFromHead();
			return true;
		}

		else if (value == LinkedList<T>::tail->data) //LinkedList<T>::tail data deletion
		{
			deleteFromTail();
			return true;
		}

		else //in between deletion
		{
			Node<T>* t1 = LinkedList<T>::head;
			while (1)
			{
				if (value == t1->next->data)
					break;

				else
					t1 = t1->next;

				if (t1 == LinkedList<T>::tail) //t1->next == nullptr
				{
					cout << " NOT FOUND " << endl;
					return false;
				}
			}

			Node<T>* t2 = t1->next;
			t1->next = t1->next->next;
			delete t2;
			t2 = nullptr;
			return true;
		}
	}
}
template <typename T>
bool myLinkedList<T>::isEmpty()
{
	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr)
		return true;

	return false;
}
template <typename T>
T myLinkedList<T>::deleteFromHead()
{
	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr)
	{
		cout << "LL is empty" << endl;
		return NULL;
	}

	else if (LinkedList<T>::head == LinkedList<T>::tail) //single Node<T> case
	{
		T RV = LinkedList<T>::head->data;
		delete LinkedList<T>::tail;
		LinkedList<T>::head = nullptr;
		LinkedList<T>::tail = nullptr;
		return RV;
	}

	else
	{
		T RV = LinkedList<T>::head->data;
		Node<T>* temp = LinkedList<T>::head;
		LinkedList<T>::head = LinkedList<T>::head->next;
		delete temp;
		temp = nullptr;
		return RV;
	}
}
template <typename T>
T myLinkedList<T>::deleteFromTail()
{
	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr)
	{
		cout << "LL is empty" << endl;
		return NULL;
	}

	else if (LinkedList<T>::head == LinkedList<T>::tail) //single Node<T> case
	{
		T RV = LinkedList<T>::head->data;
		delete LinkedList<T>::tail;
		LinkedList<T>::head = nullptr;
		LinkedList<T>::tail = nullptr;
		return RV;
	}

	else
	{
		Node<T>* temp = LinkedList<T>::head;

		while (1)
		{
			if (temp->next == LinkedList<T>::tail)
				break;

			temp = temp->next;
		}
		
		T returningValue = LinkedList<T>::tail->data;
		delete LinkedList<T>::tail;
		LinkedList<T>::tail = temp;
		temp->next = nullptr;
		return returningValue;
	}
}
template <typename T>
void myLinkedList<T>::insertAtHead(T value)
{
	Node<T>* newNode;	//this is a WILD pointer
	newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;

	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr) //first Node<T> to insert
	{
		LinkedList<T>::head = newNode;		// pointer = memory
		LinkedList<T>::tail = newNode;
	}

	else //rest of the NODES
	{
		newNode->next = LinkedList<T>::head;
		LinkedList<T>::head = newNode;
	}
}
template <typename T>
void myLinkedList<T>::display()
{
	Node<T>* temp = LinkedList<T>::head;

	while (1)
	{
		if (temp == nullptr)
			break;

		cout << temp->data << endl;
		temp = temp->next;
	}
	

}
template <typename T>
void myLinkedList<T>::insertAtTail(T value)
{
	Node<T>* newNode;	//this is a WILD pointer
	newNode = new Node<T>;
	newNode->data = value;
	newNode->next = nullptr;

	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr) //first Node<T> to insert
	{
		LinkedList<T>::head = newNode;		// pointer = memory
		LinkedList<T>::tail = newNode;
	}

	else //rest of the NODES
	{
		LinkedList<T>::tail->next = newNode;
		LinkedList<T>::tail = newNode;
	}
}
