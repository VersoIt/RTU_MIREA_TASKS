#include <iostream>
#include <ctime>
#include <fstream>


// ����
int main(int argc, char* argv)
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	double S, p, n;

	cout << "������� S, p � n ����� ������" << endl;
	cin >> S >> p >> n;

	if (S <= 0 || p <= 0 || n <= 0)
	{
		cout << "��������� �������� ��������!" << endl;
		return EXIT_FAILURE;
	}

	double r = p / 100;

	cout << "m = " << (S * r * pow((1 + r), n)) / (12 * (pow(1 + r, n) - 1)) << endl;

	return EXIT_SUCCESS;
}