#include <iostream>
#include <ctime>
#include <fstream>
#include <string>


// Сортировка букв
int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Russian");

	std::string text{ "some texta" };

	for (int i{ 0 }; i < text.size(); ++i)
	{
		for (int j{ i + 1 }; j < text.size(); ++j)
		{
			if ((char)(text[i]) > (char)(text[j]))
				std::swap(text[i], text[j]);
		}
	}

	std::cout << text << std::endl;

	return EXIT_SUCCESS;
}