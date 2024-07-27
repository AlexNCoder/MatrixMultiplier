#include "Task.h"

Task::Task(
	int rowCid, int colCid,
	std::vector<double> fromA,
	std::vector<double> fromB,
	Matrix &matrC,
	QObject* parent)
	:QObject(parent),
	m_fromA(fromA),
	m_fromB(fromB),
	m_RowCid(rowCid),
	m_ColCid(colCid),
	m_matrC(matrC)
{
}

void Task::run()
{
	double sum = 0;

	for (int i = 0; i < m_fromA.size(); ++i)
	{
		sum += m_fromA.at(i) * m_fromB.at(i);
	}
	
	m_matrC.m_vals[m_RowCid * m_matrC.colsCnt() + m_ColCid] = sum;
	//emit result(sum);
}
