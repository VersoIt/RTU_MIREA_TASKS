#include <iostream>
#include <fstream>
#include <vector>
#include <ostream>
#include <Windows.h>
#include <iomanip>


using namespace std;


struct Book
{
	string author;
	string name;
	string year;
};


std::istream& operator >> (istream& in, Book& book)
{
	in >> book.name >> book.author >> book.year;
	return in;
}

std::ostream& operator << (ostream& out, const Book& book)
{
	out << setw(22) << book.name << " | " << setw(16) << book.author << " | " << setw(1) << book.year;
	return out;
}

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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string file_name;

	// books.txt
	cout << "Введите имя файла: ";
	cin >> file_name;

	cout << endl;

	ifstream file(file_name, ios::in);

	vector<Book> books;

	if (file.is_open())
	{
		Book book;

		while (!file.eof())
		{
			file >> book;
			books.push_back(book);
		}

		cout << "-------------------------------------------------" << endl;
		cout << setw(36) << "СОДЕРЖИМОЕ БИБЛИОТЕКИ: " << endl;
		cout << "-------------------------------------------------" << endl;
		cout << setw(22) << "КНИГА" << " | " << setw(16) << "АВТОР" << " | " << setw(1) << "ГОД" << endl;
		for (int i = 0; i < books.size(); ++i)
			cout << books[i] << endl;

		cout << "-------------------------------------------------" << endl;
		cout << endl;

		string search_word;
		vector<Book> search_books;

		cout << "Введите слово, по которому будет происходить поиск среди названий книг: ";
		cin >> search_word;

		for (int i = 0; i < books.size(); ++i)
		{
			if (contains(books[i].name, search_word))
				search_books.push_back(books[i]);
		}

		if (search_books.size() != 0)
		{
			cout << "Книги, которые содержат сочетание " << search_word << ": " << endl;

			cout << endl;
			cout << "-------------------------------------------------" << endl;

			for (int i = 0; i < search_books.size(); ++i)
				cout << search_books[i] << endl;

			cout << "-------------------------------------------------" << endl;
		}
		else
			cout << "Совпадений нет... (" << endl;
	}
	else
	{
		cout << "Не удалось открыть файл!" << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}