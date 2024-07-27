#pragma once
#include <vector>

class Matrix
{
public:
	explicit Matrix(int rows, int cols, std::vector<double> &&vals = {});
	bool isValid();
	int colsCnt();
	int rowsCnt();
	std::vector<double> getRow(int row);
	std::vector<double> getCol(int col);

private:
	bool isValidShape();

	bool m_isValid = false;
	int m_cols = 0;
	int m_rows = 0;

	std::vector<double> m_vals;
};