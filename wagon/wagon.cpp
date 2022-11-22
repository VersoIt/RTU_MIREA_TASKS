#include <iostream>

using namespace std;

int getSection(int target)
{
    if (target <= 36)
        return (target - 1) / 4;
    else
    {
        return 8 - (target - 37) / 2;
    }
}


int main()
{
    int seats_in_wagons[9]{ 0 };

    int N;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int seat_number;
        cin >> seat_number;

        ++seats_in_wagons[getSection(seat_number)];
    }

    int count = 0;
    int max = 0;

    for (int i = 0; i < N; ++i)
    {
        if (seats_in_wagons[i] == 6)
        {
            ++count;
            max = std::max(count, max);
        }
        else
            count = 0;
    }

    cout << max << endl;

    return EXIT_SUCCESS;
}