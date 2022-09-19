#include <iostream>
#include <fstream>
#include <string>


// �����
int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Russian");

	std::string file_path;
	std::cout << "������� �������� �����: " << std::endl;
	std::cin >> file_path;
	std::fstream file;
	file.open(file_path, std::ios::out);

	const int numbers_count{ 10 };

	for (int i{ 0 }; i < numbers_count; ++i)
	{
		int number;

		std::cout << "����� #" << i + 1 << ": ";
		std::cin >> number;

		file << number << " ";
	}

	file.close();
	file.open(file_path, std::ios::in);

	std::string line;
	long sum{ 0 };

	if (file.is_open())
	{
		int temp;
		while (file >> temp)
			sum += temp;
	}
	else
		std::cout << "����� �� ����������..." << std::endl;

	std::cout << "����� �����, ��������� �� ����� ����� " << sum << std::endl;
	file.close();

	return EXIT_SUCCESS;
}