#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <string>

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Russian");

	std::string file_name;
	std::cin >> file_name;

	std::fstream file(file_name, std::ios::in);
	std::string line;

	while (getline(file, line))
		std::cout << line << std::endl;

	file.close();

	return EXIT_SUCCESS;
}