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

	{
		std::string file_name;
		std::cout << file_name << std::endl;
	}

	std::fstream file(file_name, std::ios::in);
	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			for (int i{ 0 }; i < line.size(); ++i)
			{
				if (isdigit(line[i]))
				{
					std::cout << line[i];
				}
				else if (i > 0 && isdigit(line[i - 1]))
					std::cout << " ";
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