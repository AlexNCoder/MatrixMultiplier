#pragma once
#include <vector>

class Matrix
{
	friend class Task;
public:
	explicit Matrix(int rows, int cols, std::vector<double> &&vals = {});
	bool isValid();
	int colsCnt();
	int rowsCnt();
	std::vector<double> getRow(int row);
	std::vector<double> getCol(int col);
	std::vector<double> &getData();

private:
	bool isValidShape();

	bool m_isValid = false;
	int m_cols = 0;
	int m_rows = 0;

	std::vector<double> m_vals;
};