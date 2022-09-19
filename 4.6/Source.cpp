#include <iostream>
#include <exception>
#include <iomanip>
#include <map>

// Декодирует римскую запись числа
int decodate(const std::string& number)
{
	std::map<char, int> roman_comparison{
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000},
	};

	int sum = 0;
	for (int i = 0; i < number.size(); ++i)
	{
		int value = roman_comparison[number[i]];
		if (number.size() != (i + 1) && value < roman_comparison[number[i + 1]])
			sum -= value;
		else
			sum += value;
	}

	return sum;
}


// Автоматный распознаватель
int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите римскую запись числа: ";

	std::string text_number;
	std::cin >> text_number;

	try
	{
		std::cout << text_number << " = " << decodate(text_number) << std::endl;
	}
	catch (std::exception exc)
	{
		std::cout << exc.what() << std::endl;
	}

	return 0;
}