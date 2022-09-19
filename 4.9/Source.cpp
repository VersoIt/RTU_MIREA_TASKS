#include <iostream>
#include <algorithm>
#include <exception>

using namespace std;

bool pass_string(const std::string& str)
{
	bool is_passed{ true };

	std::for_each(str.begin(), str.end(), [&is_passed](const char e)
		{
			if (!isdigit(e))
				is_passed = false;
		});

	return is_passed;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string some_string;
	cin >> some_string;

	std::cout << (pass_string(some_string) ? some_string : "Строка введена неверно!") << endl;

	return EXIT_SUCCESS;
}