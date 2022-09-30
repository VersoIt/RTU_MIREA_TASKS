#include <iostream>
#include <fstream>
#include <string>

int sign(double number)
{
	return number < 0 ? -1 : number == 0 ? 0 : 1;
}

// Ђ«нак числа
int main(int argc, char* argv)
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	
	double number;
	cout << "¬ведите число: " << endl;
	
	cin >> number;
	if (cin.fail())
	{
		cout << "ERROR" << endl;
		return EXIT_FAILURE;
	}

	cout << sign(number) << endl;
	return EXIT_SUCCESS;
}