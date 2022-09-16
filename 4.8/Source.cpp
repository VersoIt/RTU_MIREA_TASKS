#include <iostream>
#include <array>
#include <vector>


class Matrix
{
public:
	Matrix(std::vector<std::vector<float>>& data) : m_data{ data }
	{
	}

	size_t getRowsCount() const;

	size_t getColumnsCount() const;

	friend float operator*(const Matrix& current, const Matrix& other);

	const std::vector<std::vector<float>>& getMatrix() const
	{
		return m_data;
	}

private:
	std::vector<std::vector<float>>& m_data;
};

size_t Matrix::getRowsCount() const
{
	return m_data.size();
}

size_t Matrix::getColumnsCount() const
{
	return m_data[0].size();
}

float operator*(const Matrix& current, const Matrix& other)
{
	if (current.getColumnsCount() != other.getRowsCount())
		throw std::exception("Count of columns in first matrix don't equal of count of rows in second matrix.");

	float sum{ 0 };

	for (int k { 0 }; k < other.getColumnsCount(); ++k)
	{
		for (int i { 0 }; i < current.getRowsCount(); ++i)
		{
			for (int j { 0 }; j < current.getColumnsCount(); ++j)
			{
				sum += current.m_data[i][j] * other.m_data[j + k][i];
			}
		}
	}

	return sum;
}

int main()
{

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
	
	Matrix A(first_data);
	Matrix B(second_data);

	try
	{
		std::cout << A * B << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}