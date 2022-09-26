#include <iostream>


// —суда
int main(int argc, char* argv)
{
	using namespace std;
	setlocale(LC_ALL, "Russian");

	float S, m, n;

	cout << "¬ведите S, m и n через пробел" << endl;
	cin >> S >> m >> n;

	double p = 0.00001;

	cout << "—читаем..." << endl;
	while ((S * p / 100 * pow((1 + p / 100), n)) / (12 * (pow((1 + p / 100), n) - 1)) < m)
		p += 0.0001;

	if (p > 100)
	{
		cout << "„исло процентов не может превышать 100." << endl;
		return EXIT_FAILURE;
	}

	cout << "p = " << p << "%" << endl;

	return EXIT_SUCCESS;
}