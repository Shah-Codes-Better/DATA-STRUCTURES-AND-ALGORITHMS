#include "myStack.h"
#include <fstream>

void file(char*&);
void findingSize(int&, int&, char*&);
void filing(int**&, int**&, const int&, const int&, char*&);
void create(int**&, const int&, const int&);
void input(int**&, const int&, const int&, std::ifstream&);
void display(int**&, const int&, const int&);
template <typename T>
bool path(int**&, int**&, const int&, const int&, myStack<T>&);
bool checkRight(int**&, int**, int, int);
bool checkDown(int**&, int**, int, int);
bool checkUp(int**&, int**, int, int);
bool checkLeft(int**&, int**, int, int);
void output(int**&, const int&, const int&, const bool&);
void delete2D(int**&, const int&);
void delete1D(char*&);


int main()
{

	int row = 0;
	int column = 0;
	int** arr = nullptr;
	int** solution = nullptr;
	bool possibility = true;
	char* fileName = new char[20];

	file(fileName);
	findingSize(row, column, fileName);
	myStack<char> S(row * column);
	filing(arr, solution, row, column, fileName);
	display(arr, row, column);
	possibility = path(arr, solution, row, column, S);

	if (possibility)
	{
		std::cout << "\n -----  SOLUTION  ----- " << std::endl;
		S.display();
		std::cout << " ---------------------- " << std::endl;
		output(solution, row, column, possibility);
	}
	else
	{
		std::cout << " NO SOLUTION POSSIBLE " << std::endl;
	}

	delete2D(arr,row);
	delete2D(solution, row);
	delete1D(fileName);

	return 0;
}
void file(char*& arr)
{
	std::cout << " ENTER THE FILE NAME FROM WHERE YOU WANT TO READ THE MATRIX = ";
	std::cin >> arr;
}
void findingSize(int& row, int& col, char*& fileName)
{
	char arr[100] = "\0";
	row = 0;
	col = 0;
	std::ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
		std::cout << " ---- ERROR, CANNOT OPEN FILE ---- " << std::endl;
	else
	{
		while (!fin.eof())
		{
			fin.getline(arr, 99);
			row++;
		}
		fin.close();
	}
	for (int i = 0; arr[i]!= '\0'; i++)
		if(arr[i]!=' ')
			col++;
}
void filing(int**& arr, int**& sol, const int& row, const int& col, char*& fileName)
{
	std::ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
		std::cout << " ---- ERROR, CANNOT OPEN FILE ---- " << std::endl;
	else
	{
		create(arr, row, col);
		input(arr, row, col, fin);
		
		create(sol, row, col);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				sol[i][j] = 0;
		fin.close();
	}
}
template <typename T>
bool path(int**& arr, int**& sol, const int& row, const int& col ,myStack<T> & S)
{
	int i = 0, j = 0;
	char garbage = '\0';
	bool flag = true;

	if (arr[0][0] == 1)
	{
		S.push('R');
		sol[0][0] = 1;
	}
	else
	{
		j = col;
		flag = false;
	}

	while (!(i == row - 1 && j == col - 1))
	{
		if (S.top() == 'R')
		{
			if (j < col && checkRight(sol, arr, i, j))
			{
				S.push('R');
				j++;
			}
			else if (i < row - 1 && checkDown(sol, arr, i, j))
			{
				S.push('D');
				i++;
			}
			else if (i > 0 && checkUp(sol, arr, i, j))
			{
				S.push('U');
				i--;
			}
			else if (j == 0 && i == 0)
			{
				flag = false;
				break;
			}
			else
			{
				garbage = S.pop();
				arr[i][j] = -1;
				sol[i][j] = 0;
				j--;
			}
		}
		else if (S.top() == 'D')
		{
			if (i < row - 1 && checkDown(sol, arr, i, j))
			{
				S.push('D');
				i++;
			}
			else if (j < col - 1 && checkRight(sol, arr, i, j))
			{
				S.push('R');
				j++;
			}
			else if (j > 0 && checkLeft(sol, arr, i, j))
			{
				S.push('L');
				j--;
			}
			else if (j == 0 && i == 0)
			{
				flag = false;
				break;
			}
			else
			{
				garbage = S.pop();
				arr[i][j] = -1;
				sol[i][j] = 0;
				i--;
			}
		}
		else if (S.top() == 'U')
		{
			if (i > 0 && checkUp(sol, arr, i, j))
			{
				S.push('U');
				i--;
			}
			else if (j < col - 1 && checkRight(sol, arr, i, j))
			{
				S.push('R');
				j++;
			}
			else if (j > 0 && checkLeft(sol, arr, i, j))
			{
				S.push('L');
				j--;
			}
			else if (j == 0 && i == 0)
			{
				flag = false;
				break;
			}
			else
			{
				garbage = S.pop();
				arr[i][j] = -1;
				sol[i][j] = 0;
				i++;
			}
			
		}
		else				// S.top() == 'L'
		{
			if (j > 0 && checkLeft(sol, arr, i, j))
			{
				S.push('L');
				j--;
			}
			else if (i < row - 1 && checkDown(sol, arr, i, j))
			{
				S.push('D');
				i++;
			}
			else if (i > 0 && checkUp(sol, arr, i, j))
			{
				S.push('U');
				i--;
			}
			else if (i == 0 && j == 0)
			{
				flag = false;
				break;
			}
			else
			{
				garbage = S.pop();
				arr[i][j] = -1;
				sol[i][j] = 0;
				j++;
			}
		}
	}
	return flag;
}
bool checkRight(int**&sol, int** arr, int i, int j)
{
	if (arr[i][++j] == 1)
	{
		arr[i][j] = -1;
		sol[i][j] = 1;
		return true;
	}
	return false;
}
bool checkLeft(int**& sol, int** arr, int i, int j)
{
	if (arr[i][--j] == 1)
	{
		arr[i][j] = -1;
		sol[i][j] = 1;
		return true;
	}
	return false;
}
bool checkDown(int**& sol, int** arr, int i, int j)
{
	if (arr[++i][j] == 1)
	{
		arr[i][j] = -1;
		sol[i][j] = 1;
		return true;
	}
	return false;
}
bool checkUp(int**& sol, int** arr, int i, int j)
{
	if (arr[--i][j] == 1)
	{
		arr[i][j] = -1;
		sol[i][j] = 1;
		return true;
	}
	return false;
}
void create(int**& arr, const int& row, const int& col)
{
	arr = new int* [row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[col];
}
void input(int**& arr, const int& row, const int& col, std::ifstream& fin)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			fin >> arr[i][j];

}
void display(int**& arr, const int& row, const int& col)
{
	std::cout << "\n ----- THE MAZE -----" << std::endl;
	for (int i = 0; i < row; i++)
	{
		std::cout << "     ";
		for (int j = 0; j < col; j++)
			std::cout << arr[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << " -------------------" << std::endl;
}
void output(int**&arr, const int& row, const int& col, const bool& yes)
{
	std::ofstream fout;
	fout.open("output.txt");
	if (yes)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				fout << arr[i][j] << " ";
			fout << std::endl;
		}
		std::cout << " SOLUTION MATRIX UPDATED IN FILE " << std::endl;
	}
	else
	{
		fout << " NO SOLUTION FOUND " << std::endl;
	}
}
void delete2D(int**& arr, const int& row)
{
	for (int i = 0; i < row; i++)
		delete arr[i];
	delete arr;
	arr = nullptr;
}
void delete1D(char*& arr)
{
	delete arr;
	arr = nullptr;
}