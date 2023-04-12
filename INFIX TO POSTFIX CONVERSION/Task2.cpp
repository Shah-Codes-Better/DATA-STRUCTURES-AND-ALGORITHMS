#include "myStack.h"

char* postfix(const char*);
void display(const char*);


int main()
{
	char* notation = new char[100] {"( ( ( 12 + 13 ) * ( 20 - 30 ) ) / ( 811 + 99 ) )"};
	std::cout << " ------------- SAMPLE INPUT ------------- " << std::endl;
	display(notation);
	std::cout << " ---------------------------------------- " << std::endl;
	delete notation;
	notation = nullptr;
	notation = new char[100];
	
	std::cout << " ENTER YOUR STRING HERE (BE MINDFUL OF SPACES) : ";
	std::cin.getline(notation, 99);
	std::cout << " STRING IN INFIX_NOTATION : ";
	display(notation);
	notation = postfix(notation);
	std::cout << " STRING IN POSTFIX_NOTATION : ";
	display(notation);
	return 0;
}

char* postfix(const char* arr)
{
	char garbage = '\0';
	char *post = new char[100] {"[\0"};
	int x = 1;
	myStack<char> S(100);
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == '(' || arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')
			S.push(arr[i]);
		else if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9'))
		{
			post[x++] = arr[i];
		}
		else if (arr[i] == ')')
		{
			post[x++] = S.pop();
			garbage = S.pop();
		}
		else if (arr[i] == ' ')
		{
			if (post[x-1] != ' ')
				post[x++] = ' ';
		}
		else
		{
			std::cout << " INVALID STRING " << std::endl;
			std::cout << " RETURNING NULLPTR " << std::endl;
			return nullptr;
		}
	}
	post[x++] = ' ';
	post[x] = ']';
	return post;
}
void display(const char* arr)
{
	if (arr != nullptr)
		std::cout << arr << std::endl;
	else
		std::cout << " NULLPTR " << std::endl;
}
