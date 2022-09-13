#include <iostream>
#include <array>
#include <vector>


class Matrix
{
public:
	Matrix(std::vector<std::vector<float>>& data) : m_data{ data }
	{
	}

	size_t getRows() const
	{
		return m_data.size();
	}

	size_t getColumns() const
	{
		return m_data[0].size();
	}

	friend float operator*(Matrix other)
	{
		float sum;
		for (int i = 0; i < other.getRows(); ++i)
		{
			for (int j = 0; j < other.getColumns(); ++j)
			{
				// TODO: sum += m_data[i][j] * other.getMatrix()[j][i];
			}
		}
	}

	std::vector<std::vector<float>>& getMatrix() const
	{
		return m_data;
	}

private:
	std::vector<std::vector<float>>& m_data;
};

int main()
{

	std::vector<std::vector<float>> first_data{ {
		{5, 2, 0, 10},
		{3, 5, 2, 5},
		{20, 0, 0, 0} 
	} };

	std::vector<std::vector<float>> second_data{ {
		{1.20f, 0.5f},
		{2.8f, 0.4f},
		{5.0f, 1.0f},
		{2.0f, 1.5f}
	} };
	
	Matrix A(first_data);
	Matrix B(second_data);

	int a;
	std::cin >> a;
	if (std::cin.fail())
		std::cout << "Îøèáêà" << std::endl;
	std::cout << a << std::endl;


	return EXIT_SUCCESS;
}