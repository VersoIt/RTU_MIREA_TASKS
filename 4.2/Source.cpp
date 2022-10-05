#include <iostream>
#include <fstream>
#include <string>

int sign(double number)
{
	return number < 0 ? -1 : number == 0 ? 0 : 1;
}

// ����� ����� (�� ���������)
int main(int argc, char* argv)
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	
	double number;
	cout << "������� �����: " << endl;
	
	cin >> number;
	if (cin.fail())
	{
		cout << "������ �����: ��� �� �����!" << endl;
		return EXIT_FAILURE;
	}

	cout << sign(number) << endl;
	return EXIT_SUCCESS;
}