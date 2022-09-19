#include <iostream>
#include <fstream>
#include <string>


// �����
int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Russian");

	std::string file_path;
	std::cout << "������� �������� �����, ���� �� ������ ���������� �����: ";
	std::cin >> file_path;

	std::fstream file(file_path, std::ios::out);
	if (file.is_open())
	{
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

		int temp;
		while (file >> temp)
			sum += temp;

		std::cout << "����� �����, ��������� �� ����� ����� " << sum << std::endl;
		file.close();
	}
	else
	{
		file.close();
		std::cout << "������ ����� �� ����������..." << std::endl;
		return EXIT_FAILURE;
	}


	return EXIT_SUCCESS;
}