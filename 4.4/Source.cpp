#include <iostream>

// Былая слава
int main()
{
	using namespace std;

	const char star = '+';
	const char line = '_';
	const char limit = '|';

	for (int height = 0; height < 13; ++height)
	{

		if (height > 0 && height < 7)
		{
			cout << limit;

			for (int states_width = 0; states_width < 8; ++states_width)
				cout << star << ' ';

			for (int default_width = 0; default_width < 19; ++default_width)
				cout << line;
		}
		else
		{
			if (height != 0)
				cout << limit;

			else
				cout << line;

			for (int default_width = 0; default_width < 35; ++default_width)
				cout << line;

		}

		if (height != 0)
			cout << limit;

		cout << endl;
	}

	return EXIT_SUCCESS;
}