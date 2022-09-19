#include <iostream>
#include <ctime>
#include <fstream>


// Заем
int main(int argc, char* argv)
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	float S, p, n;

	cout << "Введите S, p и n через пробел" << endl;
	cin >> S >> p >> n;

	float r = p / 100;

	cout << "m = " << (S * r * pow((1 + r), n)) / (12 * (pow(1 + r, n) - 1)) << endl;

	return EXIT_SUCCESS;
}