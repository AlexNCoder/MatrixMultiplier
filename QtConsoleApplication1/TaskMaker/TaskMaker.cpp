#include "TaskMaker.h"

TaskMaker::TaskMaker()
{
}

bool TaskMaker::makeTasks(Matrix matrA, Matrix matrB)
{
    if (!canMultiply(matrA, matrB))
    {
        return false;
    }
    m_matrC.reset(new Matrix(matrA.rowsCnt(), matrB.colsCnt()));

    if (!m_matrC->isValid())
    {
        return false;
    }

    auto rowsC = m_matrC->rowsCnt();
    auto colsC = m_matrC->colsCnt();

    for (int i = 0; i < rowsC; ++i)
    {
        for (int j = 0; j < colsC; ++j)
        {
            auto task = new Task(i, j, matrA.getRow(i), matrB.getCol(j), *m_matrC.get());
            /*connect(task, &Task::result,
                this, &TaskMaker::slotProcessResult,
                Qt::DirectConnection);*/
            addTask(task);
        }
    }
}

std::vector<Task*> TaskMaker::tasks()
{
    return m_tasks;
}

Matrix &TaskMaker::matrC()
{
    return *m_matrC;
}

void TaskMaker::slotProcessResult(double res)
{
    qDebug() << "Result:    " << res;
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