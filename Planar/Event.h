#pragma once

#include <QDateTime>

class Event
{
private:
	QDateTime dateTime;

public:
	Event();
	Event(QDate d);
	Event(QDateTime d);

	QDateTime getDateTime() const;
	QDate getDate() const;
	QTime getTime() const;
};
