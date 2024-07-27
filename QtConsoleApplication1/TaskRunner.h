#pragma once
#include <QObject>

class TaskRunner : public QObject
{
	Q_OBJECT

public:
	void runTasks();

public slots:
	void slotProcessResult();
};