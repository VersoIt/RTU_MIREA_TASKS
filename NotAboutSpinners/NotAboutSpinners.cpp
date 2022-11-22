#include <iostream>

using namespace std;

int main()
{
	int width;
	int height;

	cin >> width;
	cin >> height;

	int quantity_by_width = 0;
	int total = 0;

	for (int i = 1; i <= width; ++i)
		quantity_by_width += i;

	for (int i = 1; i <= height; ++i) 
		total += i * quantity_by_width;

	cout << total << endl;

	return EXIT_SUCCESS;
}