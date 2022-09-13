#include <iostream>
#include <exception>
#include <iomanip>


int getIntegerValueBySymbol(char symbol)
{
	switch (symbol)
	{
	case 'I':
		return 1;
		break;
	case 'V':
		return 5;
		break;
	case 'X':
		return 10;
		break;
	case 'L':
		return 50;
		break;
	case 'C':
		return 100;
		break;
	case 'D':
		return 500;
		break;
	case 'M':
		return 1000;
		break;
	default:
		throw std::exception("Такого знака нету в римском алфавите.");
		break;
	}
}


// Декодирует римскую запись числа
int decodate(std::string number)
{
	int sum = 0;
	if (number.size() != 0)
	{
		char last_symbol = number[0];
		sum += getIntegerValueBySymbol(last_symbol);
		int last_symbol_value = getIntegerValueBySymbol(last_symbol);

		for (int i = 1; i < number.size(); ++i)
		{
			int current_symbol_value = getIntegerValueBySymbol(number[i]);
			if (last_symbol_value < current_symbol_value)
				throw std::exception("Неправильная запись числа!");

			last_symbol = number[i];
			sum += current_symbol_value;
		}
	}

	return sum;
}


int main(int argc, char* argv)
{
	setlocale(LC_ALL, "russian");

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