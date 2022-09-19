#include <iostream>
#include <ctime>
#include <fstream>
#include <string>


// Сортировка букв
int main(int argc, char* argv)
{
	using namespace std;
	setlocale(LC_ALL, "Russian");

	string text;
	cout << "Введите любой текст: ";
	cin >> text;

	for (int i{ 0 }; i < text.size(); ++i)
	{
		for (int j{ i + 1 }; j < text.size(); ++j)
		{
			if ((char)(text[i]) > (char)(text[j]))
				swap(text[i], text[j]);
		}
	}

	cout << text << endl;

	return EXIT_SUCCESS;
}