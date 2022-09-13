#include <iostream>


int reccurent(int i, int S = 0)
{
	if (i <= 0)
	{
		std::cout << "i = 0, S = 0" << std::endl;
		return 0;
	}

	int m = rand();
	int b = rand();
	int c = rand();

	S = (m * reccurent(i - 1, S) + b) % c;

	std::cout << "i = " << i << " | S = " << S << std::endl;
	return S;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int count;

	std::cout << "—колько раз индексировать реккурентную формулу?\n¬вод: ";
	std::cin >> count;

	if (count < 0)
	{
		std::cout << "¬ведено неверное значение!" << std::endl;
		return -1;
	}

	reccurent(count);

	return 0;
}