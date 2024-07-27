#include "TaskRunner.h"
#include "TaskMaker/TaskMaker.h"
#include <QThreadPool>

void TaskRunner::slotProcessResult()
{
    
}

void TaskRunner::runTasks()
{
    Matrix matrA(2, 3, { 1,1,1,1,1,1});
    Matrix matrB(3, 2, { 2,2,2,2,2,2 });

    TaskMaker taskMaker;
    if (!taskMaker.makeTasks(matrA, matrB))
    {
        qDebug() << "Неправильно заданы матрицы";

        return;
    }

    auto tasks = taskMaker.tasks();
    auto threadPoolInstance = QThreadPool::globalInstance();
    
    for (auto task : tasks)
    {
        static int started;
        //task->setAutoDelete(false);
        threadPoolInstance->start(task);
        qDebug() << "started:   " << started++;
    }

    threadPoolInstance->waitForDone();
    qDebug() << "Все задачи завершены";
    auto result = taskMaker.matrC().getData();

    for (auto v : result)
    {
        qDebug() << v;
    }
}