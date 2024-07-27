#include "TaskMaker.h"

bool TaskMaker::makeTasks(Matrix matrA, Matrix matrB)
{
    if (!canMultiply(matrA, matrB))
    {
        return false;
    }
    Matrix matrC(matrA.colsCnt(), matrB.rowsCnt());

    if (!matrC.isValid())
    {
        return false;
    }

    auto rowsC = matrC.rowsCnt();
    auto colsC = matrC.colsCnt();

    for (int i = 0; i < rowsC; ++i)
    {
        for (int j = 0; j < colsC; ++j)
        {
            auto task = new Task(i, j, matrA.getRow(i), matrA.getCol(j));
            connect(task, &Task::result,
                this, &TaskMaker::slotProcessResult,
                Qt::DirectConnection);
            addTask(task);
        }
    }
}

std::vector<Task*> TaskMaker::tasks()
{
    return m_tasks;
}

void TaskMaker::slotProcessResult(Task *task)
{
    qDebug() << "Result";
}

void TaskMaker::addTask(Task *task)
{
	m_tasks.push_back(task);
}

bool TaskMaker::canMultiply(Matrix matrA, Matrix matrB)
{
    if (matrA.isValid() && matrB.isValid()
        && (matrA.colsCnt() == matrB.rowsCnt()))
    {
        return true;
    }

    return false;
}