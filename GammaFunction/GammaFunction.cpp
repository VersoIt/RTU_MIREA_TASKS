#include <iostream>

using namespace std;

long gammaFunction(int N) {

    long result = 1;

    for (int i = 0; i < N - 1; ++i)
        result *= (i + 1);

    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int N;

    cout << "Введите N: " << endl;
    cin >> N;

    cout << "Гамма функция от " << N << " равна " << gammaFunction(N) << "." << endl;
}