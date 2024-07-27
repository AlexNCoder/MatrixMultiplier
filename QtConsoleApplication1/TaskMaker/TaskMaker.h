#pragma once
#include "Task/Task.h"
#include "../Matrix/Matrix.h"

class TaskMaker
{
public:
	bool makeTasks(Matrix matrA, Matrix matrB);
	
private:
	bool canMultiply(Matrix matrA, Matrix matrB);
	void addTask(TaskP task);

	std::vector<TaskP> m_tasks;
};