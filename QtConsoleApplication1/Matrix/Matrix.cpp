#include "Matrix.h"

Matrix::Matrix(int rows, int cols, std::vector<double> &&vals)
{
	m_rows = rows;
	m_cols = cols;

	if (!isValidShape())
	{
		return;
	}

	if (vals.empty())
	{
		m_vals.resize(m_rows * m_cols, 0);

		return;
	}
	if (m_rows * m_cols == vals.size())
	{
		m_vals = vals;
	}
}

bool Matrix::isValid()
{
	if (isValidShape()
		&& (m_vals.size() == m_cols * m_rows))
	{
		return true;
	}

	return false;
}

int Matrix::colsCnt()
{
	return m_cols;
}

int Matrix::rowsCnt()
{
	return m_rows;
}

std::vector<double> Matrix::getRow(int row)
{
	if (isValid())
	{
		std::vector<double> res;
		auto bias = row * m_cols;

		for (int j = 0; j < m_cols; ++j)
		{
			res.push_back(m_vals[bias + j]);
		}

		return res;
	}

	return std::vector<double>();
}

std::vector<double> Matrix::getCol(int col)
{
	if (isValid())
	{
		std::vector<double> res;

		for (int i = 0; i < m_rows; ++i)
		{
			res.push_back(m_vals[i * m_cols + col]);
		}

		return res;
	}

	return std::vector<double>();
}

std::vector<double>& Matrix::getData()
{
	// TODO: вставьте здесь оператор return
	return m_vals;
}

bool Matrix::isValidShape()
{
	return m_rows > 0 && m_cols > 0;
}
