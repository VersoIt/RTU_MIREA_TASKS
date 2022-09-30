#include <iostream>
#include <ctime>
#include <fstream>
#include <string>


// ���������� ����
int main(int argc, char* argv)
{
	using namespace std;
	const string file_name = "somefile.txt";

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int count = rand() % 31 + 30;

	cout << "��������� �������� ��� ����� ������ " << count << " ��������" << endl;
	fstream file(file_name, ios::out);
	string text = "";
	for (int i = 0; i < count; ++i)
		text += (char)('A' + rand() % 26);

	file << text;

	string line;
	getline(file, line);
	cout << "��������� ������ �� �����..." << endl;

	// ���������� ������ �� �����
	for (int i{ 0 }; i < line.size(); ++i)
	{
		for (int j{ i + 1 }; j < line.size(); ++j)
		{
			if ((char)(line[i]) > (char)(line[j]))
				swap(line[i], line[j]);
		}
	}

	cout << line << endl;

	return EXIT_SUCCESS;
}