#include <iostream>
#include <array>
#include "Matrix.hpp"
#include "ActionTypes.hpp"



int main()
{
	using namespace std;
	using namespace Math;

	setlocale(LC_ALL, "Russian");

	std::vector<std::vector<float>> first_data{ {
		{5.f, 2.f, 0.f, 10.f},
		{3.f, 5.f, 2.f, 5.f},
		{20.f, 0.f, 0.f, 0.f}
	} };

	std::vector<std::vector<float>> second_data{ {
		{1.20f, 0.5f},
		{2.8f, 0.4f},
		{5.0f, 1.0f},
		{2.0f, 1.5f}
	} };
	
	Matrix A(first_data, "A");
	Matrix B(second_data, "B");

	try
	{
		Matrix product = A * B;
		cout << product << endl;
		
		cout << "1) " << std::endl;
		{
			auto [celler, _] = product.getCoordOfMaxValueInColumn(ActionTypes::SALES_AMOUNT);
			cout << "�������� #" << celler + 1 << " ������� ������ ����� ����� � �������." << endl;

			auto [taxer, __] = product.getCoordOfMinValueInColumn(ActionTypes::SALES_AMOUNT);
			cout << "�������� #" << taxer + 1 << " ������� ������ ����� ����� � �������." << endl;
		}

		cout << "2) " << std::endl;
		{
			auto [celler, _] = product.getCoordOfMaxValueInColumn(ActionTypes::TAXES_AMOUNT);
			std::cout << "�������� #" << celler + 1 << " ������� ���������� ������������." << endl;

			auto [taxer, __] = product.getCoordOfMinValueInColumn(ActionTypes::TAXES_AMOUNT);
			cout << "�������� #" << taxer + 1<< " ������� ���������� ������������." << endl;
		}

		cout << "3) " << std::endl;
		cout << "����� ����� ����� �� ��������� ������ ���������� " << product.sumColumn(ActionTypes::SALES_AMOUNT) << endl;

		cout << "4) " << std::endl;
		cout << "����� �������� �������� " << product.sumColumn(ActionTypes::TAXES_AMOUNT) << " ������������" << endl;

		cout << "5) " << std::endl;
		std::cout << "����� ����� �����, ��������� ����� ���� ��������� ���������� " << product.sumColumn(ActionTypes::SALES_AMOUNT) + product.sumColumn(ActionTypes::TAXES_AMOUNT) << std::endl;

		

	}
	catch (std::exception exc)
	{
		cout << exc.what() << endl;
	}

	return EXIT_SUCCESS;
}