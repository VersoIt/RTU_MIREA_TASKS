#include <iostream>

using namespace std;

double calculate(int N)
{
	double sum = 0;

	for (int i = 1; i <= N; ++i)
	{
		double sin_sum = 0;
		for (int j = 1; j <= i; ++j)
			sin_sum += sin(j);

		sum += i / sin_sum;
	}
	return sum;
}

int main()
{
	int N;
	cout << "Enter N: ";
	cin >> N;

	cout << "Answer = " << calculate(N) << endl;

	return EXIT_SUCCESS;
}