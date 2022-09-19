#include <iostream>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "*** Анализ роста учеников ***\nВведите рост (см) и нажмите <Enter>.\nДля завершения введите 0 и нажмите <Enter>" << endl;

	int students_count{ 0 };
	float sum{ 0 };
	float weight;

	vector<int> students_weights;

	do
	{
		++students_count;
		cout << " -> ";
		cin >> weight;
		sum += weight;
		students_weights.push_back(weight);
	} while(weight != 0);

	--students_count;
	double average_sum = sum / students_count;

	vector<int> more_than_average;
	for (int i = 0; i < students_weights.size(); ++i)
	{
		if (students_weights[i] > average_sum)
			more_than_average.push_back(students_weights[i]);
	}

	cout << "Средний рост: " << sum / students_count << " см" << endl;

	if (more_than_average.size() != 0)
		cout << "У " << more_than_average.size() << " человек рост больше среднего." << endl;

	return EXIT_SUCCESS;
}