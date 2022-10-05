#include <iostream>
#include <fstream>
#include <string>

int sign(double number)
{
	return number < 0 ? -1 : number == 0 ? 0 : 1;
}

// «Знак числа (Не проверено)
int main(int argc, char* argv)
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	
	double number;
	cout << "Введите число: " << endl;
	
	cin >> number;
	if (cin.fail())
	{
		cout << "Ошибка ввода: это не число!" << endl;
		return EXIT_FAILURE;
	}

	cout << sign(number) << endl;
	return EXIT_SUCCESS;
}