#include <iostream>

using namespace std;

int main()
{
	for (int i = -1000000; i < 10000; ++i)
	{
		if (!(((i < 2) && (i > 5)) || (i > 10)))
			cout << i << endl;
	}
}