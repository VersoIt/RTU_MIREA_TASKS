#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

using namespace std;

double Name;
double a, b, c, p, r;

double getRectangleArea(float width, float height)
{
	if (width <= 0 || height <= 0)
		throw exception("�������������� � ������ ��������� �� ����������!");

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
	if (r <= 0)
		throw exception("���������� � ����� �������� �� ����������!");

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

	try
	{
		bool is_passed = true;
		do
		{
			cout << "������� �������� ������:" << endl;
			cout << "1 - �������������;" << endl << "2 - �����������;" << endl << "3 - ����������;" << endl;

			cin >> figure_id;
			switch (figure_id)
			{
			case FigureTypes::Round:
				float radius;

				cout << "�� ������� ����������\n������� � ������: [������]: ";
				cin >> radius;
				cout << "������� ���������� ����� " << getRoundArea(radius) << endl;

				is_passed = true;

				break;
			case FigureTypes::Rectangle:
				float width;
				float height;

				cout << "�� ������� �������������\n������� ��� ������ ����� ������: [������] [������]: ";
				cin >> width >> height;
				cout << "������� �������������� ����� " << getRectangleArea(width, height) << endl;

				is_passed = true;

				break;
			case FigureTypes::Triangle:

				cout << "�� ������� ����������\n������� ��� ������ ����� ������: [a] [b] [c]: ";
				float a, b, c;

				cin >> a >> b >> c;
				cout << "������� ������������ ����� " << getTriangleArea(a, b, c) << endl;

				is_passed = true;
				break;
			default:
				cout << "����� ������ �� ����������!\n������� ������ ��������." << endl;
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