#include <QtCore/QCoreApplication>
#include <QDebug>
#include "TaskRunner.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TaskRunner taskRunner;

    taskRunner.runTasks();

    return a.exec();
}
