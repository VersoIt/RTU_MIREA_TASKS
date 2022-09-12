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

	std::cout << "¬ведите название файла: ";
	std::cin >> file_name;

	std::fstream file(file_name, std::ios::in);
	std::string line;

	while (getline(file, line))
		std::for_each(line.begin(), line.end(), [](const auto e) 
			{
				if (isdigit(e))
					std::cout << e; 
			});

	file.close();

	return EXIT_SUCCESS;
}