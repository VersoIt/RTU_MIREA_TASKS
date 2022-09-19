#include<iomanip>
#include "Matrix.hpp"


namespace Math
{
	void Matrix::fillEmpty(Matrix& dispatch, int rows, int columns, int targetSymbol)
	{
		for (int i = 0; i < rows; ++i)
		{
			dispatch.m_data.push_back(std::vector<float>(0));
			for (int j = 0; j < columns; ++j)
			{
				dispatch.m_data[i].push_back(targetSymbol);
			}
		}
	}

	std::tuple<int, int> Matrix::getCoordOfMaxValueInColumn(int column)
	{
		return getCoordByValue(getMaxValueInColumn(column));
	}

	std::tuple<int, int> Matrix::getCoordOfMinValueInColumn(int column)
	{
		return getCoordByValue(getMinValueInColumn(column));
	}

	float Matrix::sumColumn(int column)
	{
		if (column > getColumnsCount() || column < 0)
			throw std::exception("Count of columns is incorrect");

		float sum{ 0 };

		for (int i{ 0 }; i < getRowsCount(); ++i)
			sum += m_data[i][column];

		return sum;
	}

	float Matrix::getMaxValueInColumn(int column)
	{
		float max{ 0 };

		for (int j{ 0 }; j < getRowsCount(); ++j)
			max = std::max(max, m_data[j][column]);

		return max;
	}


	float Matrix::getMinValueInColumn(int column)
	{
		float min{ m_data[0][0] };

		for (int j{ 0 }; j < getRowsCount(); ++j)
			min = std::min(min, m_data[j][column]);

		return min;
	}


	std::tuple<int, int> Matrix::getCoordByValue(float value)
	{
		for (int i{ 0 }; i < getRowsCount(); ++i)
		{
			for (int j{ 0 }; j < getColumnsCount(); ++j)
			{
				if (m_data[i][j] == value)
					return { i, j };
			}
		}

		return { -1, -1 };
	}


	const std::string& Matrix::getName() const
	{
		return m_name;
	}

	const std::vector<std::vector<float>>& Matrix::getMatrix() const
	{
		return m_data;
	}

	size_t Matrix::getRowsCount() const
	{
		return m_data.size();
	}

	size_t Matrix::getColumnsCount() const
	{
		return m_data[0].size();
	}

	Matrix operator*(const Matrix& current, const Matrix& other)
	{
		if (current.getColumnsCount() != other.getRowsCount())
			throw std::exception("Count of columns in first matrix don't equal of count of rows in second matrix.");

		Matrix product(std::vector<std::vector<float>>(0), current.getName() + " * " + other.getName());
		Matrix::fillEmpty(product, current.getRowsCount(), other.getColumnsCount());

		for (int i{ 0 }; i < current.getRowsCount(); ++i)
		{
			for (int j{ 0 }; j < other.getColumnsCount(); ++j)
			{
				for (int k{ 0 }; k < current.getColumnsCount(); ++k)
					product.m_data[i][j] += current.m_data[i][k] * other.m_data[k][j];
			}
		}

		return product;
	}

	std::vector<float>& Matrix::operator [](const int index)
	{
		return m_data[index];
	}

	std::ostream& operator <<(std::ostream& out, const Matrix& matrix)
	{
		out.fill(' ');
		out << std::setw(8) << matrix.getName() << " = " << std::endl;

		for (int i{ 0 }; i < matrix.getRowsCount(); ++i)
		{
			out << "| ";
			for (int j{ 0 }; j < matrix.getColumnsCount(); ++j)
			{
				out << std::setw(4) << matrix.getMatrix()[i][j] << " | ";
			}
			out << std::endl;
		}

		return out;
	}
}