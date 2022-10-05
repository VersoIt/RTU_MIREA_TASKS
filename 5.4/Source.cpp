#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <Windows.h>
#include <string>


using namespace std;


tuple<char, int> get_rarely_found_vowel(const string& text)
{
	unordered_map<char, int> elements_counts;

	for (int i{ 0 }; i < text.size(); ++i)
		elements_counts[text[i]]++;

	int max_count{ 0 };
	char symbol{ 0 };

	for (auto it = elements_counts.begin(); it != elements_counts.end(); ++it)
	{
		if (max_count < (it->second))
		{
			max_count = it->second;
			symbol = it->first;
		}
	}

	return std::make_pair(symbol, max_count);
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
		string readed = "";
		string temp;

		while (getline(file, temp))
			readed += temp;

		cout << "Content of " << file_name << ": " << readed << endl;

		get_rarely_found_vowel(readed);

		auto [symbol, frequency_count] = get_rarely_found_vowel(readed);
		cout << "Symbol [\'" << symbol << "\'] recurs most frequently: " << frequency_count << " times!";
	}
	else
	{
		cout << "Invalid file path!" << endl;
		return -1;
	}


	return EXIT_SUCCESS;
}