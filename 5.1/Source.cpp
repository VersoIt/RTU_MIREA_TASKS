#include <iostream>
#include <string>
#include <format>
#include <string_view>
#include <math.h>


using namespace std;

int char_into_radix_format(char symbol)
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

string convert(const string& number, int base_radix, int new_radix)
{
	int length = number.length();
	long number_in_10_base{ 0 };

	for (int i = length - 1; i >= 0; --i)
	{
		int current_digit{ char_into_radix_format(number[i]) };
		if (current_digit >= base_radix)
			throw exception(std::format("Number system with base %d cannot contain the number %d!", base_radix, current_digit).c_str());
		number_in_10_base += char_into_radix_format(number[i]) * pow(base_radix, length - i - 1);
	}

	string result{ "" };

	while (number_in_10_base > 0)
	{
		result = to_string(number_in_10_base % new_radix) + result;
		number_in_10_base /= new_radix;
	}

	return result;
}

// Системы счисления
int main()
{

	string original_number;

	int base_radix;
	int new_radix;

	cout << "Enter your number: ";
	cin >> original_number;

	cout << "Enter current foundation of your number: ";
	cin >> base_radix;

	cout << "Enter new foundation of your number: ";
	cin >> new_radix;

	try
	{
		cout << "Great! Result is " << convert(original_number, base_radix, new_radix) << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	return EXIT_SUCCESS;
}