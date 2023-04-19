#include "myLinkedList.h"
#include "Stack.h"
#include "Queue.h"

void task1();
void task2();
void task3();
void task4();
void task5();

int main()
{
	//task1();
	//task2();
	//task3();
	//task4();
	//task5();

	return 0;
}

void task1()
{
	myLinkedList<int> obj;

	char opt = '\0';

	while (1)
	{
		cout << " TO ADD A NODE, PRESS 1 " << endl;
		cout << " TO INSERT A NODE IN SORTED ORDER, PRESS 2 " << endl;
		cout << " TO DELETE A NODE FROM LINKED LIST, PRESS 3 " << endl;
		cout << " TO SEARCH THE LIST, PRESS 4 " << endl;
		cout << " TO DISPLAY THE LINKED LIST, PRESS 5 " << endl;
		cout << " TO EXIT, PRESS 0 " << endl;

		cin >> opt;

		system("CLS");

		if (opt == '0')
			break;
		else if (opt == '1')
		{
			int value;
			cout << " ENTER THE VALUE TO BE INSERTED = " << endl << " ";
			cin >> value;
			obj.insertSorted(value);            // can use insertAtHead & insert&Tail, but better to use sorted insertion
		}
		else if (opt == '2')
		{
			int value;
			cout << " ENTER THE VALUE TO BE INSERTED = " << endl << " ";
			cin >> value;
			obj.insertSorted(value);
		}
		else if (opt == '3')
		{
			int value;
			cout << " ENTER THE VALUE TO BE DELETED = " << endl << " ";
			cin >> value;
			obj.deleteValue(value);
		}
		else if (opt == '4')
		{
			int value;
			cout << " ENTER THE VALUE TO BE DELETED = " << endl << " ";
			cin >> value;
			obj.search(value);
		}
		else if (opt == '5')
		{
			obj.display();
		}
		else
			cout << " PLZ ENTER VALID INPUT " << endl;
	}

}
void task2()
{
	Stack<int> stk;
	char opt = '\0';

	while (1)
	{
		cout << " TO PUSH AN ELEMENT, PRESS 1 " << endl;
		cout << " TO POP AN ELEMENT, PRESS 2 " << endl;
		cout << " TO DISPLAY THE TOP ELEMENT, PRESS 3 " << endl;
		cout << " TO DISPLAY THE STACK, PRESS 4 " << endl;
		cout << " TO CHECK IF THE STACK IS EMPTY, PRESS 5 " << endl;
		cout << " TO END THE PROGRAM, PRESS 0 " << endl;

		cin >> opt;

		system("cls");

		if (opt == '0')
			break;
		else if (opt == '1')
		{
			int temp = 0;
			cout << " ENTER VALUE = " << endl << " ";
			cin >> temp;
			stk.push(temp);
		}
		else if (opt == '2')
		{
			cout << " POPPED VALUE = " << stk.pop() << endl;;
		}
		else if (opt == '3')
		{
			cout << " TOP ELEMENT = " << stk.top() << endl;
		}
		else if (opt == '4')
		{
			stk.display();
		}
		else if (opt == '5')
		{
			if (stk.isEmpty())
				cout << " STACK IS EMPTY " << endl;
			else
				cout << " NOT EMPTY " << endl;
		}
		else
		{
			cout << " PLZ ENTER VALID INPUT " << endl;
		}
	}
}
void task3()
{
	Queue<int> que;
	char opt = '\0';

	while (1)
	{
		cout << " TO ENQUEUE AN ELEMENT, PRESS 1 " << endl;
		cout << " TO DEQUEUE AN ELEMENT, PRESS 2 " << endl;
		cout << " TO DISPLAY THE FRONT ELEMENT, PRESS 3 " << endl;
		cout << " TO DISPLAY THE QUEUE, PRESS 4 " << endl;
		cout << " TO CHECK IF THE QUEUE IS EMPTY, PRESS 5 " << endl;
		cout << " TO END THE PROGRAM, PRESS 0 " << endl;

		cin >> opt;

		system("cls");

		if (opt == '0')
			break;
		else if (opt == '1')
		{
			int temp = 0;
			cout << " ENTER VALUE = " << endl << " ";
			cin >> temp;
			que.enqueue(temp);
		}
		else if (opt == '2')
		{
			cout << " DEQUEUED VALUE = " << que.dequeue() << endl;;
		}
		else if (opt == '3')
		{
			cout << " FRONT ELEMENT = " << que.front() << endl;
		}
		else if (opt == '4')
		{
			que.display();
		}
		else if (opt == '5')
		{
			if (que.isEmpty())
				cout << " QUEUE IS EMPTY " << endl;
			else
				cout << " NOT EMPTY " << endl;
		}
		else
		{
			cout << " PLZ ENTER VALID INPUT " << endl;
		}
	}
}
void task4()
{
	myLinkedList<int> list;

	char opt = '\0';

	while (1)
	{
		cout << " TO ADD A VALUE, PRESS 1 " << endl;
		cout << " TO REMOVE DUPLICATES, PRESS 2 " << endl;
		cout << " TO DISPLAY THE LIST, PRESS 3 " << endl;
		cout << " TO EXIT, PRESS 0 " << endl;

		cin >> opt;
		system("cls");

		if (opt == '0')
			break;
		else if (opt == '1')
		{
			int num = 0;
			cout << " ENTER A NUMBER = " << endl << " ";
			cin >> num;
			list.insertAtTail(num);
		}
		else if (opt == '2')
		{
			list.deleteDuplicates();
		}
		else if (opt == '3')
		{
			list.display();
		}
		else
			cout << " PLZ ENTER VALID INPUT " << endl;
	}
}
void task5()
{
	myLinkedList<int> list;

	char opt = '\0';

	while (1)
	{
		cout << " TO ADD A NODE, PRESS 1 " << endl;
		cout << " TO COUNT NUMBER OF NODES, PRESS 2 " << endl;
		cout << " TO DISPLAY THE LIST, PRESS 3 " << endl;
		cout << " TO END, PRESS 0 " << endl;

		cin >> opt;
		system("cls");

		if (opt == '0')
			break;
		else if (opt == '1')
		{
			int node = 0;
			cout << " ENTER DATA = " << endl << " ";
			cin >> node;
			list.insertAtTail(node);

		}
		else if (opt == '2')
		{
			cout << " TOTAL NODES = " << list.numberOfNodes() << endl;
		}
		else if (opt == '3')
		{
			list.display();
		}
		else
			cout << " PLZ ENTER VALID INPUT " << endl;

	}
}