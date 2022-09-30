#include <iostream>
#include <string>
#include <format>
#include <string_view>
#include <math.h>


using namespace std;

unsigned long long char_into_radix_format(char symbol)
{
	/*
	* if we subtract 7 the position of the capital letter in the asci table from the zero symbol, 
	* then we get the correct convenient representation for the number
	*/

	const int ident_in_ascii_for_letters = '7';
	const int ident_in_ascii_for_digits = '0';

	if (isdigit(symbol))
		return symbol - ident_in_ascii_for_digits;

	if (isalpha(symbol))
		return symbol - ident_in_ascii_for_letters;

	return symbol;
}

char radix_format_into_char(int number)
{
	if (number < 10)
		return '0' + number;

	return 'A' + number - 10;
}

string convert(const string& number, int base_radix, int new_radix)
{
	long length = number.length();
	unsigned long long number_in_10_base{ 0 };

	for (int i = length - 1; i >= 0; --i)
	{
		unsigned long long current_digit{ char_into_radix_format(number[i]) };

		if (current_digit >= base_radix)
			throw exception(std::format("Number system with base %d cannot contain the number %d!", base_radix, current_digit).c_str());

		number_in_10_base += char_into_radix_format(number[i]) * pow(base_radix, length - i - 1);
	}

	string result{ "" };

	while (number_in_10_base > 0)
	{
		result = radix_format_into_char(number_in_10_base % new_radix) + result;
		number_in_10_base /= new_radix;
	}

	return result;
}

// —истемы счислени€
int main()
{
	string original_number;
	setlocale(LC_ALL, "Russian");
	int base_radix;
	int new_radix;

	cout << "¬ведите число: ";
	cin >> original_number;

	cout << "¬ведите текущее основание счислени€: ";
	cin >> base_radix;

	for (int i = 0; i < original_number.size(); ++i)
	{
		if (base_radix <= original_number[i] - '0')
		{
			cout << "ERROR" << endl;
			return -1;
		}
	}

	cout << "¬ведите новое основание счислени€: ";
	cin >> new_radix;

	try
	{
		cout << "Great! ¬аш результат равен " << convert(original_number, base_radix, new_radix) << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	return EXIT_SUCCESS;
}