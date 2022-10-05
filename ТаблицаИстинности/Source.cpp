#include <iostream>
#include <string>

using namespace std;

void Foo()
{
	cout << stod("-123.323") << endl;
}

int main()
{
	Foo();
	cout << stod("-123.323") << endl;
	return -1;
}