#include <iostream>
#include <fstream>
#include <format>
#include <string>
#include <Windows.h>

using namespace std;

bool contains(const string& base_text, const string& inner)
{
	int inner_carriage = 0;
	int last_enter = 0;
	bool is_entered = false;

	for (int i = 0; i < base_text.size(); ++i)
	{
		if (tolower(base_text[i]) == tolower(inner[inner_carriage]))
		{
			if (inner_carriage == 0)
			{
				last_enter = i + 1;
				is_entered = true;
			}
			++inner_carriage;
		}
		else if (is_entered)
		{
			if (inner_carriage == inner.size())
				return true;

			inner_carriage = 0;
			i = last_enter;
			is_entered = false;
		}
		if (inner_carriage == inner.size())
			return true;
	}

	return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	string file_name;
	cout << "Enter name of file: ";
	cin >> file_name;

	fstream file(file_name, ios::in);
	if (file.is_open())
	{
		string content = "";

		string temp;
		while (getline(file, temp))
			content += temp;

		cout << "Content of file " << file_name << ": " << content << endl;

		cout << "Enter your word: ";
		string word;
		cin >> word;

		cout << (contains(content, word) ? format("File {} CONTAINS word {}", file_name, word) : format("File {} DON'T contains word {}", file_name, word)) << endl;
	}
	else
	{
		cout << "Invalid file path!" << endl;
		return EXIT_FAILURE;
	}

	

	return EXIT_SUCCESS;
}