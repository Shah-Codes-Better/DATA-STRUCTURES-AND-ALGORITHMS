#include "Reservation.h"
#include "BST.h"

int main()
{
	BST<Reservation> obj;

	int opt = 0;
	while (true)
	{
		cout << " TO BOOK A RESERVATION, PRESS 1" << endl;
		cout << " TO SEARCH A RESERVATION, PRESS 2" << endl;
		cout << " TO CANCEL A RESERVATION, PRESS 3" << endl;
		cout << " TO END THE PROGRAM, PRESS 0" << endl << " ";
		cin >> opt;

		if (opt == 0)
			break;
		else if (opt == 1)
		{
			Reservation ob;
			cin >> ob;
			obj.insert(ob);
		}
		else if (opt == 2)
		{
			Reservation ob;
			cout << " ENTER INFO ABOUT THE RESERVATION, YOU WANT TO DELETE";
			cin >> ob;
			if (obj.deleteValue(ob))
				cout << "DELETED" << endl;
			else
				cout << " NOT FOUND " << endl;

		}
		else if (opt == 3)
		{
			Reservation ob;
			cout << " ENTER INFO ABOUT THE RESERVATION, YOU WANT TO SEARCH";
			cin >> ob;
			if (!obj.search(ob))
				cout << " NOT FOUND" << endl;

		}
		else
			cout << " PLZ ENTER VALID OPTION " << endl;
	}
	return 0;
}