#include <iostream>
#include <fstream>
#include <string>

// Копирование файла

int main(int argc, char* argv)
{
	using namespace std;
	setlocale(LC_ALL, "Russian");

	cout << "Введите имя файла: ";
	string file_name;
	cin >> file_name;

	fstream file(file_name, ios::in);
	if (file.is_open())
	{
		string line;

		while (getline(file, line))
			cout << line << std::endl;

		file.close();
	}
	else
	{
		file.close();
		cout << "Такого файла не существует..." << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}