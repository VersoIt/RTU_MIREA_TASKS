#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <algorithm>
#include <fstream>

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Russian");
	float S, m, n;

	std::cout << "¬ведите S m n через пробел" << std::endl;
	std::cin >> S >> m >> n;


	for (float p{ 0 }; p < 100; p += 0.01)
	{
		float r{ p / 100 };

		if ((S * r * pow((1 + r), n)) / (12 * (pow(1 + r, n) - 1)) == m)
		{
			std::cout << p << std::endl;
			break;
		}
	}

	return EXIT_SUCCESS;
}