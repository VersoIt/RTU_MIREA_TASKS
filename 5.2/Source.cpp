#include <iostream>

using namespace std;


int NOD_subtraction(int first, int second)
{
	while (first != second)
	{
		if (first > second)
			first -= second;
		else
			second -= first;
	}

	return first == 0 ? second : first;
}


int NOD_division(int first, int second)
{
	while (first != 0 && second != 0)
	{
		if (first > second)
			first = first % second;
		else
			second = second % first;
	}

	return first + second;
}

// Алгоритм Евклида
int main()
{

	int first_number;
	int second_number;


	cout << "Enter first number: ";
	cin >> first_number;

	cout << "Enter second number: ";
	cin >> second_number;

	cout << NOD_subtraction(first_number, second_number) << endl;

	return EXIT_SUCCESS;
}