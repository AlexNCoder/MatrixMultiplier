#include "TaskRunner.h"
#include "TaskMaker/TaskMaker.h"
#include <QThreadPool>
#include <iostream>
#include <fstream>

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

        QThread::msleep(5);
        qDebug() << "started:   " << started++;
    }

    threadPoolInstance->waitForDone();
    qDebug() << "Все задачи завершены";

    std::ofstream out;
    out.open("result.txt");
    if (out.is_open())
    {
        out << "A:\n";
        write2file(matrA, out);
        out << "B:\n";
        write2file(matrB, out);
        out << "C:\n";
        write2file(taskMaker.matrC(), out);
    }

    out.close();
}

void TaskRunner::write2file(Matrix& matr, std::ofstream& out)
{
    auto rowsCnt = matr.rowsCnt();
    auto colsCnt = matr.colsCnt();
    auto data = matr.getData();

    out << "[";

    for (int i = 0; i < rowsCnt; ++i)
    {
        for (int j = 0; j < colsCnt; ++j)
        {
            out << data[i * colsCnt + j] << " ";
        }
        out << "\n";
    }
    out << "]\n";
}
