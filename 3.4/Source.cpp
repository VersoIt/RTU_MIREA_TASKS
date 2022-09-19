#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <string>

// «Фильтр»
int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Russian");

	std::string file_name;

	std::cout << "Введите название файла: ";
	std::cin >> file_name;

	std::fstream file(file_name, std::ios::in);
	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			std::string current_number;

			for (int i{ 0 }; i < line.length(); ++i)
			{
				if (isdigit(line[i]))
					current_number += line[i];
				else
				{
					std::cout << (current_number.length() == 0 ? "" : current_number + " ");
					current_number = "";
				}
			}
		}
		file.close();
	}
	else
	{
		file.close();
		std::cout << "Такого файла не существует" << std::endl;
		return EXIT_FAILURE;
	}
	file.close();

	return EXIT_SUCCESS;
}