#include <iostream>

using namespace std;

double calculate(int N)
{
	double sum = 0;
	double sin_sum = 0;

	for (int i = 1; i <= N; ++i)
	{
		sin_sum += sin(i);
		sum += i / sin_sum;
	}
	return sum;
}

int main()
{
	int N;
	cout << "Enter N: ";
	cin >> N;

	if (N <= 0)
	{
		cout << "Incorrect number!" << endl;
		return EXIT_FAILURE;
	}

	cout << "Answer = " << calculate(N) << endl;

	return EXIT_SUCCESS;
}