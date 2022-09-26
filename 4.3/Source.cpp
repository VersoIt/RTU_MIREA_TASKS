#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

using namespace std;

double Name;
double a, b, c, p, r;

double getRectangleArea(float width, float height)
{
	if (width <= 0 || height <= 0)
		throw exception("Прямоугольника с такими сторонами не существует!");

	return width * height;
}

double getTriangleArea(float a, float b, float c)
{
	float p = (a + b + c) / 2;

	if ((((a + b) <= c) or ((a + c) <= b) or ((b + c) <= a)) || a <= 0 || b <= 0 || c <= 0)
		throw exception("Треугольника с такими сторонами не существует!");

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double getRoundArea(float r)
{
	if (r <= 0)
		throw exception("Окружности с таким радиусом не существует!");

	return M_PI * pow(r, 2);
}


enum FigureTypes
{
	Rectangle = 0b0001,
	Triangle = 0b0010,
	Round = 0b0011
};


// Геометрические фигуры
int main()
{
	setlocale(LC_ALL, "Russian");
	int figure_id;

	try
	{
		bool is_passed = true;
		do
		{
			cout << "Введите название фигуры:" << endl;
			cout << "1 - Прямоугольник;" << endl << "2 - Треугольник;" << endl << "3 - Окружность;" << endl;

			cin >> figure_id;
			switch (figure_id)
			{
			case FigureTypes::Round:
				float radius;

				cout << "Вы выбрали окружность\nВведите её данные: [радиус]: ";
				cin >> radius;
				cout << "Площадь окружности равна " << getRoundArea(radius) << endl;

				is_passed = true;

				break;
			case FigureTypes::Rectangle:
				float width;
				float height;

				cout << "Вы выбрали прямоугольник\nВведите его данные через пробел: [ширина] [высота]: ";
				cin >> width >> height;
				cout << "Площадь прямоугольника равна " << getRectangleArea(width, height) << endl;

				is_passed = true;

				break;
			case FigureTypes::Triangle:

				cout << "Вы выбрали трегольник\nВведите его данные через пробел: [a] [b] [c]: ";
				float a, b, c;

				cin >> a >> b >> c;
				cout << "Площадь треугольника равна " << getTriangleArea(a, b, c) << endl;

				is_passed = true;
				break;
			default:
				cout << "Такой фигуры не существует!\nВведите данные повторно." << endl;
				is_passed = false;
				break;
			}
		} while (!is_passed);
	}
	catch (exception exc)
	{
		cout << exc.what() << endl;
	}
	
	return EXIT_SUCCESS;
}