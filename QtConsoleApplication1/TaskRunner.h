#pragma once
#include <QObject>
#include "Matrix/Matrix.h"

class TaskRunner : public QObject
{
	Q_OBJECT

public:
	void runTasks();

	void write2file(Matrix& matrA, std::ofstream& out);

public slots:
	void slotProcessResult();
};