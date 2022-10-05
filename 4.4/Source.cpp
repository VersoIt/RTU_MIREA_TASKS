#include <iostream>
#include <Windows.h>
#define FOREGROUND_WHITE 15

int main()
{
	using namespace std;

	const char star = '+';
	const char line = '_';
	const char limit = '|';

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_RED);

	for (int height = 0; height < 13; ++height)
	{

		if (height > 0 && height < 7)
		{
			SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
			std::cout << limit;

			for (int states_width = 0; states_width < 8; ++states_width)
			{
				SetConsoleTextAttribute(handle, (states_width + height) % 2 == 0 ? FOREGROUND_BLUE : FOREGROUND_WHITE);
				std::cout << star << ' ';
			}

			SetConsoleTextAttribute(handle, height % 2 == 0 ? FOREGROUND_RED : FOREGROUND_WHITE);
			for (int default_width = 0; default_width < 19; ++default_width)
			{
				std::cout << line;
			}
		}
		else
		{

			SetConsoleTextAttribute(handle, height % 2 == 0 ? FOREGROUND_RED : FOREGROUND_WHITE);

			if (height != 0)
				std::cout << limit;

			else
				std::cout << line;

			for (int default_width = 0; default_width < 35; ++default_width)
				std::cout << line;

		}

		if (height != 0)
			std::cout << limit;

		std::cout << endl;
	}
	SetConsoleTextAttribute(handle, FOREGROUND_WHITE);

	return EXIT_SUCCESS;
}