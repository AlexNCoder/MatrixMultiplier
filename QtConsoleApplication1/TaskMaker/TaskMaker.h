#pragma once
#include "Task/Task.h"
#include <memory>

class TaskMaker : public QObject
{
	Q_OBJECT

public:
	explicit TaskMaker();
	bool makeTasks(Matrix matrA, Matrix matrB);
	std::vector<Task*> tasks();
	Matrix &matrC();

private slots:
	void slotProcessResult(double res);

private:
	bool canMultiply(Matrix matrA, Matrix matrB);
	void addTask(Task *task);

	std::vector<Task*> m_tasks;
	std::shared_ptr<Matrix> m_matrC;// Потенциально опасно
};