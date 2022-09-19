#include <iostream>
#include <fstream>
#include <string>

// Копирование файла

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Введите имя файла: " << std::endl;
	std::string file_name;
	std::cin >> file_name;

	std::fstream file(file_name, std::ios::in);
	std::string line;

	while (getline(file, line))
		std::cout << line << std::endl;

	file.close();

	return EXIT_SUCCESS;
}