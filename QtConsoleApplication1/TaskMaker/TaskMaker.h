#pragma once
#include "Task/Task.h"
#include "../Matrix/Matrix.h"

class TaskMaker : public QObject
{
	Q_OBJECT

public:
	bool makeTasks(Matrix matrA, Matrix matrB);
	std::vector<Task*> tasks();

private slots:
	void slotProcessResult(Task *task);

private:
	bool canMultiply(Matrix matrA, Matrix matrB);
	void addTask(Task *task);

	std::vector<Task*> m_tasks;
};