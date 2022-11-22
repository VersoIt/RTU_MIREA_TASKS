#include <iostream>
#include <tuple>

using namespace std;

tuple<int, int> getPlaces(int left_places_count, int children_count, int right_places_count = 0);

int main()
{
	int a;
	int b;

	cin >> a;
	cin >> b;

	auto tuple = getPlaces(a, b);

	cout << get<0>(tuple) << " " << get<1>(tuple) << endl;
	return EXIT_SUCCESS;
}

tuple<int, int> getPlaces(int left_places_count, int children_count, int right_places_count) {
	if (children_count <= 1) {
		int max_places_count = max(left_places_count, right_places_count);
		return make_tuple((max_places_count - 1) / 2, (max_places_count - 1) / 2 + (max_places_count - 1) % 2);
	}

	if (right_places_count == 0)
		return getPlaces((left_places_count - 1) / 2, children_count - 1, (left_places_count - 1) / 2 + (left_places_count - 1) % 2);

	int max_places_count = max(left_places_count, right_places_count);
	return getPlaces(left_places_count + right_places_count - max_places_count, children_count - 1,
		(max_places_count - 1) / 2 + (max_places_count - 1) % 2);
}