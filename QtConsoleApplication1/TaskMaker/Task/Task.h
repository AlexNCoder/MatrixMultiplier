#pragma once
#include <QDebug>
#include <QThreadPool>
#include <memory>
class Task;
typedef std::shared_ptr<Task> TaskP;
class Task : public QObject, public QRunnable
{
	Q_OBJECT

public:
	explicit Task(
		int numRow, int numCol,
		std::vector<double> fromA, std::vector<double> fromB,
		QObject* parent = nullptr);
	void run() override;

signals:
	void result(Task*);

protected:
	int m_numRow = 0;
	int m_numCol = 0;
};

