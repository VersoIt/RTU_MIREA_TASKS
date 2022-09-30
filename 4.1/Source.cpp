#include <iostream>
#include <fstream>
#include <string>


//bool pass_string(const std::string& str)
//{
//	for (int i = 0; i < str.size(); ++i)
//	{
//		if (!isdigit(str[i]))
//			return false;
//
//	}
//
//	return true;
//}

// �����
int main(int argc, char* argv)
{
	using namespace std;
	setlocale(LC_ALL, "Russian");

	string file_path;
	cout << "������� �������� �����, ���� �� ������ ���������� �����: ";
	cin >> file_path;

	fstream file(file_path, ios::out);
	if (file.is_open())
	{
		const int numbers_count{ 10 };

		for (int i{ 0 }; i < numbers_count; ++i)
		{
			string number;

			cout << "����� #" << i + 1 << ": ";
			try
			{
				cin >> number;
				file << stod(number.c_str()) << " ";
			}
			catch (exception)
			{
				cout << "�������� ������!" << endl;
				return 1;
			}
		}

		file.close();
		file.open(file_path, std::ios::in);

		double sum{ 0 };
		double temp;
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