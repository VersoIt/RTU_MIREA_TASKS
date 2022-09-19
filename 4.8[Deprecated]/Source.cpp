#include <iostream>

using namespace std;




int main()
{

	using namespace std;

	setlocale(LC_ALL, "Russian");

	float first_data[3][4] {
		{5.f, 2.f, 0.f, 10.f},
		{3.f, 5.f, 2.f, 5.f},
		{20.f, 0.f, 0.f, 0.f}
	};

	float second_data[4][2] {
		{1.20f, 0.5f},
		{2.8f, 0.4f},
		{5.0f, 1.0f},
		{2.0f, 1.5f}
	};



	/*for (int i{ 0 }; i < current.getRowsCount(); ++i)
	{
		for (int j{ 0 }; j < other.getColumnsCount(); ++j)
		{
			for (int k{ 0 }; k < current.getColumnsCount(); ++k)
				product.m_data[i][j] += current.m_data[i][k] * other.m_data[k][j];
		}
	}*/


	float product[3][2]{ 0.0f };
	// Умножение матриц
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 4; ++k)
				product[i][j] += first_data[i][k] * second_data[k][j];
		}
	}

	cout << "A * B = " << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << " | ";
		for (int j = 0; j < 2; ++j)
			cout << product[i][j] << " | ";

		cout << endl;
	}

	cout << "1) " << std::endl;
	{
		float max = product[0][0];
		float min = product[0][0];

		{
			int celler;

			for (int i = 0; i < 3; ++i)
			{
				if (max < product[i][0])
				{
					max = product[i][0];
					celler = i;
				}
			}
			cout << "Seller #" << celler + 1 << " made the most money from sales." << endl;
		}
		{
			int celler;

			for (int i = 0; i < 3; ++i)
			{
				if (min > product[i][0])
				{
					min = product[i][0];
					celler = i;
				}
			}

			cout << "Seller #" << celler + 1 << " made the least amount of money from the sale." << endl;
		}
	}

	cout << "2) " << endl;
	{
		float max = product[0][0];
		float min = product[0][0];

		{
			int celler = 0;

			for (int i = 0; i < 3; ++i)
			{
				if (max < product[i][0])
				{
					max = product[i][0];
					celler = i;
				}
			}
			cout << "Seller #" << celler + 1 << " made the most comission from sales." << endl;
		}
		{
			int celler;

			for (int i = 0; i < 3; ++i)
			{
				if (min > product[i][1])
				{
					min = product[i][1];
					celler = i;
				}
			}

			cout << "Seller #" << celler + 1 << " made the least amount of comission from the sale." << endl;
		}
	}


	cout << "3) " << endl;
	float sells_sum = 0;
	{
		for (int i = 0; i < 3; ++i)
		{
			sells_sum += product[i][0];
		}
		cout << "The total amount of money for goods sold is " << sells_sum << "." << endl;
	}

	cout << "4) " << std::endl;
	float comission_sum = 0;
	{
		for (int i = 0; i < 3; ++i)
		{
			comission_sum += product[i][1];
		}
		cout << "The total amount of comission for goods sold is " << comission_sum << "." << endl;
	}

	cout << "5) " << endl;
	cout << "The total amount of money that has passed through the hands of sellers is " << sells_sum + comission_sum << "." << std::endl;

	return EXIT_SUCCESS;
}