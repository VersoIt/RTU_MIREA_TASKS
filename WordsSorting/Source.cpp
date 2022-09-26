#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
bool compare(const T& first, T& second)
{
	const size_t size = first.size() > second.size() ? second.size() : first.size();

	for (size_t i{ 0 }; i < size; ++i)
	{
		if (first[i] < second[i])
			return true;
	}

	return false;
}

void sort_words(std::vector<string>& words)
{
	for (size_t i{ 0 }; i < words.size(); ++i)
	{
		for (size_t j{ i }; j < words.size() - 1; ++j)
		{
			if (compare(words[j + 1], words[i]))
				std::swap(words[j + 1], words[i]);
		}
	}
}

int main(int argc, char* argv[])
{
	vector<string> some_words{ "abc", "cba", "aaa", "cav" };

	sort_words(some_words);
	for_each(some_words.begin(), some_words.end(), [](const auto e) { cout << e << endl; });

	return EXIT_SUCCESS;
}