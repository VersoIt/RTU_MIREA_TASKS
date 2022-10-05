#include <iostream>

using namespace std;

int fact(int n)
{
	return (n > 1) ? fact(n - 1) * n : 1;
}

int perestanovka(int m, int n, int* bounces)
{
	int combinations_count = 0;
	if (m >= n)
	{
		if (bounces[m - 1] == n)
		{
			combinations_count = 1;
		}
	}
	else
	{
		for (int i = m; i <= n; ++i)
		{
			if (bounces[m - 1] == i)
			{
				combinations_count += fact(n - m);
			}
			else
			{
				swap(bounces[i - 1], bounces[m - 1]);
				combinations_count += perestanovka(m + 1, n, bounces);
				swap(bounces[i - 1], bounces[m - 1]);
			}
		}
	}
	return combinations_count;
}

int main()
{
	int bounces_count;
	cin >> bounces_count;

	int* bounces = new int[bounces_count];
	for (int i = 0; i < bounces_count; ++i)
	{
		bounces[i] = i + 1;
	}

	cout << perestanovka(1, bounces_count, bounces) << endl;

	delete[] bounces;
	return EXIT_SUCCESS;
}