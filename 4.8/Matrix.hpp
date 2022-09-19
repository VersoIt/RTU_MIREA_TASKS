#pragma once
#ifndef _MATRIX_
#define _MATRIX_

#include <iostream>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include <vector>


namespace Math
{

	class Matrix
	{
	public:
		Matrix(std::vector<std::vector<float>> data, const std::string& name) : m_data{ data }, m_name{ name }
		{
		}

		size_t getRowsCount() const;

		size_t getColumnsCount() const;

		const std::vector<std::vector<float>>& getMatrix() const;

		const std::string& getName() const;

		std::vector<float>& operator [](const int index);

		float getMaxValueInColumn(int column);

		float getMinValueInColumn(int column);

		float sumColumn(int column);

		std::tuple<int, int> getCoordOfMaxValueInColumn(int column);

		std::tuple<int, int> getCoordOfMinValueInColumn(int column);

		std::tuple<int, int> getCoordByValue(float value);

		friend Matrix operator*(const Matrix& current, const Matrix& other);

		friend std::ostream& operator <<(std::ostream& out, const Matrix& matrix);

	private:

		std::string m_name;
		std::vector<std::vector<float>> m_data;

		static void fillEmpty(Matrix& dispatch, int rows, int columns, int targetSymbol = 0);
	};

#endif
}