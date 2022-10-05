#include <iostream>
#include <string>

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
	setlocale(LC_ALL, "Russian");

	int first_number;
	int second_number;

	cout << "Введите первое число: ";
	cin >> first_number;

	if (cin.fail() || first_number < 0)
	{
		cout << "Ошибка ввода!";
		return EXIT_FAILURE;
	}

	cout << "Введите второе число: ";
	cin >> second_number;

	if (cin.fail() || second_number < 0)
	{
		cout << "Ошибка ввода: это не число!";
		return EXIT_FAILURE;
	}

	cout << NOD_subtraction(first_number, second_number) << endl;

	return EXIT_SUCCESS;
}