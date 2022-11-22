#include <iostream>
#include <set>

using namespace std;

int popElement(multiset<int>& set);

int main() {

	int students_count;
	int places_count = 22;

	cin  >> students_count;

	int first_division = 0;
	int second_division = 0;

	multiset<int> place_divisions;
	place_divisions.insert(places_count);

	for (int i = 0; i < students_count; ++i) {
		int bigger_space = popElement(place_divisions);

		first_division = (bigger_space - 1) / 2;
		second_division = bigger_space - first_division - 1;

		place_divisions.insert(first_division);
		place_divisions.insert(second_division);
	}

	cout << first_division << " " << second_division << endl;

	return 0;
}

int popElement(multiset<int>& set) {
	auto pointer = set.end();
	--pointer;
	int element = *pointer;
	set.erase(pointer);
	return element;
}