#include <iostream>
#include <vector>
#include <string>


using namespace std;

bool is_prime(int number)
{
	for (int i{ 2 }; i <= (int)sqrt(number); ++i)
	{
		if (number % i == 0)
			return false;
	}

	return true;
}

vector<int> get_prime_numbers(int number)
{
	vector<int> primes;

	for (int i{ 2 }; i < number; ++i)
	{
		if (is_prime(i))
			primes.push_back(i);
	}

	return primes;
}

// Решето Эратосфена
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите длину диапозона: ";

	int prime_limit;
	cin >> prime_limit;
	vector<int> primes = get_prime_numbers(prime_limit);

	cout << "Ваши простые числа: ";
	for (int i{ 0 }; i < primes.size(); ++i)
		cout << primes[i] << " ";

	return EXIT_SUCCESS;
}