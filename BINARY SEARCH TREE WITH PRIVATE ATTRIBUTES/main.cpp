#include "BST.h"

int main()
{
	BST obj;

	obj.insert(100);
	obj.insert(200);
	obj.insert(150);
	obj.insert(50);
	obj.insert(25);
	obj.insert(100);
	obj.insert(75);
	obj.insert(325);
	obj.insert(30);
	obj.insert(250);
	obj.insert(225);
	obj.insert(275);
	obj.insert(175);
	obj.insert(325);


	cout << " --- INORDER IS --- " << endl;
	obj.inorder();

	obj.deleteValue(325);
	cout << endl;

	obj.inorder();

	int level = 0;
	int comparisons = 0;

	if (obj.searchtree(275, comparisons, level))
	{
		cout << "\n FOUND ";
		cout << "\n COMPARISONS = " << comparisons;
		cout << "\n LEVEL OF NODE = " << level << " \n\n";
	}
	else
		cout << " NOT FOUND ";

	cout << obj.count(100) << endl;
	cout << obj.count(325) << endl;
	cout << obj.count(20000) << endl;

	return 0;
}