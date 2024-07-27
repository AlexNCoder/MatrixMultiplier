#pragma once
#include <QDebug>
#include <QRunnaBle>
//#include <memory>
#include "../../Matrix/Matrix.h"

class Task;
//typedef std::shared_ptr<Task> TaskP;
class Task : public QObject, public QRunnable
{
	Q_OBJECT

public:
	explicit Task(
		int numRowC, int numColC,
		std::vector<double> fromA, std::vector<double> fromB,
		Matrix &matrC,
		QObject* parent = nullptr);
	void run() override;

signals:
	void result(double);

protected:
	int m_RowCid = 0;
	int m_ColCid = 0;

	std::vector<double> m_fromA;
	std::vector<double> m_fromB;

	Matrix &m_matrC;
};

