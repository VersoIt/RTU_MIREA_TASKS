#include <iostream>

using namespace std;

int main()
{
	int N;

	cin >> N;
	int third_count = 0;
	int fourth_count = 0;

	while (N > 2) {
		if (N % 4 == 0) {
			fourth_count += N / 4;
			N = 0;
			break;
		}
		N -= 3;
		third_count++;
	}

	cout << third_count << " " << fourth_count << endl;

	return EXIT_SUCCESS;
}