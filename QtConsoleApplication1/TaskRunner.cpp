#include "TaskRunner.h"
#include "TaskMaker/TaskMaker.h"

void TaskRunner::slotProcessResult()
{
    
}

void TaskRunner::runTasks()
{
    Matrix matrA(3, 3, { 1,1,1,1,1,1,1,1,1 });
    Matrix matrB(3, 3, { 5,5,5,5,5,5,5,5,5 });

    TaskMaker taskMaker;
    if (!taskMaker.makeTasks(matrA, matrB))
    {
        qDebug() << "����������� ������ �������";

        return;
    }



    



    //QThreadPool::globalInstance()->start(task);
}