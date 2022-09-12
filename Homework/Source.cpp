#include <iostream>
#include <ctime>
#include <fstream>

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Russian");
	float S, p, n;

	std::cout << "¬ведите S p n через пробел" << std::endl;
	std::cin >> S >> p >> n;

	float r = p / 100;

	std::cout << "m = " << (S * r * pow((1 + r), n)) / (12 * (pow(1 + r, n) - 1)) << std::endl;

	return EXIT_SUCCESS;
}