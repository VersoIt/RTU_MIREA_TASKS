#include <iostream>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "A = X and Y and Z or (not X) and (not Y) and (not Z)" << endl;
	cout << "B = X or Y or Z\n" << endl;

	cout << "|X| |Y| |Z| |A| |B|" << endl;
	for (int x = 0; x < 2; ++x)
	{
		for (int y = 0; y < 2; ++y)
		{
			for (int z = 0; z < 2; ++z)
			{
				cout << "|" << x << "| |" << y << "| |" << z << "| |" << (x && y && z || !x && !y && !z) << "| |" << (x || y || z) << "|" << endl;
			}
		}
	}

	return 0;
}