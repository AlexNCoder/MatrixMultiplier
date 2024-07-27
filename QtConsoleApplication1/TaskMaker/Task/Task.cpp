#include "Task.h"

Task::Task(
	int numRow, int numCol,
	std::vector<double> fromA,
	std::vector<double> fromB,
	QObject* parent)
	:QObject(parent)
{
}

void Task::run()
{
	static int cnt = 0;
	++cnt;
	qDebug() << "Hi from file cpp!" << cnt;
}
