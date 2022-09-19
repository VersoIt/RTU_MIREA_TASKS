#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

using namespace std;

double Name;
double a, b, c, p, r;

double getRectangleArea(float width, float height)
{
	return width * height;
}

double getTriangleArea(float a, float b, float c)
{
	float p = (a + b + c) / 2;

	if ((((a + b) <= c) or ((a + c) <= b) or ((b + c) <= a)) || a <= 0 || b <= 0 || c <= 0)
		throw exception("������������ � ������ ��������� �� ����������!");

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double getRoundArea(float r)
{
	return M_PI * pow(r, 2);
}


enum FigureTypes
{
	Rectangle = 0b0001,
	Triangle = 0b0010,
	Round = 0b0011
};


// �������������� ������
int main()
{
	setlocale(LC_ALL, "Russian");
	int figure_id;

	cout << "������� �������� ������:" << endl;
	cout << "1 - �������������;" << endl << "2 - �����������;" << endl << "3 - ����;" << endl;

	cin >> figure_id;

	try
	{
		switch (static_cast<FigureTypes>(figure_id))
		{
		case FigureTypes::Round:
			float radius;
			std::cout << "�� ������� ����\n������� ��� ������: [������]: ";
			std::cin >> radius;
			std::cout << "������� ����� ����� " << getRoundArea(radius) << std::endl;
			break;
		case FigureTypes::Rectangle:
			float width;
			float height;

			std::cout << "�� ������� �������������\n������� ��� ������ ����� ������: [������] [������]: ";
			std::cin >> width >> height;
			std::cout << "������� �������������� ����� " << getRectangleArea(width, height) << std::endl;

			break;
		case FigureTypes::Triangle:

			std::cout << "�� ������� ����������\n������� ��� ������ ����� ������: [a] [b] [c]: ";
			float a, b, c;
			std::cin >> a >> b >> c;
			std::cout << "������� ������������ ����� " << getTriangleArea(a, b, c) << std::endl;
			break;
		default:
			std::cout << "����� ������ �� ����������!" << std::endl;
		}
	}
	catch (exception exc)
	{
		std::cout << exc.what() << std::endl;
	}
	
	return EXIT_SUCCESS;
}